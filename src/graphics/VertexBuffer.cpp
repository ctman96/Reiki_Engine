/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#include "VertexBuffer.hpp"

namespace Reiki::graphics {
    VertexBuffer::VertexBuffer(const GLfloat *data, GLsizei size) {
        glGenBuffers(1, &m_id);
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * size, data, GL_STATIC_DRAW);
        unbind();
    }

    VertexBuffer::VertexBuffer(const Vertex *data, GLsizei size) {
        glGenBuffers(1, &m_id);
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, data, GL_STATIC_DRAW);
        unbind();
    }

    void VertexBuffer::setLayout(const VertexLayout &layout) {
        m_layout = layout;
        m_layout.enable();
    };

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        m_layout.enable();
    }

    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}