#include "core/buffer.hpp"
#include "core/buffer.hxx"
#include "core/commandQueue.hpp"
#include "core/context.hpp"
#include "core/context.hxx"
#include "core/device.hpp"
#include "core/kernel.hpp"
#include "core/kernel.hxx"
#include "core/platform.hpp"
#include "core/program.hpp"

#include <iostream>

#include <string>

const std::string source =
    "typedef struct container_t"
    "{"
    "   double m_d;"
    "   int m_i;"
    "}"
    "Container;"
    ""
    "__kernel void vector_add(__global const int* _bufferA, __global const int* _bufferB, __global double* _bufferC, int _factor, Container _container) {"
    "   int i = get_global_id(0);"
    "   _bufferC[i] = (_bufferA[i] + _bufferB[i]) * _factor + _container.m_d + _container.m_i;"
    "}";


typedef struct container_t
{
   double m_d;
   int m_i;
}
Container;

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
    ::core::Device device = platform.createDevice();
    ::core::Context context = device.createContext();

    ::core::CommandQueue commandQueue = context.createCommandQueue();

    ::core::Program program = context.createProgram(source);
    program.build();

    ::core::Kernel kernel = program.createKernel("vector_add");

    ::core::Buffer< int > bufferA = context.createBuffer(commandQueue, ::core::READ, hostBufferA);
    ::core::Buffer< int > bufferB = context.createBuffer< int >(::core::READ, bufferLength);
    bufferB.write(commandQueue, hostBufferB);
    ::core::Buffer< double > bufferC = context.createBuffer< double >(::core::WRITE, bufferLength);

    kernel.setArg(bufferA, 0);
    kernel.setArg(bufferB, 1);
    kernel.setArg(bufferC, 2);
    kernel.setArg(2, 3);
    kernel.setArg(Container{1.2, 3},4);

    kernel.enqueueNDRange(commandQueue, bufferLength, 64);
    kernel.finish();

    std::vector< double > res = bufferC.read(commandQueue);
    for(double val : res)
    {
        std::cout << val << std::endl;
    }

    return EXIT_SUCCESS;
}
