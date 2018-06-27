#include "core/Device.hpp"

#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/unknow.hpp"

namespace titane
{
namespace core
{

Device::Device(const Platform& _platform,  const TITANE_DEVICE_TYPE& _type)
{
    std::vector< ::cl::Device > devices;
    cl_int err;
    switch (_type)
    {
    case DEFAULT:
         err = _platform.m_platform.getDevices(CL_DEVICE_TYPE_DEFAULT, &devices);
        break;
    case CPU:
        err = _platform.m_platform.getDevices(CL_DEVICE_TYPE_CPU, &devices);
        break;
    case GPU:
        err = _platform.m_platform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
        break;
    case ACCELERATOR:
        err = _platform.m_platform.getDevices(CL_DEVICE_TYPE_ACCELERATOR, &devices);
        break;
    }

    if(devices.empty())
    {
        throw ::titane::exception::Not("No device found");
    }

    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_PLATFORM :
        throw ::titane::exception::Invalid("Invalid platform");
        break;
    case CL_INVALID_DEVICE_TYPE :
        throw ::titane::exception::Invalid("Invalid device type");
        break;
    case CL_INVALID_VALUE :
        throw ::titane::exception::Invalid("Invalid value");
        break;
    case CL_DEVICE_NOT_FOUND :
        throw ::titane::exception::Invalid("Device not found");
        break;
    default :
        throw ::titane::exception::Unknow("Unknow exception");
        break;
    }

    for(const ::cl::Device& device : devices)
    {
        if(device.getInfo< CL_DEVICE_AVAILABLE >())
        {
            m_device = device;
        }
    }
    throw ::titane::exception::Not("Not available device found");
}

}
}
