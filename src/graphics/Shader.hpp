/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#ifndef REIKI_SHADER_HPP
#define REIKI_SHADER_HPP

#include <glad/glad.h>
#include <vector>
#include <iostream>
#include "../math/Math.hpp"
#include "../utils/FileUtils.hpp"

namespace Reiki::graphics {
    class Shader {
    private:
        GLuint m_program;

    public:
        Shader(const char* vs_path, const char* fs_path);
        ~Shader();

        void use() const;
        void clear() const;

        GLint getUniformLocation(const GLchar* name) const;
        void setUniformFloat(const GLchar* name, float val) const;
        void setUniformInt(const GLchar* name, int val) const;
        void setUniformVec2(const GLchar* name, const math::vec2& vec) const;
        void setUniformVec3(const GLchar* name, const math::vec3& vec) const;
        void setUniformVec4(const GLchar* name, const math::vec4& vec) const;
        void setUniformMat3(const GLchar* name, const math::mat3& mat) const;


        GLint getAttributeLocation(const GLchar* name) const;
    };
}


#endif //REIKI_SHADER_HPP
