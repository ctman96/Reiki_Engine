//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_SIMPLERENDERER_HPP
#define REIKI_SIMPLERENDERER_HPP

#include <deque>
#include "Renderer.hpp"
#include "../math/math.hpp"

namespace Reiki::graphics {
    class SimpleRenderer : public Renderer {
    private:
        std::deque<const Renderable*> m_renderQueue;
    public:
        void submit(const Renderable* renderable);
        void render();
    };
}

#endif //REIKI_SIMPLERENDERER_HPP
