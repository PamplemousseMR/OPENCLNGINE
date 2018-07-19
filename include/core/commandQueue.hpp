#pragma once

#include "core/context.hpp"
#include "core/device.hpp"

#include <CL/cl.h>

namespace core
{

class CommandQueue
{

    friend class Kernel;

public:

    CommandQueue(const Context&, const Device&);

    ~CommandQueue();

    const cl_command_queue getCommandQueue() const;

private:

    cl_command_queue m_commandQueue {nullptr};

};

}
