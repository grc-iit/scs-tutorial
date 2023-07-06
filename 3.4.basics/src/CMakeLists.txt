#------------------------------------------------------------------------------
# Include Header Directories
#------------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR}/include)

#------------------------------------------------------------------------------
# Build libstdc++ test
#------------------------------------------------------------------------------
add_executable(test_libstd ${CMAKE_CURRENT_SOURCE_DIR}/libstd.cc)
target_link_libraries(test_libstd stdc++fs)

#------------------------------------------------------------------------------
# Build POSIX test
#------------------------------------------------------------------------------
add_executable(test_posix ${CMAKE_CURRENT_SOURCE_DIR}/libstd.cc)
target_link_libraries(test_posix stdc++fs)

#------------------------------------------------------------------------------
# Build STDIO test
#------------------------------------------------------------------------------
add_executable(test_stdio ${CMAKE_CURRENT_SOURCE_DIR}/libstd.cc)
target_link_libraries(test_stdio stdc++fs)
