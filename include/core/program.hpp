#pragma once

#include "core/context.hpp"

#include <CL/cl.h>

namespace core
{

class Program
{

    friend class Kernel;

public:

    Program(const Context&, const std::string&);

    ~Program();

    void build(const Device&) const;

    size_t getNumKernel() const;

    std::vector< std::string > getKernelNames();

private:

    template< typename T >
    static T getInfo(const cl_program, const cl_profiling_info);

private:

    cl_program m_program {nullptr};

    std::string m_sources {""};

};

}
