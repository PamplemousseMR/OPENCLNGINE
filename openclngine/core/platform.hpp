#pragma once

#include "core/device.hpp"

#ifndef __APPLE__
#include <CL/cl.h>
#else
#include <OpenCL/cl.h>
#endif

#include <iostream>
#include <vector>

namespace core
{

class Platform
{

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

    Device createDevice(Device::DEVICE_TYPE = Device::DEFAULT) const;

    std::string getName() const;

    std::string getVendor() const;

    std::string getVersion() const;

    std::string getProfile() const;

    std::string getExtensions() const;

    friend std::ostream& operator<<(std::ostream&, const Platform&) noexcept;

private:

    static cl_platform_id findFromVendor(std::vector< cl_platform_id >&, const std::string&);

    static std::string getInfo(const cl_platform_id, const cl_platform_info);

private:

    cl_platform_id m_platform {nullptr};

};

}
