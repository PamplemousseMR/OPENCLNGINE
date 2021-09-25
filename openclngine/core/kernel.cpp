#include "core/kernel.hpp"

#include "exception/helper.hpp"

namespace core
{

Kernel::Kernel(const cl_program _program, const std::string& _name)
{
    cl_int err;
    m_kernel = clCreateKernel(_program, _name.c_str(), &err);
    ::exception::checkCLError(err);
}

Kernel::~Kernel()
{
    cl_int err = clReleaseKernel(m_kernel);
    ::exception::checkCLError(err);
}

void Kernel::finish()
{
    cl_int err = clFinish(m_commandQueue);
    ::exception::checkCLError(err);
    m_commandQueue = nullptr;
}

}
