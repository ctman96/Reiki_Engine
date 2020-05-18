//! Abstract class representing a state of the game
/*!
 * This abstract class provides the base for GameStates,
 * the states used by the game engine state machine.
 *
 * @author: Cody Newman
 *
 * Created on: 5/18/2020
 */

#ifndef REIKI_GAMEENGINE_HPP
#define REIKI_GAMEENGINE_HPP

// TODO SDL_MIXER / AUDIO?

#include <map>
#include "Window.hpp"
#include "../ecs/ECS.hpp"
#include "../graphics/Graphics.hpp"
#include "GameState.hpp"
namespace Reiki::core {
    class GameState;

    class GameEngine {
    public:
        // Singleton
        static GameEngine &getInstance() {
            static GameEngine INSTANCE;
            return INSTANCE;
        }

        GameEngine(GameEngine const &) = delete;

        void operator=(GameEngine const &) = delete;
        //

        //! Initializes the GameEngine
        void init();

        //! Cleans up the GameEngine in preparation for deletion
        void terminate();

        //! Switches to a new state
        /*!
         * @param state pointer to the state to be switched to
         */
        void changeState(GameState *state);

        //! Updates the state
        void update(float ms);

        //! Renders the state
        void draw();

        //! Returns whether the engine is currently running
        bool isRunning() { return running; }

        //! Sets the engine to stop running, for breaking out of loop
        void quit() { running = false; }

        // Getters
        Window *getM_window() const;

        float getM_screen_scale() const;

        float getElapsed_ms() const;

        float getM_current_speed() const;

        void setM_current_speed(float m_current_speed);

        void toggleM_debug_mode();

        bool getM_debug_mode();

        Reiki::ECS::EntityManager *getEntityManager();

        Reiki::ECS::SystemManager *getSystemManager();

    private:
        GameEngine() = default; // private constructor

        //! Window handle
        Window *m_window{};

        //! Renderer handle
        Reiki::graphics::Renderer *m_renderer{};

        //! Screen to pixel coordinates scale factor
        float m_screen_scale{};

        //! The current loaded audio track
        //Mix_Music * music{};

        Reiki::ECS::EntityManager entityManager;
        Reiki::ECS::SystemManager systemManager;

        float m_current_speed = 1.f;
        bool m_debug_mode = false;

        float elapsed_ms{};

        bool running{};
        GameState *state{};

        bool changingState = false;
    };
}


#endif //REIKI_GAMEENGINE_HPP
