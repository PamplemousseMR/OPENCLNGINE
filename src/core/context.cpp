#include "core/context.hpp"

#include "exception/helper.hpp"

namespace core
{

Context::Context(const Device& _device)
{
    cl_int err;
    m_context = clCreateContext(nullptr, 1, &_device.m_device, nullptr, nullptr, &err);
    ::exception::checkCLError(err);
}

Context::~Context()
{
    cl_int err = clReleaseContext(m_context);
    ::exception::checkCLError(err);
}

}
