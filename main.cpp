#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "src/Window.hpp"

namespace
{
    void glfw_error(int error, const char* desc)
    {
        fprintf(stderr, "%d: %s", error, desc);
    }

    // openGl Debug Callback
    static void APIENTRY openglCallbackFunction(
            GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar* message,
            const void* userParam
    ){
        (void)source; (void)type; (void)id;
        (void)severity; (void)length; (void)userParam;
        fprintf(stderr, "%s\n", message);
        if (severity==GL_DEBUG_SEVERITY_HIGH) {
            fprintf(stderr, "Aborting...\n");
            abort();
        }
    }
}

int main() {
    using namespace Reiki;
    glfwSetErrorCallback(glfw_error);

    if(!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    Window window("Test", 800, 600);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD!");
    }
    printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(
            GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true
    );

    glClearColor(0.5f,0.5f,0.5f,0.f);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.update();
    }

    glfwTerminate();
    return 0;
}