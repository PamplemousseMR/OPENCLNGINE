#pragma once

#include "core/commandQueue.hpp"
#include "core/context.hpp"

#include <CL/cl.h>

namespace core
{

enum BUFFER_FLAG
{
    READ = CL_MEM_READ_ONLY,
    WRITE = CL_MEM_WRITE_ONLY,
    READ_WRITE = CL_MEM_READ_WRITE
};

template< typename T >
class Buffer
{

public:

    Buffer(const Context&, const CommandQueue&, BUFFER_FLAG, const T*, size_t);

    Buffer(const Context&, BUFFER_FLAG, size_t);

    ~Buffer();

    const std::vector< T >& read(const CommandQueue&) const;

    void write(const CommandQueue&, const T*) const;

private:

    cl_mem m_deviceBuffer {nullptr};

    std::vector< T > m_hostBuffer {};

    size_t m_size {0};

};

}
