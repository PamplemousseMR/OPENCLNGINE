#pragma once

#include "core/buffer.hpp"
#include "core/commandQueue.hpp"

#include <CL/cl.h>

namespace core
{

class Kernel
{

    friend class Program;

public:

    ~Kernel();

    template< typename T >
    void setArg(const Buffer< T >&, uint32_t) const;

    void enqueueNDRange(const CommandQueue&, size_t, size_t);

    void finish();

private:

    Kernel(const cl_program, const std::string&);

private:

    cl_kernel m_kernel {nullptr};

    cl_command_queue m_commandQueue {nullptr};

};

}
