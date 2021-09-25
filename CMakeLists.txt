#=======================================
#                PROJECT
#=======================================

cmake_minimum_required(VERSION 3.0)
project("OPENCLNGINE" CXX)

#=======================================
#               LIBRARIES
#=======================================

find_package("OpenCL" REQUIRED)

#=======================================
#              EXECUTABLE
#=======================================

set(openclngine_src
    openclngine/core/commandQueue.cpp
    openclngine/core/context.cpp
    openclngine/core/device.cpp
    openclngine/core/kernel.cpp
    openclngine/core/platform.cpp
    openclngine/core/program.cpp
    openclngine/exception/failure.cpp
    openclngine/exception/helper.cpp
    openclngine/exception/iexception.cpp
    openclngine/exception/invalid.cpp
    openclngine/exception/not.cpp
    openclngine/exception/out.cpp
    openclngine/exception/unknow.cpp
    openclngine/openclngine.cpp)

set(openclngine_header
    openclngine/core/buffer.hpp
    openclngine/core/buffer.hxx
    openclngine/core/commandQueue.hpp
    openclngine/core/context.hpp
    openclngine/core/context.hxx
    openclngine/core/device.hpp
    openclngine/core/kernel.hpp
    openclngine/core/kernel.hxx
    openclngine/core/platform.hpp
    openclngine/core/program.hpp
    openclngine/exception/failure.hpp
    openclngine/exception/helper.hpp
    openclngine/exception/iexception.hpp
    openclngine/exception/invalid.hpp
    openclngine/exception/not.hpp
    openclngine/exception/out.hpp
    openclngine/exception/unknow.hpp)

add_executable(openclngine ${openclngine_src} ${openclngine_header})
target_include_directories(openclngine PRIVATE "openclngine")
set_target_properties(openclngine PROPERTIES CXX_STANDARD 14)
target_link_libraries(openclngine PRIVATE OpenCL::OpenCL)
