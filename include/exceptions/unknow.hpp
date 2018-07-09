#pragma once

#include "exceptions/iexception.hpp"

#include <string>

namespace exception
{

class Unknow : public IException
{

public:

    Unknow(const std::string&) noexcept;

};

}
