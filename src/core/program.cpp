#include "core/program.hpp"

#include "exception/failure.hpp"
#include "exception/helper.hpp"

#include <CL/cl.h>

#include <assert.h>
#include <sstream>

namespace core
{

template< typename T >
T Program::getInfo(const cl_program _program, const cl_program_info _name)
{
    assert(_program != nullptr);
    T info;
    {
        cl_int err = clGetProgramInfo(_program, _name, sizeof(T), &info, nullptr);
        ::exception::checkCLError(err);
    }
    return info;
}

template<>
std::string Program::getInfo< std::string >(const cl_program _program, const cl_program_info _name)
{
    assert(_program != nullptr);
    size_t infoSize;
    {
        cl_int err = clGetProgramInfo(_program, _name, 0, nullptr, &infoSize);
        ::exception::checkCLError(err);
    }
    std::string info;
    info.resize(infoSize);
    {
        cl_int err = clGetProgramInfo(_program, _name, infoSize, &info[0], nullptr);
        ::exception::checkCLError(err);
    }
    return info;
}

Program::Program(const Context& _context, const std::string& _source) :
    m_sources(_source)
{
    const char* sources = m_sources.c_str();
    const size_t length = m_sources.length();
    cl_int err;
    m_program = clCreateProgramWithSource(_context.m_context, 1, &sources, &length, &err);
    ::exception::checkCLError(err);
}

Program::~Program()
{
    cl_int err = clReleaseProgram(m_program);
    ::exception::checkCLError(err);
}

void Program::build(const Device& _device) const
{
    cl_int err = clBuildProgram(m_program, 1, &_device.m_device, nullptr, nullptr, nullptr);
    if(err == CL_BUILD_PROGRAM_FAILURE)
    {
        size_t infoSize;
        {
            cl_int err = clGetProgramBuildInfo(m_program, _device.m_device, CL_PROGRAM_BUILD_LOG, 0, nullptr, &infoSize);
            ::exception::checkCLError(err);
        }
        std::string info;
        info.resize(infoSize);
        {
            cl_int err = clGetProgramBuildInfo(m_program, _device.m_device, CL_PROGRAM_BUILD_LOG, infoSize, &info[0], nullptr);
            ::exception::checkCLError(err);
        }
        throw ::exception::Failure(info);
    }
    ::exception::checkCLError(err);

    cl_build_status buildStatus;
    do
    {
        err = clGetProgramBuildInfo(m_program, _device.m_device, CL_PROGRAM_BUILD_STATUS, sizeof(buildStatus), &buildStatus, nullptr);
        ::exception::checkCLError(err);
        if(buildStatus != CL_BUILD_SUCCESS && buildStatus != CL_BUILD_IN_PROGRESS)
        {
            switch(buildStatus)
            {
                case CL_BUILD_NONE :
                    throw ::exception::Failure("No build");
                break;
                case CL_BUILD_ERROR :
                    throw ::exception::Failure("Build error");
                break;
            }
        }
    }
    while(buildStatus == CL_BUILD_IN_PROGRESS);
}

size_t Program::getNumKernel() const
{
    return Program::getInfo< size_t >(m_program, CL_PROGRAM_NUM_KERNELS);
}

std::vector<std::string> Program::getKernelNames() const
{
    std::string names = Program::getInfo< std::string >(m_program, CL_PROGRAM_KERNEL_NAMES);

    std::vector< std::string > res;
    std::istringstream ss(names);
    std::string token;
    while(std::getline(ss, token, ';'))
    {
        res.push_back(token);
    }
    return res;
}

}
