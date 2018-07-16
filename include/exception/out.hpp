#pragma once

#include "exception/iexception.hpp"

#include <string>

namespace exception
{

class Out : public IException
{

public:

    Out(const std::string&) noexcept;

};

}
