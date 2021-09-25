#pragma once

#include "exception/iexception.hpp"

#include <string>

namespace exception
{

class Failure : public IException
{

public:

    Failure(const std::string&) noexcept;

};

}
