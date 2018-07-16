#include "exception/helper.hpp"

#include "exception/failure.hpp"
#include "exception/invalid.hpp"
#include "exception/not.hpp"
#include "exception/out.hpp"
#include "exception/unknow.hpp"

namespace exception
{

void checkCLError(cl_int _err)
{
    if(_err != CL_SUCCESS)
    {
        switch(_err)
        {
        case CL_DEVICE_NOT_FOUND :
            throw ::exception::Not("No device founded");
            break;
        case CL_DEVICE_NOT_AVAILABLE :
            throw ::exception::Not("No device available");
            break;
        case CL_COMPILER_NOT_AVAILABLE :
            throw ::exception::Not("No compiler available");
            break;
        case CL_MEM_OBJECT_ALLOCATION_FAILURE :
            throw ::exception::Failure("Fail to allocate object");
            break;
        case CL_OUT_OF_RESOURCES :
            throw ::exception::Out("Out of resources");
            break;
        case CL_OUT_OF_HOST_MEMORY :
            throw ::exception::Out("Out of host memory");
            break;
        case CL_PROFILING_INFO_NOT_AVAILABLE :
            throw ::exception::Not("No profiling info available");
            break;
        case CL_MEM_COPY_OVERLAP :
            throw ::exception::Failure("Fail to copy memory");
            break;
        case CL_IMAGE_FORMAT_MISMATCH :
            throw ::exception::Failure("Fail to match image format");
            break;
        case CL_IMAGE_FORMAT_NOT_SUPPORTED :
            throw ::exception::Not("No image format supported");
            break;
        case CL_BUILD_PROGRAM_FAILURE :
            throw ::exception::Failure("Fail to build program");
            break;
        case CL_MAP_FAILURE :
            throw ::exception::Failure("Fail to map");
            break;
        case CL_MISALIGNED_SUB_BUFFER_OFFSET :
            throw ::exception::Failure("Fail to align sub buffer offset");
            break;
        case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST :
            throw ::exception::Failure("Fail to wait in list");
            break;
        case CL_COMPILE_PROGRAM_FAILURE :
            throw ::exception::Failure("Fail to compile program");
            break;
        case CL_LINKER_NOT_AVAILABLE :
            throw ::exception::Not("No linker available");
            break;
        case CL_LINK_PROGRAM_FAILURE :
            throw ::exception::Failure("Fail to link program");
            break;
        case CL_DEVICE_PARTITION_FAILED :
            throw ::exception::Failure("Fail to partition device");
            break;
        case CL_KERNEL_ARG_INFO_NOT_AVAILABLE :
            throw ::exception::Not("No kernel info available");
            break;
        case CL_INVALID_VALUE :
            throw ::exception::Invalid("Invalid value");
            break;
        case CL_INVALID_DEVICE_TYPE :
            throw ::exception::Invalid("Invalid device type");
            break;
        case CL_INVALID_PLATFORM :
            throw ::exception::Invalid("Invalid platform");
            break;
        case CL_INVALID_DEVICE :
            throw ::exception::Invalid("Invalid device");
            break;
        case CL_INVALID_CONTEXT :
            throw ::exception::Invalid("Invalid context");
            break;
        case CL_INVALID_QUEUE_PROPERTIES :
            throw ::exception::Invalid("Invalid queue properties");
            break;
        case CL_INVALID_COMMAND_QUEUE :
            throw ::exception::Invalid("Invalid command queue");
            break;
        case CL_INVALID_HOST_PTR :
            throw ::exception::Invalid("Invalid host ptr");
            break;
        case CL_INVALID_MEM_OBJECT :
            throw ::exception::Invalid("Invalid mem object");
            break;
        case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR :
            throw ::exception::Invalid("Invalid image format descriptor");
            break;
        case CL_INVALID_IMAGE_SIZE :
            throw ::exception::Invalid("Invalid image size");
            break;
        case CL_INVALID_SAMPLER :
            throw ::exception::Invalid("Invalid sampler");
            break;
        case CL_INVALID_BINARY :
            throw ::exception::Invalid("Invalid binary");
            break;
        case CL_INVALID_BUILD_OPTIONS :
            throw ::exception::Invalid("Invalid build options");
            break;
        case CL_INVALID_PROGRAM :
            throw ::exception::Invalid("Invalid program");
            break;
        case CL_INVALID_PROGRAM_EXECUTABLE :
            throw ::exception::Invalid("Invalid program executable");
            break;
        case CL_INVALID_KERNEL_NAME :
            throw ::exception::Invalid("Invalid kernel name");
            break;
        case CL_INVALID_KERNEL_DEFINITION :
            throw ::exception::Invalid("Invalid kernel definition");
            break;
        case CL_INVALID_KERNEL :
            throw ::exception::Invalid("Invalid kernel");
            break;
        case CL_INVALID_ARG_INDEX :
            throw ::exception::Invalid("Invalid arg index");
            break;
        case CL_INVALID_ARG_VALUE :
            throw ::exception::Invalid("Invalid arg value");
            break;
        case CL_INVALID_ARG_SIZE :
            throw ::exception::Invalid("Invalid arg size");
            break;
        case CL_INVALID_KERNEL_ARGS :
            throw ::exception::Invalid("Invalid kernel args");
            break;
        case CL_INVALID_WORK_DIMENSION :
            throw ::exception::Invalid("Invalid work dimension");
            break;
        case CL_INVALID_WORK_GROUP_SIZE :
            throw ::exception::Invalid("Invalid work group size");
            break;
        case CL_INVALID_WORK_ITEM_SIZE :
            throw ::exception::Invalid("Invalid work item size");
            break;
        case CL_INVALID_GLOBAL_OFFSET :
            throw ::exception::Invalid("Invalid global offset");
            break;
        case CL_INVALID_EVENT_WAIT_LIST :
            throw ::exception::Invalid("Invalid event wait list");
            break;
        case CL_INVALID_EVENT :
            throw ::exception::Invalid("Invalid event");
            break;
        case CL_INVALID_OPERATION :
            throw ::exception::Invalid("Invalid operation");
            break;
        case CL_INVALID_GL_OBJECT :
            throw ::exception::Invalid("Invalid gl object");
            break;
        case CL_INVALID_BUFFER_SIZE :
            throw ::exception::Invalid("Invalid buffer size");
            break;
        case CL_INVALID_MIP_LEVEL :
            throw ::exception::Invalid("Invalid mip level");
            break;
        case CL_INVALID_GLOBAL_WORK_SIZE :
            throw ::exception::Invalid("Invalid global work size");
            break;
        case CL_INVALID_PROPERTY :
            throw ::exception::Invalid("Invalid property");
            break;
        case CL_INVALID_IMAGE_DESCRIPTOR :
            throw ::exception::Invalid("Invalid image descriptor");
            break;
        case CL_INVALID_COMPILER_OPTIONS :
            throw ::exception::Invalid("Invalid compiler options");
            break;
        case CL_INVALID_LINKER_OPTIONS :
            throw ::exception::Invalid("Invalid linker options");
            break;
        case CL_INVALID_DEVICE_PARTITION_COUNT :
            throw ::exception::Invalid("Invalid device partition count");
            break;
        default:
            throw ::exception::Unknow("Unknow exception");
            break;
        }
    }
}

}
