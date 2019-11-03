//
// Created by Cody on 11/2/2019.
//

#include "FrameBuffer.hpp"

namespace Reiki::graphics {
    FrameBuffer::FrameBuffer(GLsizei width, GLsizei height)
            : m_width(width), m_height(height) {
        m_clear = math::vec4(0,0,0,1);
        glGenFramebuffers(1, &m_frameBufferId);
        glGenRenderbuffers(1, &m_depthBufferId);

        glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);
        glBindRenderbuffer(GL_RENDERBUFFER, m_depthBufferId);

        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBufferId);

        m_texture = new Texture(width, height);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture->getId(), 0);

        // Set the list of draw buffers TODO is this necessary? Copied from 427 template,
        GLenum draw_buffers[1] = {GL_COLOR_ATTACHMENT0};
        glDrawBuffers(1, draw_buffers); // "1" is the size of DrawBuffers

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            throw std::runtime_error("Failed to create Framebuffer");
        }
    }

    FrameBuffer::~FrameBuffer() {
        if (m_frameBufferId != 0) glDeleteFramebuffers(1, &m_frameBufferId);
    }


    void FrameBuffer::bind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, m_frameBufferId);
        glViewport(0, 0, m_width, m_height);
        glDepthRange(0.00001, 10);// TODO depth?
    }

    void FrameBuffer::unbind() const {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void FrameBuffer::clear() const {
        glClearColor(m_clear.x, m_clear.y, m_clear.z, m_clear.w);
        glClearDepth(1.f);// todo depth?
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}