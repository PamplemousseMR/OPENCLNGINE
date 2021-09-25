#include "core/buffer.hpp"

namespace core
{

template< typename T >
Buffer< T > Context::createBuffer(const CommandQueue& _commandQueue, BUFFER_FLAG _flag, const std::vector< T >& _buffer) const
{
    return Buffer< T >(m_context, _commandQueue, _flag, _buffer);
}

template< typename T >
Buffer< T > Context::createBuffer(const CommandQueue& _commandQueue, BUFFER_FLAG _flag, size_t _size) const
{
    return Buffer< T >(m_context, _commandQueue, _flag, _size);
}

}
