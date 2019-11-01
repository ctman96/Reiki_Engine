//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_VERTEXLAYOUT_HPP
#define REIKI_VERTEXLAYOUT_HPP

#include <glad/glad.h>
#include <vector>
#include "VertexAttribute.hpp"
#include "Vertex.hpp"

namespace Reiki::graphics {
    class VertexLayout {
    private:
        std::vector<VertexAttribute> m_layout;
        GLsizei m_size;

        void addAttribute(GLsizei size, GLuint count, GLenum type, GLboolean normalized);
    public:
        VertexLayout();

        void addFloat(GLuint count, GLboolean normalized) {
            addAttribute(sizeof(float), count, GL_FLOAT, normalized);
        }

        void addVec2(GLboolean normalized) {
            addFloat(2, normalized);
        }
        void addVec3(GLboolean normalized) {
            addFloat(3, normalized);
        }
        void addVec4(GLboolean normalized) {
            addFloat(4, normalized);
        }

        void addVertex(GLboolean normalized) {
            addVec3(normalized);
            addVec4(normalized);
            //addAttribute(sizeof(Vertex), 3, GL_FLOAT, normalized);
            //addAttribute(sizeof(Vertex), 4, GL_FLOAT, normalized);
        }
        void addTexturedVertex(GLboolean normalized) {
            addVec3(normalized);
            addVec2(normalized);
        }

        void enable() const;
    };
}


#endif //REIKI_VERTEXLAYOUT_HPP
