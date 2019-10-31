//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_WINDOW_HPP
#define REIKI_WINDOW_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <stdexcept>
#include <iostream>

namespace Reiki {
    #define KEY_MAX 512
    #define BUTTON_MAX 16

    template <typename T> struct pos { T x, y; };

    class Window {
    private:
        const char* m_title;
        int m_width;
        int m_height;
        GLFWwindow* m_window;

        bool m_keys[KEY_MAX];
        bool m_buttons[BUTTON_MAX];

        pos<double> m_mouse;

    public:
        Window(const char* title, int width, int height);

        ~Window();

        int shouldClose();

        void update();

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        bool isKeyPressed(int key) const;
        bool isButtonPressed(int button) const;
        pos<double> getMousePosition() const;
    private:
        void resize(GLFWwindow* window, int width, int height);
        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };
}


#endif //REIKI_WINDOW_HPP
