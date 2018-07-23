#pragma once

#include "core/buffer.hpp"
#include "core/commandQueue.hpp"
#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

class Context
{

    friend class Device;

public:

    ~Context();

    CommandQueue createCommandQueue() const;

    Program createProgram(const std::string&) const;

    template< typename T >
    Buffer< T > createBuffer(const CommandQueue&, BUFFER_FLAG, const std::vector< T >&) const;

    template< typename T >
    Buffer< T > createBuffer(const CommandQueue&, BUFFER_FLAG, size_t) const;

private:

    Context(const cl_device_id);

private:

    cl_context m_context {nullptr};

    const cl_device_id m_device;

};

}
