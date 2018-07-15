#pragma once

#include <CL/cl.hpp>

namespace core
{

class Platform
{

    friend class Device;

public:

    enum PLATFORM_VENDOR
    {
        DEFAULT,
        NVIDIA,
        AMD,
        INTEL
    };

public:

    Platform(const PLATFORM_VENDOR& = DEFAULT);

    friend std::ostream& operator<<(std::ostream&, const Platform&) noexcept;

private:

    static const ::cl::Platform& findFromVendor(std::vector< ::cl::Platform >&, const std::string&);

private:

    ::cl::Platform m_platform {};

};

}
