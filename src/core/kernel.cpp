#include "core/kernel.hpp"

#include "exception/helper.hpp"

namespace core
{

Kernel::Kernel(const Program& _program, const std::string& _name)
{
    cl_int err;
    m_kernel = clCreateKernel(_program.m_program, _name.c_str(), &err);
    ::exception::checkCLError(err);
}

Kernel::~Kernel()
{
    cl_int err = clReleaseKernel(m_kernel);
    ::exception::checkCLError(err);
}

}
