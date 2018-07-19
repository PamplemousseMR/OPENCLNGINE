#pragma once

#include "core/context.hpp"
#include "core/device.hpp"

#include <CL/cl.h>

namespace core
{

class CommandQueue
{

public:

    CommandQueue(const Context&, const Device&);

    ~CommandQueue();

private:

    cl_command_queue m_commandQueue {nullptr};

};

}
