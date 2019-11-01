/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#include "IndexBuffer.hpp"

namespace Reiki::graphics {
    IndexBuffer::IndexBuffer(const GLuint *data, GLuint count) : m_count(count) {
        glGenBuffers(1, &m_id);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * count, data, GL_STATIC_DRAW);
        unbind();
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void IndexBuffer::unbind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}