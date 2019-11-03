//
// Created by Cody on 11/2/2019.
//

#ifndef REIKI_FRAMEBUFFER_HPP
#define REIKI_FRAMEBUFFER_HPP

#include <glad/glad.h>
#include "../math/math.hpp"
#include "Texture.hpp"

namespace Reiki::graphics {
    class FrameBuffer {
    private:
        GLuint m_frameBufferId;
        GLuint m_depthBufferId;
        GLsizei m_width, m_height;
        Texture* m_texture;
        math::vec4 m_clear;
    public:
        FrameBuffer(GLsizei width, GLsizei height);
        ~FrameBuffer();

        void bind() const;

        void unbind() const;

        void bindTexture() const { m_texture->bind(); } // TODO should this just be part of bind?

        void unbindTexture() const { m_texture->unbind(); };

        void clear() const;

        void setColor(const math::vec4 &color) { m_clear = color; };
    };
}


#endif //REIKI_FRAMEBUFFER_HPP
