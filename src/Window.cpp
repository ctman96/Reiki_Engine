//
// Created by Cody on 10/30/2019.
//

#include "Window.hpp"


Reiki::Window::Window(const char* title, int width, int height) : m_title(title), m_width(width), m_height(height) {
    m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
    if (!m_window) {
        throw std::runtime_error("Failed to create GLFW window!");
    }
    glfwMakeContextCurrent(m_window);

    // Set resize callback
    glfwSetWindowUserPointer(m_window, this);
    auto resize_redirect = [](GLFWwindow *window, int width, int height) { ((Window*)glfwGetWindowUserPointer(window))->resize(window, width, height); };
    glfwSetWindowSizeCallback(m_window, resize_redirect);
}

Reiki::Window::~Window() {
    glfwDestroyWindow(m_window);
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

