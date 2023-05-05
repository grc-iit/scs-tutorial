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
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

#------------------------------------------------------------------------------
# Build options
#------------------------------------------------------------------------------
option(BUILD_TESTING "Build testing kits" OFF)

#------------------------------------------------------------------------------
# Setup CMake Output Directories
#------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all Executables.")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all Libraries")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all static libraries.")

#-----------------------------------------------------------------------------
# Dependencies common to all subdirectories
#-----------------------------------------------------------------------------
find_package(Boost COMPONENTS system filesystem REQUIRED)

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
