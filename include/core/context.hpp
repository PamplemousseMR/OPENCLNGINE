#pragma once

#include "core/device.hpp"

#include <CL/cl.hpp>

namespace core
{

class Context
{

    friend class Program;

public:

    Context(const Device&);

private:

    void createCommandQueue(const Device&);

private:

    ::cl::Context m_context {};

    ::cl::CommandQueue m_commandQueue {};

};

}
