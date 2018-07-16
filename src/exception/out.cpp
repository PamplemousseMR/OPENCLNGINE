#include "exception/out.hpp"

namespace exception
{

Out::Out(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
