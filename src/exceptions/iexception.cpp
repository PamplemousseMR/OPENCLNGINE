#include "exceptions/iexception.hpp"

namespace exception
{

IException::IException(const std::string& _message) noexcept
    :   std::exception(),
        m_message(_message)
{
}

const char* IException::what() const noexcept
{
    return m_message.c_str();
}

}
