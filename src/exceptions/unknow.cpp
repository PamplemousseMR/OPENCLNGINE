#include "exceptions/unknow.hpp"

namespace exception
{

Unknow::Unknow(const std::string& _message) noexcept
    :   IException(_message.c_str())
{
}

}
