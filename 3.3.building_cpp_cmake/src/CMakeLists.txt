cmake_minimum_required (VERSION 3.10)
project(MyFirstCMake)

#------------------------------------------------------------------------------
# Compiler optimization
#------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
add_compile_options("-fPIC")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fPIC")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fPIC")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fPIC")
endif()

#------------------------------------------------------------------------------
# Version information
#------------------------------------------------------------------------------
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")

#------------------------------------------------------------------------------
# Build options
#------------------------------------------------------------------------------
option(BUILD_TESTING "Use GOTCHA as IO interception tool" OFF)I" OFF)

#-----------------------------------------------------------------------------
# Dependencies common to all subdirectories
#-----------------------------------------------------------------------------
find_package(OpenMP REQUIRED COMPONENTS C CXX)
find_package(Boost)

#-----------------------------------------------------------------------------
# Enable Testing
#-----------------------------------------------------------------------------
include(CTest)
if(CMAKE_PROJECT_NAME STREQUAL MyFirstCMake AND BUILD_TESTING)
  enable_testing()
endif()

#-----------------------------------------------------------------------------
# Source
#-----------------------------------------------------------------------------
add_subdirectory(src)

#-----------------------------------------------------------------------------
# Testing Sources
#-----------------------------------------------------------------------------
if(CMAKE_PROJECT_NAME STREQUAL MyFirstCMake AND BUILD_TESTING)
  add_subdirectory(test)
endif()
