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
    void APIENTRY openglCallbackFunction(
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
    // Initialize keys/buttons to false
    for (bool &m_key : m_keys)
        m_key = false;
    for (bool &m_button : m_buttons)
        m_button = false;
    m_mouse = {0.0, 0.0};

    glfwSetErrorCallback(glfw_error);

    if(!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW!");

    m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
    if (!m_window) {
        throw std::runtime_error("Failed to create GLFW window!");
    }

    glfwMakeContextCurrent(m_window);

    // Set GLFW window Callbacks
    glfwSetWindowUserPointer(m_window, this);

    // Set resize callback
    auto resize_redirect = [](GLFWwindow *window, int width, int height) { ((Window*)glfwGetWindowUserPointer(window))->resize(window, width, height); };
    glfwSetWindowSizeCallback(m_window, resize_redirect);

    // Set key callback
    auto key_redirect = [](GLFWwindow* wnd, int _0, int _1, int _2, int _3) { ((Window*)glfwGetWindowUserPointer(wnd))->key_callback(wnd, _0, _1, _2, _3); };
    glfwSetKeyCallback(m_window, key_redirect);

    // Set mouse callbacks
    auto cursor_pos_redirect = [](GLFWwindow* wnd, double _0, double _1) { ((Window*)glfwGetWindowUserPointer(wnd))->cursor_position_callback(wnd, _0, _1); };
    glfwSetCursorPosCallback(m_window, cursor_pos_redirect);
    auto mouse_button_redirect = [](GLFWwindow* wnd, int _0, int _1, int _2) { ((Window*)glfwGetWindowUserPointer(wnd))->mouse_button_callback(wnd, _0, _1, _2); };
    glfwSetMouseButtonCallback(m_window, mouse_button_redirect);

    // TODO scroll callback?

    // Load GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD!");
    }
    printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, true);
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

void Reiki::Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    switch(action){
        case GLFW_RELEASE:
            m_keys[key] = false;
            break;
        case GLFW_PRESS:
        case GLFW_REPEAT:
            m_keys[key] = true;
            break;
        default:break;
    }
}

void Reiki::Window::cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
    m_mouse.x = xpos;
    m_mouse.y = ypos;
}

void Reiki::Window::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    switch(action){
        case GLFW_RELEASE:
            m_buttons[button] = false;
            break;
        case GLFW_PRESS:
        case GLFW_REPEAT:
            m_buttons[button] = true;
            break;
        default:break;
    }
}

bool Reiki::Window::isKeyPressed(int key) const{
    if (key >= KEY_MAX)
        return false;
    return m_keys[key];
}

bool Reiki::Window::isButtonPressed(int button) const {
    if (button >= BUTTON_MAX)
        return false;
    return m_buttons[button];
}

Reiki::pos<double> Reiki::Window::getMousePosition() const{
    return m_mouse;
}

