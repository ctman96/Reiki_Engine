//
// Created by Cody on 11/2/2019.
//

#ifndef REIKI_FRAMEBUFFER_HPP
#define REIKI_FRAMEBUFFER_HPP

#include <glad/glad.h>
#include "../math/Math.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Renderable.hpp"

namespace Reiki::graphics {
    class FrameBuffer {
    private:
        GLuint m_frameBufferId;
        GLuint m_depthBufferId;
        GLsizei m_width, m_height;
        math::vec4 m_clear;

        Shader* m_shader;
        Texture* m_texture;
        VertexArray* m_vao;
        IndexBuffer* m_ibo;
    public:
        FrameBuffer(GLsizei width, GLsizei height);
        ~FrameBuffer();

        void bind() const;

        void unbind() const;

        void clear() const;

        void setColor(const math::vec4 &color) { m_clear = color; };

        void bindTexture() const;
        void unbindTexture() const;
    };
}


#endif //REIKI_FRAMEBUFFER_HPP
