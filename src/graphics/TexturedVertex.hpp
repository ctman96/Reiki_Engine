//
// Created by Cody on 10/31/2019.
//

#ifndef REIKI_TEXTUREDVERTEX_HPP
#define REIKI_TEXTUREDVERTEX_HPP


#include "../math/Math.hpp"

namespace Reiki::graphics {
    class TexturedVertex {
    private:
        math::vec3 m_position;
        math::vec2 m_texcoord;
    public:
        TexturedVertex(const math::vec3& position, const math::vec2& texcoord): m_position(position), m_texcoord(texcoord) {};

        const math::vec3 &getPosition() const { return m_position; }
        const math::vec2 &getTexcoord() const { return m_texcoord; }
    };
}


#endif //REIKI_TEXTUREDVERTEX_HPP
