#pragma once

#include <CL/cl.h>

#include <iostream>
#include <vector>

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
