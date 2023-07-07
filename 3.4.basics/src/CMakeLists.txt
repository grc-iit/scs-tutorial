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

#------------------------------------------------------------------------------
# Build parameter pass test
#------------------------------------------------------------------------------
add_executable(test_parameter_pass ${CMAKE_CURRENT_SOURCE_DIR}/parameter_pass.cc)
target_link_libraries(test_parameter_pass stdc++fs)

#------------------------------------------------------------------------------
# Build Kitchen Fire Dataset
#------------------------------------------------------------------------------
add_executable(make_kitchen_fire ${CMAKE_CURRENT_SOURCE_DIR}/make_kitchen_fire.cc)
target_link_libraries(make_kitchen_fire stdc++fs)
add_executable(analyze_kitchen_fire ${CMAKE_CURRENT_SOURCE_DIR}/analyze_kitchen_fire.cc)
target_link_libraries(analyze_kitchen_fire stdc++fs)

#------------------------------------------------------------------------------
# Build data structures
#------------------------------------------------------------------------------
add_executable(data_structure ${CMAKE_CURRENT_SOURCE_DIR}/data_structures.cc)
target_link_libraries(data_structure stdc++fs)


#------------------------------------------------------------------------------
# Build Configuration Manager
#------------------------------------------------------------------------------
add_executable(config_manager ${CMAKE_CURRENT_SOURCE_DIR}/config_manager.cc)
target_link_libraries(config_manager stdc++fs)

#------------------------------------------------------------------------------
# Build IOSched Factory
#------------------------------------------------------------------------------
add_executable(iosched_factory ${CMAKE_CURRENT_SOURCE_DIR}/iosched_factory.cc)
target_link_libraries(iosched_factory stdc++fs)