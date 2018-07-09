#include "exceptions/invalid.hpp"

namespace exception
{

Invalid::Invalid(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
