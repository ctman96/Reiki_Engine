cmake_minimum_required(VERSION 3.10)
project(Reiki)

# Options. Turn on with 'cmake -D{VAR}=ON'
option(test "Build tests" OFF)
option(verbose "Verbose build output" OFF)
if (verbose)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()


if (POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif ()
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


#Find OS
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(IS_OS_MAC 1)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(IS_OS_LINUX 1)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(IS_OS_WINDOWS 1)
else()
    message(FATAL_ERROR "OS ${CMAKE_SYSTEM_NAME} was not recognized")
endif()


# Generate the folder location to the header
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/project_path.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/project_path.hpp")


# Find OpenGL
find_package(OpenGL REQUIRED)

if (IS_OS_WINDOWS)
    set(GLFW_FOUND TRUE)

    set(GLFW_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include")

    # TODO 32 vs 64 bit like in 427 template?
    set(GLFW_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/lib/glfw3dll.lib")
    set(GLFW_DLL "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/lib/glfw3.dll")
elseif(IS_OS_LINUX OR IS_OS_MAC)
    find_package(PkgConfig REQUIRED)

    pkg_search_module(GLFW REQURIED glfw3)

    # Link Frameworks on OSX
    if (IS_OS_MAC)
        find_library(COCOA_LIBRARY Cocoa)
        find_library(CF_LIBRARY CoreFoundation)
    endif()
endif()

## Get Glad
add_library(GLAD ${PROJECT_SOURCE_DIR}/libs/GLAD/glad.c)
target_include_directories(GLAD PRIVATE ${PROJECT_SOURCE_DIR}/libs/GLAD)

# Can't find the include and lib. Quit.
if (NOT GLFW_FOUND)
    message(FATAL_ERROR "Can't find GLFW." )
endif()

add_subdirectory(src)
if (test)
    add_subdirectory(test)
endif()