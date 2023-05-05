cmake_minimum_required (VERSION 3.10)
project(MyFirstCMake)

#------------------------------------------------------------------------------
# Compiler optimization
#------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
add_compile_options("-fPIC")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -03")
else()
  message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
endif()

#------------------------------------------------------------------------------
# Build options
#------------------------------------------------------------------------------
option(BUILD_TESTING "Build testing kits" OFF)

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
