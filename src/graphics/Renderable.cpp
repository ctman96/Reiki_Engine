//
// Created by Cody on 11/2/2019.
//

#include "Renderable.hpp"

namespace Reiki::graphics {
    Renderable::Renderable() : m_texture(nullptr){

    }

    Renderable::Renderable(math::vec2 position, math::vec2 size, float rotation, math::vec4 color, Shader *shader)
            : m_position(position), m_scale({1,1}), m_rotation(rotation), m_color(color), m_texture(nullptr), m_shader(shader) {
        m_vertexArray = new VertexArray();

        float w = size.x;
        float h = size.y;

        GLfloat vertices[] = {
                0,0,0,
                0,size.y,0,
                size.x, size.y,0,
                size.x,0,0
        };
        GLfloat colors[] = {
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
        };

        Vertex vertices1[] = {
                {{0,0,0}, {color.x, color.y, color.z, color.w}},
                {{0,h,0}, {color.x, color.y, color.z, color.w}},
                {{w,h,0}, {color.x, color.y, color.z, color.w}},
                {{w,0,0}, {color.x, color.y, color.z, color.w}},
        };

        VertexLayout layout;
        layout.addVertex(GL_FALSE);

        auto *vbo = new VertexBuffer(vertices1, 4);
        m_vertexArray->bind();
        vbo->bind();
        vbo->setLayout(layout);
        vbo->unbind();
        m_vertexArray->unbind();
        //m_vertexArray->addBuffer(vbo,0); TODO idk what I'm doing with this

        //m_vertexArray->addBuffer(new VertexBuffer(vertices, 4*3,3),0);
        //m_vertexArray->addBuffer(new VertexBuffer(vertices, 4*4,4),1);

        GLuint indices[] = {0,1,2,2,3,0};
        m_indexBuffer = new IndexBuffer(indices, 6);
    }

    Renderable::Renderable(const math::vec2 &position, const math::vec2 &scale, float rotation, const math::vec4 &color, Texture *texture, Shader *shader)
            : m_position(position), m_scale({1,1}), m_rotation(rotation), m_color(color), m_shader(shader) {

        m_vertexArray = new VertexArray();

        float w = texture->getWidth() * 0.5f;
        float h = texture->getHeight() * 0.5f;

        TexturedVertex vertices[] = {
                {{-w,+h,0}, {0,1}},
                {{+w,+h,0}, {1,1}},
                {{+w,-h,0}, {1,0}},
                {{-w,-h,0}, {0,0}},
        };

        VertexLayout layout;
        layout.addTexturedVertex(GL_FALSE);

        auto *vbo = new VertexBuffer(vertices, 4);
        m_vertexArray->bind();
        vbo->bind();
        vbo->setLayout(layout);
        vbo->unbind();
        m_vertexArray->unbind();
        //m_vertexArray->addBuffer(vbo,0); TODO idk what I'm doing with this

        GLuint indices[] = {0,1,2,2,3,0};
        m_indexBuffer = new IndexBuffer(indices, 6);
    }

    // TODO Split renderable into subclasses. Do a sprite/spritesheet subclass using similar code to vape

    Renderable::~Renderable() {
            delete m_vertexArray;
            delete m_indexBuffer;
    }
}