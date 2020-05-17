//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_RENDERER_HPP
#define REIKI_RENDERER_HPP

#include <deque>
#include "Renderable.hpp"
#include "../math/Math.hpp"

namespace Reiki::graphics {
    class Renderer {
    public:
        virtual void submit(const Renderable* renderable) = 0;
        virtual void render() = 0;
    };
}


#endif //REIKI_RENDERER_HPP
