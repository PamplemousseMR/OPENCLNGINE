#pragma once

#include "exceptions/iexception.hpp"

#include <string>

namespace exception
{

class Not : public IException
{

public:

    Not(const std::string&) noexcept;

};

}
