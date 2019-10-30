//
// Created by Cody on 10/30/2019.
//

#include "Window.hpp"

namespace
{
    // glfw error callback fn
    void glfw_error(int error, const char* desc)
    {
        fprintf(stderr, "%d: %s", error, desc);
    }

    // openGl Debug Callback fn
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

Reiki::Window::Window(const char* title, int width, int height) : m_title(title), m_width(width), m_height(height) {
    glfwSetErrorCallback(glfw_error);

    if(!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (!m_window) {
        throw std::runtime_error("Failed to create GLFW window!");
    }
    glfwMakeContextCurrent(m_window);

    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD!");
    }
    printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);

    // Set resize callback
    glfwSetWindowUserPointer(m_window, this);
    auto resize_redirect = [](GLFWwindow *window, int width, int height) { ((Window*)glfwGetWindowUserPointer(window))->resize(window, width, height); };
    glfwSetWindowSizeCallback(m_window, resize_redirect);

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(
            GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true
    );
}

Reiki::Window::~Window() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Reiki::Window::update() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

int Reiki::Window::shouldClose() {
    return glfwWindowShouldClose(m_window);
}

void Reiki::Window::resize(GLFWwindow *window, int width, int height) {
    glViewport(0,0, width, height);
    m_width = width;
    m_height = height;
}

