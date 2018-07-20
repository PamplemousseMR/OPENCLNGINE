#include "core/device.hpp"

#include "exception/not.hpp"

#include <assert.h>

namespace core
{

template< typename T >
T Device::getInfo(const cl_device_id _device, const cl_device_info _name)
{
    assert(_device != nullptr);
    T info;
    {
        cl_int err = clGetDeviceInfo(_device, _name, sizeof(T), &info, nullptr);
        ::exception::checkCLError(err);
    }
    return info;
}

template<>
std::string Device::getInfo< std::string >(const cl_device_id _device, const cl_device_info _name)
{
    assert(_device != nullptr);
    size_t infoSize;
    {
        cl_int err = clGetDeviceInfo(_device, _name, 0, nullptr, &infoSize);
        ::exception::checkCLError(err);
    }
    std::string info;
    info.resize(infoSize);
    {
        cl_int err = clGetDeviceInfo(_device, _name, infoSize, &info[0], nullptr);
        ::exception::checkCLError(err);
    }
    return info;
}

Device::Device(const Platform& _platform,  const DEVICE_TYPE& _type)
{
    cl_uint deviceCount;
    {
        cl_int err = clGetDeviceIDs(_platform.m_platform, _type, 0, nullptr, &deviceCount);
        ::exception::checkCLError(err);
    }

    if(deviceCount == 0)
    {
        throw ::exception::Not("No device found");
    }

    std::vector< cl_device_id > devices(deviceCount);
    {
        cl_int err = clGetDeviceIDs(_platform.m_platform, _type, deviceCount, &devices[0], nullptr);
        ::exception::checkCLError(err);
    }

    for(const cl_device_id device : devices)
    {
        cl_bool available = getInfo< cl_bool >(device, CL_DEVICE_AVAILABLE);
        cl_bool compilerAvailable = getInfo< cl_bool >(device, CL_DEVICE_COMPILER_AVAILABLE);
        cl_bool linkerAvailable = getInfo< cl_bool >(device, CL_DEVICE_LINKER_AVAILABLE);
        if(available && compilerAvailable && linkerAvailable)
        {
            m_device = device;
            return;
        }
    }
    throw ::exception::Not("No available device found");
}

Device::~Device()
{
    cl_int err = clReleaseDevice(m_device);
    ::exception::checkCLError(err);
}

uint64_t Device::getType() const
{
    return Device::getInfo< cl_device_type >(m_device, CL_DEVICE_TYPE);
}

uint32_t Device::getVendorId() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_VENDOR_ID);
}

uint32_t Device::getMaxComputeUnits() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_COMPUTE_UNITS);
}

uint32_t Device::getMaxWorkItemDimensions() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS);
}

size_t Device::getMaxWorkGroupSize() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_MAX_WORK_GROUP_SIZE);
}

std::vector< size_t > Device::getMaxWorkItemSizes() const
{
    uint32_t dim = getMaxWorkItemDimensions();
    size_t* arr = new size_t[dim];
    cl_uint err = clGetDeviceInfo(m_device, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(size_t)*dim, arr, nullptr);
    ::exception::checkCLError(err);
    std::vector< size_t > res(arr, arr + dim);
    delete[] arr;
    return res;
}

uint32_t Device::getPreferredVectorWidthChar() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR);
}

uint32_t Device::getPreferredVectorWidthShort() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT);
}

uint32_t Device::getPreferredVectorWidthInt() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT);
}

uint32_t Device::getPreferredVectorWidthLong() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG);
}

uint32_t Device::getPreferredVectorWidthFloat() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT);
}

uint32_t Device::getPreferredVectorWidthDouble() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE);
}

uint32_t Device::getMaxClockFrequency() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_CLOCK_FREQUENCY);
}

uint32_t Device::getAddressBits() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_ADDRESS_BITS);
}

uint32_t Device::getMaxReadImageArgs() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_READ_IMAGE_ARGS);
}

uint32_t Device::getMaxWriteImageArgs() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_WRITE_IMAGE_ARGS);
}

uint64_t Device::getMaxMemAllocSize() const
{
    return Device::getInfo< cl_ulong >(m_device, CL_DEVICE_MAX_MEM_ALLOC_SIZE);
}

size_t Device::getImage2dMaxWidth() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE2D_MAX_WIDTH);
}

size_t Device::getImage2dMaxHeight() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE2D_MAX_HEIGHT);
}

size_t Device::getImage3dMaxWidth() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE3D_MAX_WIDTH);
}

size_t Device::getImage3dMaxHeight() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE3D_MAX_HEIGHT);
}

size_t Device::getImage3dMaxDepth() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE3D_MAX_DEPTH);
}

bool Device::getImageSupport() const
{
    return Device::getInfo< cl_bool >(m_device, CL_DEVICE_IMAGE_SUPPORT) == CL_TRUE;
}

size_t Device::getMaxParameterSize() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_MAX_PARAMETER_SIZE);
}

uint32_t Device::getMaxSamplers() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_SAMPLERS);
}

uint32_t Device::getMemBaseAddrAlign() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MEM_BASE_ADDR_ALIGN);
}

uint32_t Device::getMinDataTypeAlignSize() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE);
}

uint64_t Device::getSingleFpConfig() const
{
    return Device::getInfo< cl_device_fp_config >(m_device, CL_DEVICE_SINGLE_FP_CONFIG);
}

uint32_t Device::getGlobalMemCacheType() const
{
    return Device::getInfo< cl_device_mem_cache_type >(m_device, CL_DEVICE_GLOBAL_MEM_CACHE_TYPE);
}

uint32_t Device::getGlobalMemCachelineSize() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE);
}

uint64_t Device::getGlobalMemCacheSize() const
{
    return Device::getInfo< cl_ulong >(m_device, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE);
}

uint64_t Device::getGlobalMemSize() const
{
    return Device::getInfo< cl_ulong >(m_device, CL_DEVICE_GLOBAL_MEM_SIZE);
}

uint64_t Device::getMaxConstantBufferSize() const
{
    return Device::getInfo< cl_ulong >(m_device, CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE);
}

uint32_t Device::getMaxConstantArgs() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_MAX_CONSTANT_ARGS);
}

uint32_t Device::getLocalMemType() const
{
    return Device::getInfo< cl_device_local_mem_type >(m_device, CL_DEVICE_LOCAL_MEM_TYPE);
}

uint64_t Device::getLocalMemSize() const
{
    return Device::getInfo< cl_ulong >(m_device, CL_DEVICE_LOCAL_MEM_SIZE);
}

bool Device::getErrorCorrectionSupport() const
{
    return Device::getInfo< cl_bool >(m_device, CL_DEVICE_ERROR_CORRECTION_SUPPORT) == CL_TRUE;
}

size_t Device::getProfilingTimerResolution() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_PROFILING_TIMER_RESOLUTION);
}

bool Device::getEndianLittle() const
{
    return Device::getInfo< cl_bool >(m_device, CL_DEVICE_ENDIAN_LITTLE) == CL_TRUE;
}

bool Device::getAvailable() const
{
    return Device::getInfo< cl_bool >(m_device, CL_DEVICE_AVAILABLE) == CL_TRUE;
}

bool Device::getCompilerAvailable() const
{
    return Device::getInfo< cl_bool >(m_device, CL_DEVICE_COMPILER_AVAILABLE) == CL_TRUE;
}

uint64_t Device::getExecutionCapabilities() const
{
    return Device::getInfo< cl_device_exec_capabilities >(m_device, CL_DEVICE_EXECUTION_CAPABILITIES);
}

uint64_t Device::getQueueProperties() const
{
    return Device::getInfo< cl_command_queue_properties >(m_device, CL_DEVICE_QUEUE_PROPERTIES);
}

std::string Device::getName() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_NAME);
}

std::string Device::getVendor() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_VENDOR);
}

std::string Device::getDriverVersion() const
{
    return Device::getInfo< std::string >(m_device, CL_DRIVER_VERSION);
}

std::string Device::getVersion() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_VERSION);
}

std::string Device::getProfile() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_PROFILE);
}

std::string Device::getExtensions() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_EXTENSIONS);
}

uint64_t Device::getDoubleFpConfig() const
{
    return Device::getInfo< cl_device_fp_config >(m_device, CL_DEVICE_DOUBLE_FP_CONFIG);
}

uint32_t Device::getPreferredVectorWidthHalf() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF);
}

uint32_t Device::getHostUnifiedMemory() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_HOST_UNIFIED_MEMORY);
}

uint32_t Device::getNativeVectorWidthChar() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR);
}

uint32_t Device::getNativeVectorWidthShort() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT);
}

uint32_t Device::getNativeVectorWidthInt() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_INT);
}

uint32_t Device::getNativeVectorWidthLong() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG);
}

uint32_t Device::getNativeVectorWidthFloat() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT);
}

uint32_t Device::getNativeVectorWidthDouble() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE);
}

uint32_t Device::getNativeVectorWidthHalf() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF);
}

std::string Device::getOpenclCVersion() const
{
    return Device::getInfo< std::string >(m_device, CL_DEVICE_OPENCL_C_VERSION);
}

uint32_t Device::getLinkerAvailable() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_LINKER_AVAILABLE);
}

uint32_t Device::getBuiltInKernels() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_BUILT_IN_KERNELS);
}

size_t Device::getImageMaxBufferSize() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE_MAX_BUFFER_SIZE);
}

size_t Device::getImageMaxArraySize() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_IMAGE_MAX_ARRAY_SIZE);
}

uint32_t Device::getPartitionMaxSubDevices() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PARTITION_MAX_SUB_DEVICES);
}

/*int32_t Device::getPartitionProperties() const
{
    return Device::getInfo< cl_device_partition_property >(m_device, CL_DEVICE_PARTITION_PROPERTIES);
}*/

uint64_t Device::getPartitionAffinityDomain() const
{
    return Device::getInfo< cl_device_affinity_domain >(m_device, CL_DEVICE_PARTITION_AFFINITY_DOMAIN);
}

/*uint32_t Device::getPartitionType() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PARTITION_TYPE);
}*/

uint32_t Device::getReferenceCount() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_REFERENCE_COUNT);
}

uint32_t Device::getPreferredInteropUserSync() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_PREFERRED_INTEROP_USER_SYNC);
}

size_t Device::getPrintfBufferSize() const
{
    return Device::getInfo< size_t >(m_device, CL_DEVICE_PRINTF_BUFFER_SIZE);
}

/*uint32_t Device::getImagePitchAlignment() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_IMAGE_PITCH_ALIGNMENT);
}*/

/*uint32_t Device::getImageBaseAddressAlignment() const
{
    return Device::getInfo< cl_uint >(m_device, CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT);
}*/

std::ostream& operator<<(std::ostream& _o, const Device& _d) noexcept
{
    _o << "[Device]" << std::endl;
    _o << "\tVendor : " << _d.getVendor() << std::endl;
    _o << "\tName : " << _d.getName() << std::endl;
    _o << "\tVersion : " << _d.getVersion() << std::endl;
    _o << "\tDriver version : " << _d.getDriverVersion() << std::endl;
    _o << "\tProfile : " << _d.getProfile();
    return _o;
}

}
