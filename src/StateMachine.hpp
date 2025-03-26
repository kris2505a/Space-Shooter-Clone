#pragma once
#include "State.hpp"
#include <stack>

class StateMachine {

private:
    std::stack <State*> m_states;

public:
    StateMachine ();
    ~StateMachine ();

    void render (sf::RenderWindow* window);
    void update (float& deltaTime);
    void handleInput (float& deltaTime);

    void pushState(State* state);
    void popState();

    State* getCurrentState() const;
};