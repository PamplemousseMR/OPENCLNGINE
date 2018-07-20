#pragma once

#include "core/buffer.hpp"
#include "core/commandQueue.hpp"
#include "core/device.hpp"
#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

class Context
{

public:

    Context(const Device&);

    ~Context();

    CommandQueue createCommandQueue() const;

    Program createProgram(const std::string&) const;

    template< typename T >
    Buffer< T > createBuffer(const CommandQueue&, BUFFER_FLAG, const std::vector< T >&) const;

    template< typename T >
    Buffer< T > createBuffer(const CommandQueue&, BUFFER_FLAG, size_t) const;

private:

    cl_context m_context {nullptr};

    const Device& m_device;

};

}
