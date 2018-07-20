#pragma once

#include "core/commandQueue.hpp"

#include <CL/cl.h>

#include <vector>

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

    friend class Kernel;

    friend class Context;

public:

    ~Buffer();

    const std::vector< T >& read(const CommandQueue&);

    void write(const CommandQueue&, const std::vector< T >&) const;

private:

    Buffer(const cl_context, const CommandQueue&, BUFFER_FLAG, const std::vector< T >&);

    Buffer(const cl_context, BUFFER_FLAG, size_t);

private:

    cl_mem m_deviceBuffer {nullptr};

    std::vector< T > m_hostBuffer {};

    size_t m_size {0};

};

}
