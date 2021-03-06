#========================================
#	project
#========================================
CMAKE_MINIMUM_REQUIRED(VERSION 3.7)
PROJECT("OPENCLNGINE" CXX)

#================================================================================
#		init
#================================================================================

#========================================
#	variables
#========================================
SET(openclngine_project_name "openclngine")
SET(openclngine_src_dir "src")
SET(openclngine_header_dir "include")

#========================================
#	compiler specifications
#========================================
SET(CMAKE_CXX_STANDARD 14)
IF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    IF((CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "3.8.0") AND (CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL "3.9.1"))
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    ENDIF()
ENDIF()

#========================================
#	find files
#========================================
FILE(GLOB_RECURSE openclngine_src_files ${openclngine_src_dir}/*)
FILE(GLOB_RECURSE openclngine_header_files ${openclngine_header_dir}/*)

#================================================================================
#		create
#================================================================================

#========================================
#	create project
#========================================
ADD_EXECUTABLE(${openclngine_project_name} ${openclngine_src_files} ${openclngine_header_files})
TARGET_INCLUDE_DIRECTORIES(${openclngine_project_name} PRIVATE ${openclngine_header_dir})

#========================================
#	target specifications
#========================================
TARGET_COMPILE_FEATURES(${openclngine_project_name} PUBLIC cxx_noexcept)
TARGET_COMPILE_FEATURES(${openclngine_project_name} PUBLIC cxx_override)

#========================================
#	find OpenCL
#========================================
FIND_PACKAGE("OpenCL")

IF(NOT ${OpenCL_FOUND})
    MESSAGE(FATAL_ERROR "Can't find OpenCL")
ENDIF()

TARGET_INCLUDE_DIRECTORIES(${openclngine_project_name} PRIVATE ${OpenCL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${openclngine_project_name} ${OpenCL_LIBRARY})
