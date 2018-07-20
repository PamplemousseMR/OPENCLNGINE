#pragma once

#include "core/context.hpp"

#include <CL/cl.h>

namespace core
{

class Program
{

    friend class Kernel;

    friend class Context;

public:

    ~Program();

    void build() const;

    size_t getNumKernel() const;

    std::vector< std::string > getKernelNames() const;

private:

    template< typename T >
    static T getInfo(const cl_program, const cl_profiling_info);

private:

    Program(const Context&, const std::string&);

private:

    cl_program m_program {nullptr};

    std::string m_sources {""};

    const Context& m_context;

};

}
