#include "core/context.hpp"

#include "exception/helper.hpp"

namespace core
{

Context::Context(const Device& _device) :
    m_device(_device)
{
    cl_int err;
    m_context = clCreateContext(nullptr, 1, &m_device.m_device, nullptr, nullptr, &err);
    ::exception::checkCLError(err);
}

Context::~Context()
{
    cl_int err = clReleaseContext(m_context);
    ::exception::checkCLError(err);
}

const cl_context Context::getContext() const
{
    return m_context;
}

CommandQueue Context::createCommandQueue() const
{
    return CommandQueue(m_context, m_device.m_device);
}

Program Context::createProgram(const std::string& _sources) const
{
    return Program(m_context, m_device.m_device, _sources);
}

}
