#pragma once

#include "core/kernel.hpp"

#include "exception/helper.hpp"

#include <CL/cl.h>

namespace core
{

template< typename... A >
void Kernel::enqueueNDRange(const CommandQueue& _commandQueue, size_t _global, size_t _local, const A&... _args)
{
    setArgs(0, _args...);
    m_commandQueue = _commandQueue.getCommandQueue();
    cl_int err = clEnqueueNDRangeKernel(_commandQueue.m_commandQueue, m_kernel, 1, nullptr, &_global, &_local, 0, nullptr, nullptr);
    ::exception::checkCLError(err);
}

template< typename T, typename... A>
void Kernel::setArgs(uint32_t _location, const T& _first, const A&... _args) const
{
    setArg(_first, _location);
    setArgs(++_location, _args...);
}

void Kernel::setArgs(uint32_t) const
{
}

template< typename T >
void Kernel::setArg(const T& _buffer, uint32_t _location) const
{
    cl_int err = clSetKernelArg(m_kernel, _location, sizeof(T), (void*)&_buffer);
    ::exception::checkCLError(err);
}

template< typename T >
void Kernel::setArg(const Buffer< T >& _buffer, uint32_t _location) const
{
    cl_int err = clSetKernelArg(m_kernel, _location, sizeof(cl_mem), (void*)&_buffer.m_deviceBuffer);
    ::exception::checkCLError(err);
}

}
