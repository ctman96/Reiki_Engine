//
// Created by Cody on 11/1/2019.
//

#include "VertexLayout.hpp"

namespace Reiki::graphics {

    VertexLayout::VertexLayout() {
        m_size = 0;
    }

    void VertexLayout::addAttribute(GLsizei size, GLuint count, GLenum type, GLboolean normalized) {
        m_layout.emplace_back(VertexAttribute{size, count, type, normalized, m_size});
        m_size += sizeof(float) * count;
    }

    void VertexLayout::enable() const {
        for (GLuint i = 0; i < m_layout.size(); i++) {
            const VertexAttribute& attr = m_layout[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, attr.m_count, attr.m_type, attr.m_normalized, m_size, (const void*)attr.m_stride);
        }
    }
}