#pragma once

#include "core/context.hpp"

#include <CL/cl.h>

namespace core
{

class Program
{

public:

    Program(const Context&, const std::string&);

    void build() const;

private:

};

}
