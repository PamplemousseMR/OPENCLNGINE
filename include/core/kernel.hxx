#pragma once

#include "core/kernel.hpp"

#include "exception/helper.hpp"

#include <CL/cl.h>

namespace core
{

template< typename T >
void Kernel::setArg(T _buffer, uint32_t _location) const
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
