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

            math::mat3 transformation = math::mat3::Translation(renderable->getPosition())
                                        * math::mat3::Rotation(renderable->getRotation());
            //* math::mat3::Scale(renderable->getScale());

            renderable->getShader().setUniformMat3("transform",transformation);
            renderable->getShader().setUniformVec4("color",renderable->getColor());
            glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);

            renderable->getIndexBuffer()->unbind();
            renderable->getVertexArray()->unbind();

            m_renderQueue.pop_front();
        }
    }
}