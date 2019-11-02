/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#ifndef REIKI_BUFFER_HPP
#define REIKI_BUFFER_HPP

#include <glad/glad.h>
#include "VertexLayout.hpp"
#include "TexturedVertex.hpp"

namespace Reiki::graphics {
    class VertexBuffer {
    private:
        GLuint m_id;
        VertexLayout m_layout;
    public:
        VertexBuffer(const GLfloat * data, GLsizei size);
        VertexBuffer(const Vertex * data, GLsizei size);
        VertexBuffer(const TexturedVertex* data, GLsizei size);

        void setLayout(const VertexLayout &layout);

        void bind() const;
        void unbind() const;
    };
}


#endif //REIKI_BUFFER_HPP
