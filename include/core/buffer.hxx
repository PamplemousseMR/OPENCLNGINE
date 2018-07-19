#include "core/buffer.hpp"

#include "exception/helper.hpp"

#include <assert.h>

namespace core
{

template< typename T >
Buffer< T >::Buffer(const Context& _context, const CommandQueue& _commandQueue, BUFFER_FLAG _flag, const T* _buffer, size_t _size)
{
    assert(_buffer != nullptr);
    cl_int err;
    m_deviceBuffer = clCreateBuffer(_context.getContext(), _flag,  _size*sizeof(T), nullptr, &err);
    ::exception::checkCLError(err);
    err = clEnqueueWriteBuffer(_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, _size*sizeof(T), _buffer, 0, nullptr, nullptr);
    ::exception::checkCLError(err);
    m_size = _size;
}

template< typename T >
Buffer< T >::Buffer(const Context& _context, BUFFER_FLAG _flag, size_t _size)
{
    cl_int err;
    m_deviceBuffer = clCreateBuffer(_context.getContext(), _flag,  _size*sizeof(T), nullptr, &err);
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
const std::vector< T >& Buffer<T>::read(const CommandQueue& _commandQueue) const
{
    m_hostBuffer.resize(_size);
    cl_int err = clEnqueueReadBuffer(_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, _size*sizeof(T), &m_hostBuffer[0], 0, nullptr, nullptr);
    ::exception::checkCLError(err);
    return m_hostBuffer;
}

template< typename T >
void Buffer< T >::write(const CommandQueue& _commandQueue, const T* _buffer) const
{
    assert(_buffer != nullptr);
    cl_int err = clEnqueueWriteBuffer(_commandQueue.getCommandQueue(), m_deviceBuffer, CL_TRUE, 0, m_size*sizeof(T), _buffer, 0, nullptr, nullptr);
    ::exception::checkCLError(err);
}

}
