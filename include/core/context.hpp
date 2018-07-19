#pragma once

#include "core/device.hpp"

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

private:

    cl_context m_context {nullptr};

};

}
