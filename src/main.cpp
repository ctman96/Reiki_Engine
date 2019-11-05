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
    Shader shader1(shader_path("test_textured.vs.glsl"), shader_path("test_textured.fs.glsl"));
    //shader.use();
    //shader.setUniformMat3("transform", mat3::Translation(vec2(4,3)));
    //shader.setUniformMat3("projection", mat3::Orthographic(0.f, 16.f, 0.f, 9.f));
    //shader.setUniformVec4("color", vec4(0.2f,0.3f,0.8f,1.f));

    Texture t1(texture_path("turtle.png"));
    Texture t2(texture_path("fish.png"));

    Renderable sprite({5.f,5.f}, {40.f,40.f}, 0.f, {1,0,1,1}, &shader);
    Renderable sprite2({100.f,200.f}, {1,1}, 0.f, {1,1,1,1}, &t2, &shader1);
    SimpleRenderer renderer(vec2(window.getWidth(), window.getHeight()));

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "A PRESSED" << std::endl;
            std::cout << window.getWidth() <<","<< window.getHeight() << std::endl;
        }
        if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "LMB PRESSED: " << window.getMousePosition().x << "," << window.getMousePosition().y << std::endl;
        }
        // sprite2.setPosition(sprite2.getPosition() + vec2(0.5,0.f));
        // sprite2.setRotation(sprite2.getRotation() + 0.001f);
        // sprite2.setScale(sprite2.getScale() + vec2(0.001,0));
        // sprite2.setColor(sprite2.getColor() + vec4(0.0001,0,0,0));

        renderer.submit(&sprite);
        renderer.submit(&sprite2);
        renderer.render();

        window.update();
    }

    return 0;
}