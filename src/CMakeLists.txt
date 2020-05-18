## Core source library
set(REIKI_SOURCE_FILES
        core/Core.hpp
        core/Window.cpp core/Window.hpp
        core/GameEngine.cpp core/GameEngine.hpp
        core/GameState.hpp

        math/Math.hpp
        math/vec2.cpp math/vec2.hpp
        math/vec3.cpp math/vec3.hpp
        math/vec4.cpp math/vec4.hpp
        math/mat3.cpp math/mat3.hpp

        ecs/ECS.hpp
        ecs/Component.hpp
        ecs/Entity.hpp
        ecs/EntityManager.cpp ecs/EntityManager.hpp
        ecs/System.hpp
        ecs/SystemManager.cpp ecs/SystemManager.hpp

        utils/FileUtils.hpp

        graphics/Graphics.hpp
        graphics/Shader.cpp graphics/Shader.hpp
        graphics/VertexBuffer.cpp graphics/VertexBuffer.hpp
        graphics/IndexBuffer.cpp graphics/IndexBuffer.hpp
        graphics/VertexArray.cpp graphics/VertexArray.hpp
        graphics/Vertex.hpp graphics/TexturedVertex.hpp
        graphics/SimpleRenderer.cpp graphics/SimpleRenderer.hpp
        graphics/VertexAttribute.cpp graphics/VertexAttribute.hpp
        graphics/VertexLayout.cpp graphics/VertexLayout.hpp
        graphics/Texture.cpp graphics/Texture.hpp
        graphics/Renderable.cpp graphics/Renderable.hpp
        graphics/Renderer.hpp graphics/FrameBuffer.cpp graphics/FrameBuffer.hpp)

add_library(REIKI_CORE ${REIKI_SOURCE_FILES})
# Include stb_image
target_include_directories(REIKI_CORE PUBLIC ${PROJECT_SOURCE_DIR}/libs/stb_image)
# Include GLFW
target_include_directories(REIKI_CORE PUBLIC ${GLFW_INCLUDE_DIRS})
# Include Glad
target_include_directories(REIKI_CORE PUBLIC ${PROJECT_SOURCE_DIR}/libs/GLAD)
# Link libraries
target_link_libraries(REIKI_CORE PUBLIC ${GLFW_LIBRARIES} GLAD)


## Main Executable
add_executable(${PROJECT_NAME} main.cpp)
# Added this so policy CMP0065 doesn't scream
set_target_properties(${PROJECT_NAME} PROPERTIES ENABLE_EXPORTS 0)
# Include src
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
# Link Libraries
target_link_libraries(${PROJECT_NAME} PUBLIC REIKI_CORE ${GLFW_LIBRARIES} GLAD)

#[[ Not sure if any of this is necessary?
# Include Opengl
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
]]
