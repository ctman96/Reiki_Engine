/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#include "VertexBuffer.hpp"

namespace Reiki::graphics {
    VertexBuffer::VertexBuffer(const GLfloat *data, GLsizei size, GLsizei components): m_components(components) {
        glGenBuffers(1, &m_id);
        bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * size, data, GL_STATIC_DRAW);
        unbind();
    }

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}