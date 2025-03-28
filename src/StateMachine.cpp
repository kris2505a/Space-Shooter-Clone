#include "StateMachine.hpp"

StateMachine::StateMachine () {

}

StateMachine::~StateMachine () {
    while (!m_states.empty()) {
        delete m_states.top();
        m_states.pop();
    }
}

void StateMachine::render (sf::RenderWindow* window) {
    m_states.top()->render(window);
}

void StateMachine::update(float& deltaTime) {
    m_states.top()->update(deltaTime);
}

void StateMachine::handleInput(float& deltaTime) {
    m_states.top()->handleInput(deltaTime);
}

void StateMachine::pushState(State* state) {
    m_states.push(state);
}

void StateMachine::popState() {
    
    auto currentState = this->getCurrentState();
    m_states.pop();
    delete currentState;

}

