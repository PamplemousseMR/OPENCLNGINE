#include "core/program.hpp"

#include "exceptions/failure.hpp"
#include "exceptions/invalid.hpp"
#include "exceptions/not.hpp"
#include "exceptions/out.hpp"
#include "exceptions/unknow.hpp"

#include <CL/cl.hpp>

namespace core
{

Program::Program(const Context& _context, const std::string& _source)
{
    cl_int err;
    m_program = ::cl::Program(_context.m_context, _source, false, &err);
    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_CONTEXT :
        throw ::exception::Invalid("Invalid context");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Out("Out of host memory");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }
}

void Program::build() const
{
    cl_int err = m_program.build();
    switch(err)
    {
    case CL_SUCCESS :
        break;
    case CL_INVALID_PROGRAM :
        throw ::exception::Invalid("Invalid program");
        break;
    case CL_INVALID_VALUE :
        throw ::exception::Invalid("Invalid value");
        break;
    case CL_INVALID_DEVICE :
        throw ::exception::Invalid("Invalid device");
        break;
    case CL_INVALID_BINARY :
        throw ::exception::Invalid("Invalid binary");
        break;
    case CL_INVALID_BUILD_OPTIONS :
        throw ::exception::Invalid("Invalid build options");
        break;
    case CL_INVALID_OPERATION :
        throw ::exception::Invalid("Invalid operation");
        break;
    case CL_COMPILER_NOT_AVAILABLE :
        throw ::exception::Not("No compiler available");
        break;
    case CL_BUILD_PROGRAM_FAILURE :
        throw ::exception::Failure("Fail to build");
        break;
    case CL_OUT_OF_HOST_MEMORY :
        throw ::exception::Out("Out of host memory");
        break;
    default :
        throw ::exception::Unknow("Unknow exception");
        break;
    }
}

}
