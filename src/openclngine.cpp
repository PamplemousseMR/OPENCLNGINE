#include "core/commandQueue.hpp"
#include "core/context.hpp"
#include "core/device.hpp"
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
    ::core::Platform platform;
    std::cout << platform << std::endl;
    ::core::Device device(platform);
    std::cout << device << std::endl;
    ::core::Context context(device);
    ::core::CommandQueue commandQueue(context, device);
    ::core::Program program(context, source);
    program.build(device);

    return EXIT_SUCCESS;
}
