#pragma once

#include "core/buffer.hpp"
#include "core/commandQueue.hpp"
#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

class Kernel
{

public:

    Kernel(const Program&, const std::string&);

    ~Kernel();

    template< typename T >
    void setArg(const Buffer< T >&, uint32_t) const;

    void enqueueNDRange(const CommandQueue&, size_t, size_t) const;

    void finish(const CommandQueue&);

private:

    cl_kernel m_kernel {nullptr};

};

}
