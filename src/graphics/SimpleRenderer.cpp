//
// Created by Cody on 11/1/2019.
//

#include "SimpleRenderer.hpp"

namespace Reiki::graphics {
    void SimpleRenderer::submit(const Renderable *renderable) {
        m_renderQueue.push_back(renderable);
    }

    void SimpleRenderer::render() {
        while(!m_renderQueue.empty()){
            const Renderable* renderable = m_renderQueue.front();
            renderable->getVertexArray()->bind();
            renderable->getIndexBuffer()->bind();

            const Shader* shader = renderable->getShader();
            shader->use();

            const Texture* texture = renderable->getTexture();
            texture->bind(); // TODO texcoords and textured renderable(sprite)

            math::mat3 transformation = math::mat3::Translation(renderable->getPosition())
                                        * math::mat3::Rotation(renderable->getRotation());
            //* math::mat3::Scale(renderable->getScale());

            shader->setUniformMat3("transform",transformation);
            shader->setUniformVec4("color",renderable->getColor());
            glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

            texture->unbind();
            renderable->getIndexBuffer()->unbind();
            renderable->getVertexArray()->unbind();

            m_renderQueue.pop_front();
        }
    }
}