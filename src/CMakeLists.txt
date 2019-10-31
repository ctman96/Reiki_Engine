set(REIKI_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/libs/GLAD/glad.c

        main.cpp
        Window.cpp Window.hpp

        math/vec2.cpp math/vec2.hpp
        math/vec3.cpp math/vec3.hpp
        math/vec4.cpp math/vec4.hpp
        math/mat3.cpp math/mat3.hpp)

add_executable(${PROJECT_NAME} ${REIKI_SOURCE_FILES})

# Added this so policy CMP0065 doesn't scream
set_target_properties(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 0)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/libs/GLAD)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${GLFW_LIBRARIES})

if (OPENGL_FOUND)
    target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_gl_LIBRARY})
endif()

if (IS_OS_WINDOWS)
    # Copy and rename dlls
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${GLFW_DLL}"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/glfw3.dll")
endif()
if (IS_OS_MAC)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${COCOA_LIBRARY} ${CF_LIBRARY})
endif()

if(IS_OS_LINUX)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_DL_LIBS})
endif()