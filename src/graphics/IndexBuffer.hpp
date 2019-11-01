/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#ifndef REIKI_INDEXBUFFER_HPP
#define REIKI_INDEXBUFFER_HPP

#include <glad/glad.h>

namespace Reiki::graphics {
    class IndexBuffer {
    private:
        GLuint m_id;
        GLuint m_count;
    public:
        IndexBuffer(const GLuint * data, GLuint count);

        void bind() const;
        void unbind() const;

        inline GLuint getCount() const { return m_count; };
    };
}


#endif //REIKI_INDEXBUFFER_HPP
