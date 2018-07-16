#pragma once

#include "core/device.hpp"

#include <CL/cl.h>

namespace core
{

class Context
{

    friend class Program;

public:

    Context(const Device&);

private:

};

}
