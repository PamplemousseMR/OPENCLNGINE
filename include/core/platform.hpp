#pragma once

#include <CL/cl.hpp>

namespace core
{

class Platform
{

    friend class Device;

public:

    enum TITANE_PLATFORM_VENDOR
    {
        DEFAULT,
        NVIDIA,
        AMD,
        INTEL
    };

public:

    Platform(const TITANE_PLATFORM_VENDOR& = DEFAULT);

private:

    static const ::cl::Platform& findFromVendor(std::vector< ::cl::Platform >&, const std::string&);

private:

    ::cl::Platform m_platform {};

};

}
