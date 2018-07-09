#pragma once

#include "core/platform.hpp"

#include <CL/cl.hpp>

namespace core
{

class Device
{

   friend class Context;

public:

    enum TITANE_DEVICE_TYPE
    {
        DEFAULT,
        CPU,
        GPU,
        ACCELERATOR
    };

public:

    Device(const Platform&, const TITANE_DEVICE_TYPE& = DEFAULT);

private:

    ::cl::Device m_device{};

};

}
