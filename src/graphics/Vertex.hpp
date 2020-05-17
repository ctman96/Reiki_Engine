//
// Created by Cody on 10/31/2019.
//

#ifndef REIKI_VERTEX_HPP
#define REIKI_VERTEX_HPP

#include "../math/Math.hpp"

namespace Reiki::graphics {
    class Vertex {
    private:
        math::vec3 m_position;
        math::vec4 m_color;
    public:
        Vertex(const math::vec3& position, const math::vec4& color) : m_position(position), m_color(color) {}

        const math::vec3 &getPosition() const { return m_position; }
        const math::vec4 &getColor() const { return m_color; }
    };
}


#endif //REIKI_VERTEX_HPP
