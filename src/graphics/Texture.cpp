//
// Created by Cody on 11/2/2019.
//

#include <stdexcept>
#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Reiki::graphics {
    Texture::Texture(GLsizei width, GLsizei height)
            : m_width(width), m_height(height) {

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    }

    Texture::Texture(const char *path) {
        if (path == nullptr) {
            std::string error =  "Unable to load texture: ";
            error.append(path);
            throw std::runtime_error(error);
        }
        m_path = std::string(path);

        stbi_uc* data = stbi_load(path, &m_width, &m_height, NULL, 4);
//        if (data == NULL)
//            return false;

        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        stbi_image_free(data);
    }

    Texture::~Texture() {
        if (m_id != 0) glDeleteTextures(1, &m_id);
    }

    void Texture::bind() const {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_id);
    }

    void Texture::unbind() const {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}