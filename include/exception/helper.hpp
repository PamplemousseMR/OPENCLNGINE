#pragma once

#ifndef __APPLE__
#include <CL/cl.h>
#else
#include <OpenCL/cl.h>
#endif

#include <string>

namespace exception
{

void checkCLError(cl_int);

}
