#include "core/buffer.hpp"
#include "core/buffer.hxx"
#include "core/commandQueue.hpp"
#include "core/context.hpp"
#include "core/device.hpp"
#include "core/kernel.hpp"
#include "core/kernel.hxx"
#include "core/platform.hpp"
#include "core/program.hpp"

#include <iostream>

#include <string>

const std::string source =
    "__kernel void vector_add(__global const int *A, __global const int *B, __global int *C) {"
    "   int i = get_global_id(0);"
    "   C[i] = A[i] + B[i];"
    "}";

int main ()
{
    const int bufferLength = 1024;
    std::vector< int > hostBufferA;
    std::vector< int > hostBufferB;
    for(int i = 0; i < bufferLength; ++i)
    {
        hostBufferA.push_back(i);
        hostBufferB.push_back(i);
    }

    ::core::Platform platform;
    std::cout << platform << std::endl;
    ::core::Device device(platform);
    std::cout << device << std::endl;
    ::core::Context context(device);

    ::core::CommandQueue commandQueue = context.createCommandQueue();
    ::core::Program program = context.createProgram(source);
    program.build();

    ::core::Kernel kernel(program, "vector_add");

    ::core::Buffer< int > bufferA(context, commandQueue, ::core::READ, hostBufferA);
    ::core::Buffer< int > bufferB(context, ::core::READ, bufferLength);
    bufferB.write(commandQueue, hostBufferB);
    ::core::Buffer< int > bufferC(context, ::core::WRITE, bufferLength);

    kernel.setArg(bufferA, 0);
    kernel.setArg(bufferB, 1);
    kernel.setArg(bufferC, 2);

    kernel.enqueueNDRange(commandQueue, bufferLength, 64);
    kernel.finish(commandQueue);

    std::vector< int > res = bufferC.read(commandQueue);
    for(int val : res)
    {
        std::cout << val << std::endl;
    }

    return EXIT_SUCCESS;
}
