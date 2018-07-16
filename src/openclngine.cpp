#include "core/context.hpp"
#include "core/device.hpp"
#include "core/platform.hpp"

#include <iostream>

int main ()
{
    ::core::Platform platform;
    std::cout << platform << std::endl;
    ::core::Device device(platform);
    std::cout << device << std::endl;
    ::core::Context context(device);

    std::cout << device.getType() << std::endl;

    std::cout << device.getVendorId() << std::endl;

    std::cout << device.getMaxComputeUnits() << std::endl;

    std::cout << device.getMaxWorkItemDimensions() << std::endl;

    std::cout << device.getMaxWorkGroupSize() << std::endl;

    std::cout << device.getMaxWorkItemSizes()[0] << " " << device.getMaxWorkItemSizes()[1] << " " << device.getMaxWorkItemSizes()[2] << std::endl;

    std::cout << device.getPreferredVectorWidthChar() << std::endl;

    std::cout << device.getPreferredVectorWidthShort() << std::endl;

    std::cout << device.getPreferredVectorWidthInt() << std::endl;

    std::cout << device.getPreferredVectorWidthLong() << std::endl;

    std::cout << device.getPreferredVectorWidthFloat() << std::endl;

    std::cout << device.getPreferredVectorWidthDouble() << std::endl;

    std::cout << device.getMaxClockFrequency() << std::endl;

    std::cout << device.getAddressBits() << std::endl;

    std::cout << device.getMaxReadImageArgs() << std::endl;

    std::cout << device.getMaxWriteImageArgs() << std::endl;

    std::cout << device.getMaxMemAllocSize() << std::endl;

    std::cout << device.getImage2dMaxWidth() << std::endl;

    std::cout << device.getImage2dMaxHeight() << std::endl;

    std::cout << device.getImage3dMaxWidth() << std::endl;

    std::cout << device.getImage3dMaxHeight() << std::endl;

    std::cout << device.getImage3dMaxDepth() << std::endl;

    std::cout << device.getImageSupport() << std::endl;

    std::cout << device.getMaxParameterSize() << std::endl;

    std::cout << device.getMaxSamplers() << std::endl;

    std::cout << device.getMemBaseAddrAlign() << std::endl;

    std::cout << device.getMinDataTypeAlignSize() << std::endl;

    std::cout << device.getSingleFpConfig() << std::endl;

    std::cout << device.getGlobalMemCacheType() << std::endl;

    std::cout << device.getGlobalMemCachelineSize() << std::endl;

    std::cout << device.getGlobalMemCacheSize() << std::endl;

    std::cout << device.getGlobalMemSize() << std::endl;

    std::cout << device.getMaxConstantBufferSize() << std::endl;

    std::cout << device.getMaxConstantArgs() << std::endl;

    std::cout << device.getLocalMemType() << std::endl;

    std::cout << device.getLocalMemSize() << std::endl;

    std::cout << device.getErrorCorrectionSupport() << std::endl;

    std::cout << device.getProfilingTimerResolution() << std::endl;

    std::cout << device.getEndianLittle() << std::endl;

    std::cout << device.getAvailable() << std::endl;

    std::cout << device.getCompilerAvailable() << std::endl;

    std::cout << device.getExecutionCapabilities() << std::endl;

    std::cout << device.getQueueProperties() << std::endl;

    std::cout << device.getName() << std::endl;

    std::cout << device.getVendor() << std::endl;

    std::cout << device.getDriverVersion() << std::endl;

    std::cout << device.getVersion() << std::endl;

    std::cout << device.getProfile() << std::endl;

    std::cout << device.getExtensions() << std::endl;

    std::cout << device.getDoubleFpConfig() << std::endl;

    std::cout << device.getPreferredVectorWidthHalf() << std::endl;

    std::cout << device.getHostUnifiedMemory() << std::endl;

    std::cout << device.getNativeVectorWidthChar() << std::endl;

    std::cout << device.getNativeVectorWidthShort() << std::endl;

    std::cout << device.getNativeVectorWidthInt() << std::endl;

    std::cout << device.getNativeVectorWidthLong() << std::endl;

    std::cout << device.getNativeVectorWidthFloat() << std::endl;

    std::cout << device.getNativeVectorWidthDouble() << std::endl;

    std::cout << device.getNativeVectorWidthHalf() << std::endl;

    std::cout << device.getLinkerAvailable() << std::endl;

    std::cout << device.getBuiltInKernels() << std::endl;

    std::cout << device.getImageMaxBufferSize() << std::endl;

    std::cout << device.getImageMaxArraySize() << std::endl;

    std::cout << device.getPartitionMaxSubDevices() << std::endl;

    std::cout << device.getPartitionAffinityDomain() << std::endl;

    std::cout << device.getReferenceCount() << std::endl;

    std::cout << device.getPreferredInteropUserSync() << std::endl;

    //std::cout << device.getImagePitchAlignment() << std::endl;

    std::cout << device.getPrintfBufferSize() << std::endl;

    return EXIT_SUCCESS;
}
