#include "exceptions/failure.hpp"

namespace exception
{

Failure::Failure(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
