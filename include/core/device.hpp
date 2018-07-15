#pragma once

#include "core/platform.hpp"

#include <CL/cl.hpp>

namespace core
{

class Device
{

   friend class Context;

public:

    enum DEVICE_TYPE
    {
        DEFAULT,
        CPU,
        GPU,
        ACCELERATOR
    };

public:

    Device(const Platform&, const DEVICE_TYPE& = DEFAULT);

    friend std::ostream& operator<<(std::ostream& _o, const Device& _d) noexcept;

private:

    ::cl::Device m_device{};

};

}
