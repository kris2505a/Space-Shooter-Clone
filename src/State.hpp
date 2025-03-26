#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class State {

private:
    bool m_endState;
    bool m_pauseState;
    sf::CircleShape circle;

public:
    State() : m_endState(false) { circle.setRadius(50.f); }
    virtual ~State() { }

    virtual void render (sf::RenderWindow* targetWindow) { targetWindow->draw(circle); }
    virtual void update (const float& deltaTime) { }
    virtual void handleInput (const float& deltaTime) { }

    inline const bool endState() { return m_endState; }
    inline const bool pauseState() { return m_pauseState; }

};