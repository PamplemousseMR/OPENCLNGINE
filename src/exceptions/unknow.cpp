#include "exceptions/unknow.hpp"

namespace titane
{
namespace exception
{

Unknow::Unknow(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
}
