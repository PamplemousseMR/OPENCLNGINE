#include "exceptions/not.hpp"

namespace exception
{

Not::Not(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
