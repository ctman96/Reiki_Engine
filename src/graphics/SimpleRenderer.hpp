//
// Created by Cody on 11/1/2019.
//

#ifndef REIKI_SIMPLERENDERER_HPP
#define REIKI_SIMPLERENDERER_HPP

#include <deque>
#include "Renderer.hpp"
#include "../math/Math.hpp"
#include "FrameBuffer.hpp"

namespace Reiki::graphics {
    class SimpleRenderer : public Renderer {
    private:
        std::deque<const Renderable*> m_renderQueue;
        FrameBuffer* m_frameBuffer;
        math::vec2 m_size;
    public:
        explicit SimpleRenderer(const math::vec2 &size);
        ~SimpleRenderer();

        void submit(const Renderable* renderable) override;
        void render() override;
    private:
        void render(const Renderable* renderable);
    };
}

#endif //REIKI_SIMPLERENDERER_HPP
