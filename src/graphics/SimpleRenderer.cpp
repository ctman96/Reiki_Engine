//
// Created by Cody on 11/1/2019.
//

#include "SimpleRenderer.hpp"

namespace Reiki::graphics {
    SimpleRenderer::SimpleRenderer(const math::vec2 &size) : m_size(m_size) {
        //m_frameBuffer = new FrameBuffer(static_cast<GLsizei>(size.x), static_cast<GLsizei>(size.y));
    }

    SimpleRenderer::~SimpleRenderer() {
        //delete m_frameBuffer;
    }

    void SimpleRenderer::submit(const Renderable *renderable) {
        m_renderQueue.push_back(renderable);
    }


    void SimpleRenderer::render() {
        // TODO: generate new framebuffer if screen size changes?
        //m_frameBuffer->bind();
        //m_frameBuffer->clear();

        while(!m_renderQueue.empty()){
            const Renderable* renderable = m_renderQueue.front();

            render(renderable);

            m_renderQueue.pop_front();
        }
        //glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //m_frameBuffer->bindTexture();
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        //m_frameBuffer->unbindTexture();
        //m_frameBuffer->unbind();
    }


    void SimpleRenderer::render(const Renderable *renderable) {
        renderable->getVertexArray()->bind();
        renderable->getIndexBuffer()->bind();

        const Texture* texture = renderable->getTexture();
        if (texture != nullptr)
            texture->bind();

        const Shader* shader = renderable->getShader();
        shader->use();

        math::mat3 transformation = math::mat3::Translation(renderable->getPosition())
                                    * math::mat3::Rotation(renderable->getRotation())
                                    * math::mat3::Scale(renderable->getScale());


        shader->setUniformMat3("projection", math::mat3::Orthographic(0.f, 800.f, 600.f, 0.f ));
        shader->setUniformMat3("transform",transformation);
        shader->setUniformVec4("color",renderable->getColor());
        glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

        shader->clear();
        if (texture != nullptr)
            texture->unbind();
        renderable->getIndexBuffer()->unbind();
        renderable->getVertexArray()->unbind();
    }
}