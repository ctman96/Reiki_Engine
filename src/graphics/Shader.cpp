/*!
 * @author: Cody Newman
 *
 * Created on 10/31/2019.
 */

#include "Shader.hpp"

namespace Reiki::graphics {

    Shader::Shader(const char *vs_path, const char *fs_path) {
        // Read sources
        std::string vs_str = read_file(vs_path);
        std::string fs_str = read_file(fs_path);

        const char* vs_src = vs_str.c_str();
        const char* fs_src = fs_str.c_str();

        auto vs_len = (GLsizei)vs_str.size();
        auto fs_len = (GLsizei)fs_str.size();

        // Create shaders
        m_program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vs_src, &vs_len);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fs_src, &fs_len);

        // Compiling
        // Shaders already delete if compilation fails
        glCompileShader(vertex);
        GLint vresult;
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &vresult);
        if (vresult == GL_FALSE) {
            GLint length;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(vertex, length, &length, &error[0]);
            std::cout << "Vertex shader comilation failed: " << &error[0] << std::endl;
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            m_program = 0;
            return;
        }

        glCompileShader(fragment);
        GLint fresult;
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &fresult);
        if (fresult == GL_FALSE) {
            GLint length;
            glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(fragment, length, &length, &error[0]);
            std::cout << "Fragment shader comilation failed: " << &error[0] << std::endl;
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            m_program = 0;
            return;
        }

        // Linking
        glAttachShader(m_program, vertex);
        glAttachShader(m_program, fragment);

        glLinkProgram(m_program);
        glValidateProgram(m_program);

        // Cleanup
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    Shader::~Shader() {
        glDeleteProgram(m_program);
    }

    void Shader::use() const {
        glUseProgram(m_program);
    }

    void Shader::clear() const{
        glUseProgram(0);
    }

    GLint Shader::getUniformLocation(const GLchar *name) const{
        return glGetUniformLocation(m_program, name);
    }

    void Shader::setUniformFloat(const GLchar *name, float val) const{
        glUniform1f(getUniformLocation(name), val);
    }

    void Shader::setUniformInt(const GLchar *name, int val) const{
        glUniform1i(getUniformLocation(name), val);
    }

    void Shader::setUniformVec2(const GLchar *name, const math::vec2 &vec) const{
        glUniform2f(getUniformLocation(name), vec.x, vec.y);
    }

    void Shader::setUniformVec3(const GLchar *name, const math::vec3 &vec) const{
        glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z);
    }

    void Shader::setUniformVec4(const GLchar *name, const math::vec4 &vec) const{
        glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
    }

    void Shader::setUniformMat3(const GLchar *name, const math::mat3 &mat) const{
        glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, (float*)&mat);
    }

    GLint Shader::getAttributeLocation(const GLchar *name) const{
        return glGetAttribLocation(m_program, name);
    }
}