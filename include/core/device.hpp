#pragma once

#include "exception/helper.hpp"

#include <CL/cl.h>

#include <vector>

namespace core
{

class Device
{

   friend class Context;

   friend class Program;

public:

    enum DEVICE_TYPE
    {
        DEFAULT = CL_DEVICE_TYPE_DEFAULT,
        CPU = CL_DEVICE_TYPE_CPU,
        GPU = CL_DEVICE_TYPE_GPU,
        ACCELERATOR = CL_DEVICE_TYPE_ACCELERATOR,
        ALL = CL_DEVICE_TYPE_ALL
    };

public:

    Device(const cl_platform_id, const DEVICE_TYPE& = DEFAULT);

    ~Device();

    Context createContext() const;

    uint64_t getType() const;

    uint32_t getVendorId() const;

    uint32_t getMaxComputeUnits() const;

    uint32_t getMaxWorkItemDimensions() const;

    size_t getMaxWorkGroupSize() const;

    std::vector< size_t > getMaxWorkItemSizes() const;

    uint32_t getPreferredVectorWidthChar() const;

    uint32_t getPreferredVectorWidthShort() const;

    uint32_t getPreferredVectorWidthInt() const;

    uint32_t getPreferredVectorWidthLong() const;

    uint32_t getPreferredVectorWidthFloat() const;

    uint32_t getPreferredVectorWidthDouble() const;

    uint32_t getMaxClockFrequency() const;

    uint32_t getAddressBits() const;

    uint32_t getMaxReadImageArgs() const;

    uint32_t getMaxWriteImageArgs() const;

    uint64_t getMaxMemAllocSize() const;

    size_t getImage2dMaxWidth() const;

    size_t getImage2dMaxHeight() const;

    size_t getImage3dMaxWidth() const;

    size_t getImage3dMaxHeight() const;

    size_t getImage3dMaxDepth() const;

    bool getImageSupport() const;

    size_t getMaxParameterSize() const;

    uint32_t getMaxSamplers() const;

    uint32_t getMemBaseAddrAlign() const;

    uint32_t getMinDataTypeAlignSize() const;

    uint64_t getSingleFpConfig() const;

    uint32_t getGlobalMemCacheType() const;

    uint32_t getGlobalMemCachelineSize() const;

    uint64_t getGlobalMemCacheSize() const;

    uint64_t getGlobalMemSize() const;

    uint64_t getMaxConstantBufferSize() const;

    uint32_t getMaxConstantArgs() const;

    uint32_t getLocalMemType() const;

    uint64_t getLocalMemSize() const;

    bool getErrorCorrectionSupport() const;

    size_t getProfilingTimerResolution() const;

    bool getEndianLittle() const;

    bool getAvailable() const;

    bool getCompilerAvailable() const;

    uint64_t getExecutionCapabilities() const;

    uint64_t getQueueProperties() const;

    std::string getName() const;

    std::string getVendor() const;

    std::string getDriverVersion() const;

    std::string getVersion() const;

    std::string getProfile() const;

    std::string getExtensions() const;

    uint64_t getDoubleFpConfig() const;

    uint32_t getPreferredVectorWidthHalf() const;

    uint32_t getHostUnifiedMemory() const;

    uint32_t getNativeVectorWidthChar() const;

    uint32_t getNativeVectorWidthShort() const;

    uint32_t getNativeVectorWidthInt() const;

    uint32_t getNativeVectorWidthLong() const;

    uint32_t getNativeVectorWidthFloat() const;

    uint32_t getNativeVectorWidthDouble() const;

    uint32_t getNativeVectorWidthHalf() const;

    std::string getOpenclCVersion() const;

    uint32_t getLinkerAvailable() const;

    uint32_t getBuiltInKernels() const;

    size_t getImageMaxBufferSize() const;

    size_t getImageMaxArraySize() const;

    uint32_t getPartitionMaxSubDevices() const;

    //int32_t getPartitionProperties() const;

    uint64_t getPartitionAffinityDomain() const;

    //uint32_t getPartitionType() const;

    uint32_t getReferenceCount() const;

    uint32_t getPreferredInteropUserSync() const;

    size_t getPrintfBufferSize() const;

    //uint32_t getImagePitchAlignment() const;

    //uint32_t getImageBaseAddressAlignment() const;

    friend std::ostream& operator<<(std::ostream&, const Device&) noexcept;

private:

    template< typename T >
    static T getInfo(const cl_device_id, const cl_device_info);

private:

    cl_device_id m_device {nullptr};

};

}
