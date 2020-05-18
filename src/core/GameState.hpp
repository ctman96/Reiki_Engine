//
// Created by Cody on 5/18/2020.
//

#ifndef REIKI_GAMESTATE_HPP
#define REIKI_GAMESTATE_HPP

namespace Reiki::core {
    class GameState {
    public:
        //! Initializes the state
        virtual void init() = 0;

        //! Cleans up the state
        virtual void terminate() = 0;

        //! Updates the state
        virtual void update(float ms) = 0;

        //! Renders the state
        virtual void draw() = 0;

        //! Default destructor
        virtual ~GameState() = default;
    };
}

#endif //REIKI_GAMESTATE_HPP
