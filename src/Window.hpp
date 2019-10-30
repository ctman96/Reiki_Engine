//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_WINDOW_HPP
#define REIKI_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

namespace Reiki {
    class Window {
    private:
        const char* m_title;
        int m_width;
        int m_height;
        GLFWwindow* m_window;
    public:
        Window(const char* title, int width, int height);

        ~Window();

        int shouldClose();

        void update();

        int getWidth() const { return m_width; }

        int getHeight() const { return m_height; }
    private:
        void resize(GLFWwindow* window, int width, int height);
    };
}


#endif //REIKI_WINDOW_HPP
