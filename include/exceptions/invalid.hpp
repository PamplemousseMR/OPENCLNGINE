#pragma once

#include "exceptions/iexception.hpp"

#include <string>

namespace titane
{
namespace exception
{

class Invalid : public IException
{

public:

    Invalid(const std::string&) noexcept;

};

}
}
