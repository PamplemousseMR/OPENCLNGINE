#pragma once

#include "exceptions/iexception.hpp"

#include <string>

namespace titane
{
namespace exception
{

class Out : public IException
{

public:

    Out(const std::string&) noexcept;

};

}
}
