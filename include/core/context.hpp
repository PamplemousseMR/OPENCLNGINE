#pragma once

#include "core/commandQueue.hpp"
#include "core/device.hpp"
#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

class Context
{

    friend class CommandQueue;

    friend class Program;

public:

    Context(const Device&);

    ~Context();

    const cl_context getContext() const;

    CommandQueue createCommandQueue() const;

    Program createProgram(const std::string&) const;

private:

    cl_context m_context {nullptr};

    const Device& m_device;

};

}
