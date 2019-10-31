//
// Created by Cody on 10/31/2019.
//

#ifndef REIKI_SHADER_HPP
#define REIKI_SHADER_HPP

#include <glad/glad.h>
#include <vector>
#include <iostream>
#include "../math/math.hpp"
#include "../utils/FileUtils.hpp"

namespace Reiki::graphics {
    class Shader {
    private:
        GLuint m_program;

    public:
        Shader(const char* vs_path, const char* fs_path);
        ~Shader();

        void use() const;
        static void clear();

        GLint getUniformLocation(const GLchar* name);
        void setUniformFloat(const GLchar* name, float val);
        void setUniformInt(const GLchar* name, int val);
        void setUniformVec2(const GLchar* name, const math::vec2& vec);
        void setUniformVec3(const GLchar* name, const math::vec3& vec);
        void setUniformVec4(const GLchar* name, const math::vec4& vec);
        void setUniformMat3(const GLchar* name, const math::mat3& mat);
    };
}


#endif //REIKI_SHADER_HPP
