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
    const int LIST_SIZE = 1024;
    int* A = (int*)malloc(sizeof(int)*LIST_SIZE);
    int* B = (int*)malloc(sizeof(int)*LIST_SIZE);
    for(int i = 0; i < LIST_SIZE; ++i)
    {
        A[i] = i;
        B[i] = i;
    }

    ::core::Platform platform;
    std::cout << platform << std::endl;
    ::core::Device device(platform);
    std::cout << device << std::endl;
    ::core::Context context(device);
    ::core::CommandQueue commandQueue(context, device);

    ::core::Program program(context, source);
    program.build(device);
    ::core::Kernel kernel(program, "vector_add");

    ::core::Buffer< int > bufferA(context, commandQueue, ::core::READ, A, LIST_SIZE);
    ::core::Buffer< int > bufferB(context, ::core::READ, LIST_SIZE);
    bufferB.write(commandQueue, B);
    ::core::Buffer< int > bufferC(context, ::core::WRITE, LIST_SIZE);

    kernel.setArg(bufferA, 0);
    kernel.setArg(bufferB, 1);
    kernel.setArg(bufferC, 2);

    kernel.enqueueNDRange(commandQueue, LIST_SIZE, 64);
    kernel.finish(commandQueue);

    std::vector< int > res = bufferC.read(commandQueue);
    for(int val : res)
    {
        std::cout << val << std::endl;
    }

    free(A);
    free(B);

    return EXIT_SUCCESS;
}
