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

    //INLINE FUNCTIONS
    inline State* getCurrentState() const { return m_states.top(); }
    inline bool isEmpty() const { return m_states.empty(); }
    inline bool shouldEnd() const { return m_states.top()->endState(); }
    inline bool shouldPause() const { return m_states.top()->pauseState(); }
};