#pragma once

#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

class Kernel
{

public:

    Kernel(const Program&, const std::string&);

    ~Kernel();

private:

    cl_kernel m_kernel {nullptr};

};

}
