//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_VERTEXATTRIBUTE_HPP
#define REIKI_VERTEXATTRIBUTE_HPP

#include <glad/glad.h>

namespace Reiki::graphics {
    // TODO just include this in VertexLayout? struct?
    class VertexAttribute {
        friend class VertexLayout;
    private:
        GLint m_size;
        GLuint m_count;
        GLenum m_type;
        GLboolean m_normalized;
        GLsizei m_stride;
    public:
        VertexAttribute(GLint size, GLuint count, GLenum type, GLboolean normalized, GLsizei stride);
    };
}


#endif //REIKI_VERTEXATTRIBUTE_HPP
