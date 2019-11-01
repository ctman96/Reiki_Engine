/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#include "VertexArray.hpp"

namespace Reiki::graphics {

    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_id);
    }

    VertexArray::~VertexArray() {
        // delete buffers?
    }

    void VertexArray::addBuffer(VertexBuffer *buffer, GLuint index) {
        // TODO change this whole thing
        bind();
        buffer->bind();
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, GL_FALSE, 0,0);

        buffer->unbind();
        unbind();
        m_buffers.push_back(buffer);
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_id);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }
}