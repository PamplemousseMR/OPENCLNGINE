#pragma once

#include "core/kernel.hpp"

#include <CL/cl.h>

#include <vector>

namespace core
{

class Program
{

    friend class Context;

public:

    ~Program();

    void build() const;

    Kernel createKernel(const std::string&) const;

    size_t getNumKernel() const;

    std::vector< std::string > getKernelNames() const;

private:

    template< typename T >
    static T getInfo(const cl_program, const cl_profiling_info);

private:

    Program(const cl_context, const cl_device_id, const std::string&);

private:

    cl_program m_program {nullptr};

    std::string m_sources {""};

    const cl_device_id m_device;

};

}
