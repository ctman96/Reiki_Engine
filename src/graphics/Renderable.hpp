//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_RENDERABLE_HPP
#define REIKI_RENDERABLE_HPP

#include <glad/glad.h>
#include "../math/math.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"


namespace Reiki::graphics {
    // TODO should maybe be a component later
    class Renderable {
    protected:
        math::vec2 m_position;
        math::vec2 m_scale;
        float m_rotation;
        math::vec4 m_color;

        Shader& m_shader;
        VertexArray* m_vertexArray;
        IndexBuffer* m_indexBuffer;

    public:
        Renderable(math::vec2 position, math::vec2 scale, float rotation, math::vec4 color, Shader& shader)
                : m_position(position), m_scale(scale), m_rotation(rotation), m_color(color), m_shader(shader) {
            m_vertexArray = new VertexArray();
            GLfloat vertices[] = {
                    0,0,0,
                    0,scale.y,0,
                    scale.x, scale.y,0,
                    scale.x,0,0
            };
            GLfloat colors[] = {
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
                color.x, color.y, color.z, color.w,
            };

            Vertex vertices1[] = {
                    {{0,0,0}, {color.x, color.y, color.z, color.w}},
                    {{0,scale.y,0}, {color.x, color.y, color.z, color.w}},
                    {{scale.x, scale.y,0}, {color.x, color.y, color.z, color.w}},
                    {{scale.x,0,0}, {color.x, color.y, color.z, color.w}},
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

        virtual ~Renderable() {
            delete m_vertexArray;
            delete m_indexBuffer;
        }

        inline const VertexArray* getVertexArray() const { return m_vertexArray; }
        inline const IndexBuffer* getIndexBuffer() const { return m_indexBuffer; }
        inline Shader& getShader() const { return m_shader; };

        inline const math::vec2 &getPosition() const { return m_position; }

        inline const math::vec2 &getScale() const { return m_scale; }

        inline float getRotation() const { return m_rotation; }

        inline const math::vec4 &getColor() const { return m_color; }
    };
}

#endif //REIKI_RENDERABLE_HPP
