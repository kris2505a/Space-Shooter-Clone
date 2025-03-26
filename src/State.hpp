#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class State {

private:
    bool m_endState;
    bool m_pauseState;
public:
    State() : m_endState(false) { }
    virtual ~State() { }

    virtual void render (sf::RenderWindow* targetWindow) { }
    virtual void update (const float& deltaTime) { }
    virtual void handleInput (const float& deltaTime) { }

    inline const bool endState() { return m_endState; }
    inline const bool pauseState() { return m_pauseState; }

};