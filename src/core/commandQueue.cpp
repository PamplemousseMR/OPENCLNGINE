#include "core/commandQueue.hpp"

#include "exception/helper.hpp"

namespace core
{

CommandQueue::CommandQueue(const Context& _context, const Device& _device)
{
    cl_int err;
    m_commandQueue = clCreateCommandQueue(_context.m_context, _device.m_device, 0, &err);
    ::exception::checkCLError(err);
}

CommandQueue::~CommandQueue()
{
    cl_int err = clReleaseCommandQueue(m_commandQueue);
    ::exception::checkCLError(err);
}

}
