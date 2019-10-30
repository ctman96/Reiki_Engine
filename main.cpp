#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "src/Window.hpp"




int main() {
    using namespace Reiki;

    Window window("Test", 800, 600);

    glClearColor(0.5f,0.5f,0.5f,0.f);

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.update();
    }

    return 0;
}