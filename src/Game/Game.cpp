#include "Game/Game.hpp"
#include <SFML/Window/Event.hpp>
#include "Engine/Entity.hpp"

Game::Game() {
	this->initWindow();

	float x{ 0 }, y{ 0 };
	for (int i = 0; i < 1024 ; i++) {
		m_tiles.push_back(new Tile(sf::Vector2f(x, y), m_window));
		y += 32;
		if (y >= 1024) {
			x += 32;
			y = 0;
		}
	}
	
	this->run();
}

Game::~Game() {
	delete m_window;
}

void Game::initWindow() {
	
	//TEMPORARY ASSIGNMENT OF WINDOW VARIABLES DIRECTLY
	m_width = 1280;
	m_height = 720;
	m_fps = 144;
	m_title = "Tower Shooter";
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
	
	for (auto* iter : m_tiles) {
		iter->render();
	}

	m_window->display();
}

void Game::update() {
	//UPDATE DELTATIME
	m_deltaTime = m_dtClock.restart().asSeconds();

	//TODO: UPDATE ALL ENTITIES
}

void Game::handleInput() {
	//TODO: HANDLE INPUT OF ALL ENTITIES
}

void Game::run() {


	sf::Event event;
	while (m_window->isOpen()) {
		
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		this->handleInput();
		this->update();
		this->render();
		
	}
}