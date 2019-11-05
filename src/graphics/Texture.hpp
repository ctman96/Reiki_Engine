//
// Created by Cody on 11/2/2019.
//

#ifndef REIKI_TEXTURE_HPP
#define REIKI_TEXTURE_HPP

#include <glad/glad.h>
#include <string>


namespace Reiki::graphics {
    class Texture {
    private:
        std::string m_path;
        GLuint m_id;
        GLsizei m_width, m_height;
    public:
        Texture(GLsizei width, GLsizei height);
        explicit Texture(const char* path);
        ~Texture();

        void bind() const;
        void unbind() const;

        inline const GLuint getId() const { return m_id; };
        inline const GLsizei getWidth() const { return m_width; };
        inline const GLsizei getHeight() const { return m_height; };
    };
}


#endif //REIKI_TEXTURE_HPP
