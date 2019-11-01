/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#ifndef REIKI_BUFFER_HPP
#define REIKI_BUFFER_HPP

#include <glad/glad.h>

namespace Reiki::graphics {
    class VertexBuffer {
    private:
        GLuint m_id;
        GLsizei m_components;
    public:
        VertexBuffer(const GLfloat * data, GLsizei size, GLsizei count);

        inline GLsizei getCount() const { return m_components; };

        void bind() const;
        void unbind() const;
    };
}


#endif //REIKI_BUFFER_HPP
