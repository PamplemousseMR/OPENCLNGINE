CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#------------ project ------------
PROJECT("Titane")

#------------ variables ------------
SET(titane_src_dir "src")
SET(titane_header_dir "include")
SET(titane_project_name "titane")

#------ find files ------
FILE(GLOB_RECURSE titane_src_files ${titane_src_dir}/*)
FILE(GLOB_RECURSE titane_header_files ${titane_header_dir}/*)

#------------ create project ------------
INCLUDE_DIRECTORIES(${titane_header_dir})
ADD_EXECUTABLE(${titane_project_name} ${titane_src_files} ${titane_header_files})

#------------ compiler specifications ------------
TARGET_COMPILE_FEATURES(${titane_project_name} PUBLIC cxx_noexcept)
TARGET_COMPILE_FEATURES(${titane_project_name} PUBLIC cxx_override)

#------ find OpenCL ------
FIND_PACKAGE("OpenCL")

IF(NOT ${OpenCL_FOUND})
    MESSAGE(FATAL_ERROR "Can't find OpenCL")
ENDIF()

INCLUDE_DIRECTORIES(${OpenCL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${titane_project_name} ${OpenCL_LIBRARY})
