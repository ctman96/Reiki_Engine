#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


#include "core/Window.hpp"
#include "math/vec4.hpp"


int main() {
    using namespace Reiki;
    using namespace core;
    using namespace math;

    Window window("Test", 800, 600);

    glClearColor(0.5f,0.5f,0.5f,0.f);

    vec4 a(1.f, 2.f, 3.f, 4.f);

    vec4 b(100.f,200.f, 300.f, 400.f);

    vec4 c = a + b;

    std::cout << a << b << c << std::endl;

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "A PRESSED" << std::endl;
            std::cout << window.getWidth() <<","<< window.getHeight() << std::endl;
        }
        if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "LMB PRESSED: " << window.getMousePosition().x << "," << window.getMousePosition().y << std::endl;
        }
        window.update();
    }

    return 0;
}