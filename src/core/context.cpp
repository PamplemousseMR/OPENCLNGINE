#include "core/context.hpp"

#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/out.hpp"
#include "exceptions/unknow.hpp"

namespace core
{

::cl::CommandQueue Context::s_commandQueue{};

Context::Context(const Device& _device)
{
    cl_int err;
    m_context = ::cl::Context(_device.m_device, nullptr, nullptr, nullptr, &err);

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
    case CL_DEVICE_NOT_AVAILABLE :
        throw ::exception::Not("Device not available");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Out("Out of host memory");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }

    createCommandQueue(_device);
}

void Context::makeCurrent() const noexcept
{
    s_commandQueue = m_commandQueue;
}

void Context::createCommandQueue(const Device& _device)
{
    cl_int err;
    m_commandQueue = ::cl::CommandQueue(m_context, _device.m_device, 0, &err);

    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_CONTEXT  :
        throw ::exception::Invalid("Invalid context");
        break;
    case CL_INVALID_DEVICE :
        throw ::exception::Invalid("Invalid device");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    case CL_INVALID_QUEUE_PROPERTIES  :
        throw ::exception::Invalid("Invalid queue properties");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Out("Out of host memory");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }
}

}
