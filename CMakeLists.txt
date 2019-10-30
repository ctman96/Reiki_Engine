cmake_minimum_required(VERSION 3.10)
project(Reiki)


if (POLICY CMP0025)
    cmake_policy(SET CMP0025 NEW)
endif ()
set (CMAKE_CXX_STANDARD 11)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)


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


set(SOURCE_FILES
        libs/GLAD/glad.c
        main.cpp
        src/Window.cpp
        src/Window.hpp src/math/vec2.cpp src/math/vec2.hpp src/math/vec3.cpp src/math/vec3.hpp src/math/mat3.cpp src/math/mat3.hpp src/math/vec4.cpp src/math/vec4.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC src/)


# Added this so policy CMP0065 doesn't scream
set_target_properties(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 0)


target_include_directories(${PROJECT_NAME} PUBLIC libs/GLAD)
target_include_directories(${PROJECT_NAME} PUBLIC libs/GLAD)


# Find OpenGL
find_package(OpenGL REQUIRED)

if (OPENGL_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_gl_LIBRARY})
endif()



if (IS_OS_WINDOWS)
    set(GLFW_FOUND TRUE)

    set(GLFW_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/include")

    # TODO 32 vs 64 bit like in 427 template?
    set(GLFW_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/lib/glfw3dll.lib")
    set(GLFW_DLL "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/lib/glfw3.dll")

    # Copy and rename dlls
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${GLFW_DLL}"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/glfw3.dll")
elseif(IS_OS_LINUX OR IS_OS_MAC)
    find_package(PkgConfig REQUIRED)

    pkg_search_module(GLFW REQURIED glfw3)

    # Link Frameworks on OSX
    if (IS_OS_MAC)
        find_library(COCOA_LIBRARY Cocoa)
        find_library(CF_LIBRARY CoreFoundation)
        target_link_libraries(${PROJECT_NAME} PUBLIC ${COCOA_LIBRARY} ${CF_LIBRARY})
    endif()
endif()


# Can't find the include and lib. Quit.
if (NOT GLFW_FOUND)
    message(FATAL_ERROR "Can't find GLFW." )
endif()


target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PUBLIC ${GLFW_LIBRARIES})


if(IS_OS_LINUX)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_DL_LIBS})
endif()