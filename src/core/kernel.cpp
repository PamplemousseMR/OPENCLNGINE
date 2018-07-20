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

void Kernel::enqueueNDRange(const CommandQueue& _commandQueue, size_t _global, size_t _local) const
{
    cl_int err = clEnqueueNDRangeKernel(_commandQueue.m_commandQueue, m_kernel, 1, nullptr, &_global, &_local, 0, nullptr, nullptr);
    ::exception::checkCLError(err);
}

void Kernel::finish(const CommandQueue& _commandQueue) const
{
    cl_int err = clFinish(_commandQueue.m_commandQueue);
    ::exception::checkCLError(err);
}

}
