cmake_minimum_required(VERSION 3.24)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# the project name is also the name of the resulting GDExtension library
project("gdextension_test" LANGUAGES CXX)

set(GODOT_PROJECT_NAME "GDExtension")
set(GODOT_PROJECT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${GODOT_PROJECT_NAME}")
set(GDEXTENSION_LIBRARY_OUTPUT_DIRECTORY "${GODOT_PROJECT_DIRECTORY}/bin")

if(NOT CMAKE_CXX_STANDARD)
    message(STATUS "Setting CMAKE_CXX_STANDARD to C++23")
    set(CMAKE_CXX_STANDARD 23)
endif()

# # testing settings
# include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptions.cmake)
include(cmake/DefaultCompilerWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

add_subdirectory(godot-cpp)
add_subdirectory(src)
