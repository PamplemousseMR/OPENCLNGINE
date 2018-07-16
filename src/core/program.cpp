#include "core/program.hpp"

#include <CL/cl.h>

namespace core
{

Program::Program(const Context& _context, const std::string& _source)
{
    /*cl_int err;
    m_program = ::cl::Program(_context.m_context, _source, false, &err);
    switch(err)
    {
    case CL_DEVICE_NOT_FOUND :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_DEVICE_NOT_AVAILABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_COMPILER_NOT_AVAILABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_MEM_OBJECT_ALLOCATION_FAILURE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_OUT_OF_RESOURCES :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_PROFILING_INFO_NOT_AVAILABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_MEM_COPY_OVERLAP :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_IMAGE_FORMAT_MISMATCH :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_IMAGE_FORMAT_NOT_SUPPORTED :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_BUILD_PROGRAM_FAILURE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_MAP_FAILURE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_MISALIGNED_SUB_BUFFER_OFFSET :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_COMPILE_PROGRAM_FAILURE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_LINKER_NOT_AVAILABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_LINK_PROGRAM_FAILURE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_DEVICE_PARTITION_FAILED :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_KERNEL_ARG_INFO_NOT_AVAILABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_DEVICE_TYPE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_PLATFORM :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_DEVICE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_CONTEXT :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_QUEUE_PROPERTIES :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_COMMAND_QUEUE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_HOST_PTR :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_MEM_OBJECT :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_IMAGE_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_SAMPLER :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_BINARY :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_BUILD_OPTIONS :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_PROGRAM :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_PROGRAM_EXECUTABLE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_KERNEL_NAME :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_KERNEL_DEFINITION :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_KERNEL :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_ARG_INDEX :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_ARG_VALUE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_ARG_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_KERNEL_ARGS :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_WORK_DIMENSION :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_WORK_GROUP_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_WORK_ITEM_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_GLOBAL_OFFSET :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_EVENT_WAIT_LIST :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_EVENT :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_OPERATION :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_GL_OBJECT :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_BUFFER_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_MIP_LEVEL :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_GLOBAL_WORK_SIZE :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_PROPERTY :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_IMAGE_DESCRIPTOR :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_COMPILER_OPTIONS :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_LINKER_OPTIONS :
        throw ::exception::Invalid("Invalid");
        break;
    case CL_INVALID_DEVICE_PARTITION_COUNT :
        throw ::exception::Invalid("Invalid");
        break;
    }*/
}

void Program::build() const
{
    /*cl_int err = m_program.build();
    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_PROGRAM :
        throw ::exception::Invalid("Invalid program");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    case CL_INVALID_DEVICE :
        throw ::exception::Invalid("Invalid device");
        break;
    case CL_INVALID_BINARY :
        throw ::exception::Invalid("Invalid binary");
        break;
    case CL_INVALID_BUILD_OPTIONS :
        throw ::exception::Invalid("Invalid build options");
        break;
    case CL_INVALID_OPERATION :
        throw ::exception::Invalid("Invalid operation");
        break;
    case CL_COMPILER_NOT_AVAILABLE :
        throw ::exception::Not("No compiler available");
        break;
    case CL_BUILD_PROGRAM_FAILURE :
        throw ::exception::Failure("Fail to build");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Out("Out of host memory");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }*/
}

}
