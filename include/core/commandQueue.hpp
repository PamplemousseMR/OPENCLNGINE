#pragma once

#include "core/context.hpp"
#include "core/device.hpp"

#include <CL/cl.h>

namespace core
{

class CommandQueue
{

    friend class Kernel;

    friend class Context;

public:

    ~CommandQueue();

    const cl_command_queue getCommandQueue() const;

private:

    CommandQueue(const Context&, const Device&);

private:

    cl_command_queue m_commandQueue {nullptr};

};

}
