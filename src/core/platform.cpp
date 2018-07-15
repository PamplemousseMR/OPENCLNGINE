#include "core/platform.hpp"

#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/unknow.hpp"

#include <algorithm>

namespace core
{

Platform::Platform(const PLATFORM_VENDOR& _vendor)
{
    std::vector< ::cl::Platform > platforms;
    cl_int err = ::cl::Platform::get(&platforms);

    if(platforms.empty())
    {
        throw ::exception::Not("No platform found");
    }

    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
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

const ::cl::Platform& Platform::findFromVendor(std::vector< ::cl::Platform >& _platforms, const std::string& _vendor)
{
    cl_int err;
    for(const ::cl::Platform& platform : _platforms)
    {
        std::string vendor = platform.getInfo< CL_PLATFORM_VENDOR >(&err);
        switch(err)
        {
        case CL_SUCCESS :
            break;
        case CL_INVALID_PLATFORM :
            throw ::exception::Invalid("Invalid platform");
            break;
        case CL_INVALID_VALUE :
            throw ::exception::Invalid("Invalid value");
            break;
        default :
            throw ::exception::Unknow("Unknow exception");
            break;
        }
        std::transform(vendor.begin(), vendor.end(),vendor.begin(), ::toupper);
        if(vendor.find(_vendor) != std::string::npos)
        {
            return platform;
        }
    }
    throw ::exception::Not("No platform found from vendor : " + _vendor);
}

std::ostream& operator<<(std::ostream& _o, const Platform& _p) noexcept
{
    _o << "[Platform]" << std::endl;
    _o << "\tVendor : " << _p.m_platform.getInfo<CL_PLATFORM_VENDOR>() << std::endl;
    _o << "\tName : " << _p.m_platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
    _o << "\tVersion : " << _p.m_platform.getInfo<CL_PLATFORM_VERSION>() << std::endl;
    _o << "\tProfile : " << _p.m_platform.getInfo<CL_PLATFORM_PROFILE>();
    return _o;
}

}
