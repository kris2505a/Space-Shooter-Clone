#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include <fstream>
#include <string>
#include <iostream>	


Game::Game() {
	this->initWindow();
	m_player = new Player(m_window);
}

Game::~Game() {
	delete m_window;
}

void Game::initWindow() {
	
	//TEMPORARY ASSIGNMENT OF WINDOW VARIABLES DIRECTLY
	m_width = 1024;
	m_height = 768;
	m_fps = 144;
	m_title = "Space Shooter";
	m_fullScreen = false;
	m_vSync = false;

	m_window = new sf::RenderWindow(
					{ m_width, m_height }, 
					m_title, 
					sf::Style::Close | (sf::Style::Fullscreen * m_fullScreen)
				);
}

void Game::render() {
	m_window->clear();
	
	if(!m_states.isEmpty()) {
		m_states.getCurrentState()->render(m_window);
	}
	
	m_window->display();
}

void Game::update() {
	//UPDATE DELTATIME
	m_deltaTime = m_dtClock.restart().asSeconds();

	//TODO: UPDATE ALL ENTITIES
	if(!m_states.isEmpty()) {
		m_states.getCurrentState()->update(m_deltaTime);
	}

}

void Game::handleInput() {
	//TODO: HANDLE INPUT OF ALL ENTITIES
	if(!m_states.isEmpty()) {
		m_states.getCurrentState()->handleInput(m_deltaTime);
	}
}

void Game::run() {


	sf::Event event;
	while (m_window->isOpen()) {
		
		while (m_window->pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				m_window->close();

		this->handleInput();
		this->update();
		this->render();
		
	}
}
