/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#ifndef REIKI_VERTEXARRAY_HPP
#define REIKI_VERTEXARRAY_HPP

#include <glad/glad.h>
#include <vector>
#include "VertexBuffer.hpp"

namespace Reiki::graphics {
    class VertexArray {
    private:
        GLuint m_id;
        std::vector<VertexBuffer*> m_buffers;
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(VertexBuffer* buffer, GLuint index);

        void bind() const;
        void unbind() const;
    };
}


#endif //REIKI_VERTEXARRAY_HPP
