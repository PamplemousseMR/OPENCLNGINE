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

    return EXIT_SUCCESS;
}
