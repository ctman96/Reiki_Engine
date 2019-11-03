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
#include "Texture.hpp"


namespace Reiki::graphics {
    // TODO should maybe be a component later
    class Renderable {
    protected:
        math::vec2 m_position;
        math::vec2 m_scale;
        float m_rotation;
        math::vec4 m_color;

        Shader* m_shader;
        Texture* m_texture;
        VertexArray* m_vertexArray;
        IndexBuffer* m_indexBuffer;

        Renderable();
    public:
        Renderable(math::vec2 position, math::vec2 scale, float rotation, math::vec4 color, Shader* shader);
        Renderable(const math::vec2 &position, const math::vec2 &scale, float rotation, const math::vec4 &color, Texture *texture, Shader *shader);

        virtual ~Renderable();

        inline const VertexArray* getVertexArray() const { return m_vertexArray; }
        inline const IndexBuffer* getIndexBuffer() const { return m_indexBuffer; }
        inline const Shader* getShader() const { return m_shader; };
        inline const Texture* getTexture() const { return m_texture; };

        inline const math::vec2 &getPosition() const { return m_position; }
        inline void setPosition(math::vec2 position) { m_position = position;};

        inline const math::vec2 &getScale() const { return m_scale; }
        inline void setScale(math::vec2 scale) { m_scale = scale; };

        inline float getRotation() const { return m_rotation; };
        inline void setRotation(float rotation) { m_rotation = rotation; };

        inline const math::vec4 &getColor() const { return m_color; }
        inline void setColor(math::vec4 color) { m_color = color; };
    };
}

#endif //REIKI_RENDERABLE_HPP
