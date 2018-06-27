#include "exceptions/out.hpp"

namespace titane
{
namespace exception
{

Out::Out(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
}
