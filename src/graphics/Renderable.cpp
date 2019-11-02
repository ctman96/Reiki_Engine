//
// Created by Cody on 11/2/2019.
//

#include "Renderable.hpp"

namespace Reiki::graphics {

    Renderable::Renderable(math::vec2 position, math::vec2 size, float rotation, math::vec4 color, Texture* texture, Shader *shader)
            : m_position(position), m_scale({1,1}), m_rotation(rotation), m_color(color), m_texture(texture), m_shader(shader) {
        m_vertexArray = new VertexArray();

        float w = size.x;
        float h = size.y;
        if (texture != nullptr) {
                w = texture->getWidth();
                h = texture->getHeight();
        }

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
        vbo->setLayout(layout);
        m_vertexArray->addBuffer(vbo,0);

        //m_vertexArray->addBuffer(new VertexBuffer(vertices, 4*3,3),0);
        //m_vertexArray->addBuffer(new VertexBuffer(vertices, 4*4,4),1);

        GLuint indices[] = {0,1,2,2,3,0};
        m_indexBuffer = new IndexBuffer(indices, 6);
    }

    Renderable::~Renderable() {
            delete m_vertexArray;
            delete m_indexBuffer;
    }
}