#include "core/device.hpp"

#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/unknow.hpp"

namespace core
{

Device::Device(const Platform& _platform,  const DEVICE_TYPE& _type)
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
        throw ::exception::Not("No device found");
    }

    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_PLATFORM :
        throw ::exception::Invalid("Invalid platform");
        break;
    case CL_INVALID_DEVICE_TYPE :
        throw ::exception::Invalid("Invalid device type");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    case CL_DEVICE_NOT_FOUND :
        throw ::exception::Invalid("Device not found");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }

    for(const ::cl::Device& device : devices)
    {
        if(device.getInfo< CL_DEVICE_AVAILABLE >())
        {
            m_device = device;
            return;
        }
    }
    throw ::exception::Not("Not available device found");
}

std::ostream& operator<<(std::ostream& _o, const Device& _d) noexcept
{
    _o << "[Device]" << std::endl;
    _o << "\tVendor : " << _d.m_device.getInfo<CL_DEVICE_VENDOR>() << std::endl;
    _o << "\tName : " << _d.m_device.getInfo<CL_DEVICE_NAME>() << std::endl;
    _o << "\tType : " << _d.m_device.getInfo<CL_DEVICE_TYPE>() << std::endl;
    _o << "\tVersion : " << _d.m_device.getInfo<CL_DEVICE_VERSION>() << std::endl;
    _o << "\tDriver version : " << _d.m_device.getInfo<CL_DRIVER_VERSION>() << std::endl;
    _o << "\tProfile : " << _d.m_device.getInfo<CL_DEVICE_PROFILE>();
    return _o;
}

}
