#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <graphics/VertexArray.hpp>
#include <graphics/IndexBuffer.hpp>


#include "core/Window.hpp"
#include "math/math.hpp"
#include "graphics/Shader.hpp"
#include "utils/FileUtils.hpp"


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


    // Old
    /*GLfloat vertices[] = {
            0,0,0,
            8,0,0,
            0,3,0,
            0,3,0,
            8,3,0,
            8,0,0,
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);*/

    // New
    GLfloat vertices[] = {
            0,0,0,
            8,0,0,
            8,3,0,
            0,3,0,
    };
    GLuint indices[] = {
            0,1,2,
            2,3,0
    };
    VertexArray vao;
    auto *vbo = new VertexBuffer(vertices,12, 3);
    IndexBuffer ibo(indices, 6);

    vao.addBuffer(vbo, 0);

    Shader shader(shader_path("test.vs.glsl"), shader_path("test.fs.glsl"));
    shader.use();
    shader.setUniformMat3("transform", mat3::Translation(vec2(4,3)));
    shader.setUniformMat3("projection", mat3::Orthographic(0.f, 16.f, 0.f, 9.f));
    shader.setUniformVec4("color", vec4(0.2f,0.3f,0.8f,1.f));

    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (window.isKeyPressed(GLFW_KEY_A)) {
            std::cout << "A PRESSED" << std::endl;
            std::cout << window.getWidth() <<","<< window.getHeight() << std::endl;
        }
        if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
            std::cout << "LMB PRESSED: " << window.getMousePosition().x << "," << window.getMousePosition().y << std::endl;
        }

        // Old
        //glDrawArrays(GL_TRIANGLES, 0, 6);

        // New
        vao.bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);
        ibo.unbind();
        vao.unbind();


        window.update();
    }

    return 0;
}