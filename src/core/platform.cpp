#include "core/platform.hpp"

#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/unknow.hpp"

#include <algorithm>

namespace titane
{
namespace core
{

Platform::Platform(const TITANE_PLATFORM_VENDOR& _vendor)
{
    std::vector< ::cl::Platform > platforms;
    cl_int err = ::cl::Platform::get(&platforms);

    if(platforms.empty())
    {
        throw ::titane::exception::Not("No platform found");
    }

    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_VALUE :
        throw ::titane::exception::Invalid("Invalid value");
        break;
    default :
        throw ::titane::exception::Unknow("Unknow exception");
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
            throw ::titane::exception::Invalid("Invalid platform");
            break;
        case CL_INVALID_VALUE :
            throw ::titane::exception::Invalid("Invalid value");
            break;
        default :
            throw ::titane::exception::Unknow("Unknow exception");
            break;
        }
        std::transform(vendor.begin(), vendor.end(),vendor.begin(), ::toupper);
        if(vendor.find(_vendor) != std::string::npos)
        {
            return platform;
        }
    }
    throw ::titane::exception::Not("No platform found from vendor : " + _vendor);
}

}
}
