#pragma once

#include "core/device.hpp"

#include <CL/cl.hpp>

namespace core
{

class Context
{

public:

    Context(const Device&);

    void makeCurrent() const noexcept;

private:

    static ::cl::CommandQueue s_commandQueue;

private:

    void createCommandQueue(const Device&);

private:

    ::cl::Context m_context {};

    ::cl::CommandQueue m_commandQueue {};

};

}
