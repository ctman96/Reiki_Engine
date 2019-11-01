//
// Created by Cody on 11/1/2019.
//

#include "VertexAttribute.hpp"

namespace Reiki::graphics {

    VertexAttribute::VertexAttribute(GLint size, GLuint count, GLenum type, GLboolean normalized, GLsizei stride)
            : m_size(size), m_count(count), m_type(type), m_normalized(normalized), m_stride(stride) {

    }
}