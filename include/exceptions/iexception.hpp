#pragma once

#include <exception>
#include <string>

namespace titane
{
namespace exception
{

class IException : public std::exception
{

public:

    IException(const std::string&) noexcept;

    virtual const char* what() const noexcept override;

private:

    std::string m_message{};

};

}
}
