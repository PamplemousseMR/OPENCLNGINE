#include "core/platform.hpp"

#include "exception/helper.hpp"
#include "exception/not.hpp"

#include <algorithm>
#include <assert.h>

namespace core
{

std::string Platform::getInfo(const cl_platform_id _platform, const cl_platform_info _name)
{
    assert(_platform != nullptr);
    size_t infoSize;
    {
        cl_int err = clGetPlatformInfo(_platform, _name, 0, nullptr, &infoSize);
        ::exception::checkCLError(err);
    }
    std::string info;
    info.resize(infoSize);
    {
        cl_int err = clGetPlatformInfo(_platform, _name, infoSize, &info[0], nullptr);
        ::exception::checkCLError(err);
    }
    return info;
}


Platform::Platform(const PLATFORM_VENDOR& _vendor)
{
    cl_uint platformCount;
    {
        cl_int err = clGetPlatformIDs(0, nullptr, &platformCount);
        ::exception::checkCLError(err);
    }

    if(platformCount == 0)
    {
        throw ::exception::Not("No platform found");
    }

    std::vector< cl_platform_id > platforms(platformCount);
    {
        cl_int err = clGetPlatformIDs(platformCount, &platforms[0], nullptr);
        ::exception::checkCLError(err);
    }

    switch (_vendor)
    {
    case DEFAULT:
        m_platform = platforms[0];
        break;
    case NVIDIA:
        m_platform = Platform::findFromVendor(platforms, "NVIDIA");
        break;
    case AMD:
        m_platform = Platform::findFromVendor(platforms, "AMD");
        break;
    case INTEL:
        m_platform = Platform::findFromVendor(platforms, "INTEL");
        break;
    }
}

std::string Platform::getName() const
{
    return Platform::getInfo(m_platform, CL_PLATFORM_NAME);
}

std::string Platform::getVendor() const
{
    return Platform::getInfo(m_platform, CL_PLATFORM_VENDOR);
}

std::string Platform::getVersion() const
{
    return Platform::getInfo(m_platform, CL_PLATFORM_VERSION);
}

std::string Platform::getProfile() const
{
    return Platform::getInfo(m_platform, CL_PLATFORM_PROFILE);
}

std::string Platform::getExtensions() const
{
    return Platform::getInfo(m_platform, CL_PLATFORM_EXTENSIONS);
}

cl_platform_id Platform::findFromVendor(std::vector< cl_platform_id >& _platforms, const std::string& _vendor)
{
    for(const cl_platform_id platform : _platforms)
    {
        assert(platform != nullptr);
        std::string info = Platform::getInfo(platform, CL_PLATFORM_VERSION);
        std::transform(info.begin(), info.end(),info.begin(), ::toupper);
        if(info.find(_vendor) != std::string::npos)
        {
            return platform;
        }
    }
    throw ::exception::Not("No platform found from vendor : " + _vendor);
}

std::ostream& operator<<(std::ostream& _o, const Platform& _p) noexcept
{
    _o << "[Platform]" << std::endl;
    _o << "\tVendor : " << _p.getVendor() << std::endl;
    _o << "\tName : " << _p.getName() << std::endl;
    _o << "\tVersion : " << _p.getVersion() << std::endl;
    _o << "\tProfile : " << _p.getProfile();
    return _o;
}

}
