#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <graphics/VertexArray.hpp>
#include <graphics/IndexBuffer.hpp>


#include "core/Window.hpp"
#include "math/math.hpp"
#include "graphics/Shader.hpp"
#include "utils/FileUtils.hpp"
#include "graphics/Renderable.hpp"
#include "graphics/SimpleRenderer.hpp"
#include "ecs/ECS.hpp"



int main() {
    using namespace Reiki;
    using namespace core;
    using namespace math;
    using namespace graphics;

    Window window("Test", 800, 600);

    glClearColor(0.5f,0.5f,0.5f,0.f);

    vec4 a(1.f, 2.f, 3.f, 4.f);

    vec4 b(100.f,200.f, 300.f, 400.f);

    vec4 c = a + b;
    std::cout << a << b << c << std::endl;

    Shader shader(shader_path("test.vs.glsl"), shader_path("test.fs.glsl"));
    shader.use();
    //shader.setUniformMat3("transform", mat3::Translation(vec2(4,3)));
    shader.setUniformMat3("projection", mat3::Orthographic(0.f, 16.f, 0.f, 9.f));
    //shader.setUniformVec4("color", vec4(0.2f,0.3f,0.8f,1.f));

    Renderable sprite({5.f,5.f}, {4.f,4.f}, 0.f, {1,0,1,1}, shader);
    Renderable sprite2({7.f,1.f}, {2.f,3.f}, 0.f, {0.2f,0,1,1}, shader);
    SimpleRenderer renderer;

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "A PRESSED" << std::endl;
            std::cout << window.getWidth() <<","<< window.getHeight() << std::endl;
        }
        if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "LMB PRESSED: " << window.getMousePosition().x << "," << window.getMousePosition().y << std::endl;
        }

        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.render();

        window.update();
    }

    return 0;
}