#include "core/commandQueue.hpp"

#include "exception/helper.hpp"

namespace core
{

CommandQueue::CommandQueue(const cl_context _context, const cl_device_id _device)
{
    cl_int err;
    m_commandQueue = clCreateCommandQueue(_context, _device, 0, &err);
    ::exception::checkCLError(err);
}

CommandQueue::~CommandQueue()
{
    cl_int err = clReleaseCommandQueue(m_commandQueue);
    ::exception::checkCLError(err);
}

const cl_command_queue CommandQueue::getCommandQueue() const
{
    return m_commandQueue;
}

}
