//#include <gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/Window.hpp"

namespace
{
    void glfw_error(int error, const char* desc)
    {
        fprintf(stderr, "%d: %s", error, desc);
    }
}

int main() {
    using namespace Reiki;
    glfwSetErrorCallback(glfw_error);

    if(!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    Window window("Test", 800, 600);

    //if (!gl3wInit())
    //    throw std::runtime_error("Failed to initialize GL3W");

    glClearColor(0.5f,0.5f,0.5f,0.f);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.update();
    }

    glfwTerminate();
    return 0;
}