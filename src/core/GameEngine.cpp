//! The state machine which handles running and swapping game states
/*!
 * The GameEngine class is a basic state machine designed to run
 * the different GameStates that make up the game.
 *
 * @author: Cody Newman
 *
 * Created on: 5/18/2020
 */

#include "GameEngine.hpp"

/*!
 * Initialize the game engine, setting up the Window
 */
void Reiki::core::GameEngine::init() {
    // TODO Window

    m_current_speed = 1.f;

    running = true;
}

/*!
 * Cleans up the engine, terminating the running state, deleting any allocated objects
 */
void Reiki::core::GameEngine::terminate() {
    // Clean up the current state
    if (state != nullptr){
        state->terminate();
    }
    delete(state);
    state = nullptr;

    delete(m_renderer);
    m_renderer = nullptr;

    delete(m_window);
    m_window = nullptr;
}

/*!
 * Terminates the current state and replaces it with the
 * provided GameState
 * @param state the new GameState to be swapped in
 */
void Reiki::core::GameEngine::changeState(GameState *state) {
    changingState = true;
    if (this->state != nullptr) {
        this->state->terminate();
        delete (this->state);
    }
    this->state = state;
    state->init();
    changingState = false;
}

/*!
 * Runs the state's update function
 */
void Reiki::core::GameEngine::update(float ms) {
    entityManager.update(ms * m_current_speed);
    systemManager.update(ms * m_current_speed);
    this->elapsed_ms = ms;
    state->update(ms * m_current_speed);

    if (m_window->shouldClose()) {
        this->running = false;
    }
}

/*!
 * Runs the state's render function
 */
void Reiki::core::GameEngine::draw() {
    //entityManager.draw(...);
    //systemManager.draw(...);
    state->draw();
    m_renderer->render();
    m_window->update();
}

float Reiki::core::GameEngine::getElapsed_ms() const {
    return elapsed_ms;
}

Reiki::core::Window *Reiki::core::GameEngine::getM_window() const {
    return m_window;
}

float Reiki::core::GameEngine::getM_screen_scale() const {
    return m_screen_scale;
}

float Reiki::core::GameEngine::getM_current_speed() const {
    return m_current_speed;
}

void Reiki::core::GameEngine::setM_current_speed(float m_current_speed) {
    Reiki::core::GameEngine::m_current_speed = m_current_speed;
}

void Reiki::core::GameEngine::toggleM_debug_mode() {
    Reiki::core::GameEngine::m_debug_mode = !Reiki::core::GameEngine::m_debug_mode;
}

bool Reiki::core::GameEngine::getM_debug_mode() {
    return Reiki::core::GameEngine::m_debug_mode;
}

Reiki::ECS::EntityManager *Reiki::core::GameEngine::getEntityManager() {
    return &entityManager;
}
Reiki::ECS::SystemManager *Reiki::core::GameEngine::getSystemManager() {
    return &systemManager;
}
