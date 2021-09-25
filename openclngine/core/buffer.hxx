#include "core/buffer.hpp"

#include "exception/helper.hpp"

#include <assert.h>

namespace core
{

template< typename T >
Buffer< T >::Buffer(const cl_context _context, const CommandQueue& _commandQueue, BUFFER_FLAG _flag, const std::vector< T >& _buffer) :
    m_commandQueue(_commandQueue)
{
    m_size = _buffer.size();
    cl_int err;
    m_deviceBuffer = clCreateBuffer(_context, _flag,  m_size*sizeof(T), nullptr, &err);
    ::exception::checkCLError(err);
    err = clEnqueueWriteBuffer(m_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, m_size*sizeof(T), &_buffer[0], 0, nullptr, nullptr);
    ::exception::checkCLError(err);
}

template< typename T >
Buffer< T >::Buffer(const cl_context _context, const CommandQueue& _commandQueue, BUFFER_FLAG _flag, size_t _size) :
    m_commandQueue(_commandQueue)
{
    cl_int err;
    m_deviceBuffer = clCreateBuffer(_context, _flag,  _size*sizeof(T), nullptr, &err);
    ::exception::checkCLError(err);
    m_size = _size;
}

template< typename T >
Buffer< T >::~Buffer()
{
    cl_int err = clReleaseMemObject(m_deviceBuffer);
    ::exception::checkCLError(err);
}

template< typename T >
const std::vector< T >& Buffer< T >::read()
{
    m_hostBuffer.resize(m_size);
    cl_int err = clEnqueueReadBuffer(m_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, m_size*sizeof(T), &m_hostBuffer[0], 0, nullptr, nullptr);
    ::exception::checkCLError(err);
    return m_hostBuffer;
}

template< typename T >
void Buffer< T >::write(const std::vector< T >& _buffer) const
{
    cl_int err = clEnqueueWriteBuffer(m_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, m_size*sizeof(T), &_buffer[0], 0, nullptr, nullptr);
    ::exception::checkCLError(err);
}

}
