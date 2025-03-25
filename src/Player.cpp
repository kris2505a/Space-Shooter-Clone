#include "Player.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <math.h>


Player::Player(const sf::RenderWindow* window) : p_targetWindow(window) {
	if (!m_texture.loadFromFile("resources/player.png")) {
		throw std::runtime_error("Failed to load texture: " + m_path);
	}
	this->setTexture(m_texture);
	m_health = 0;
	m_ammo = 0;
	m_ammoDamage = 0;
	m_speed = 800.0f;
	this->setPosition({ 512, 384 });
	this->setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

void Player::update(float& deltaTime) {

}

void Player::handleInput(float& deltaTime) {

	this->rotatePlayer(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->movePlayer(-1, 0, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->movePlayer(1, 0, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
		this->movePlayer(0, -1, deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->movePlayer(0, 1, deltaTime);
}

void Player::movePlayer(int x, int y, float& deltaTime) {
	sf::Vector2f deltaPos = this->getPosition();
	deltaPos += {x * m_speed * deltaTime, y * m_speed * deltaTime};
	this->setPosition(deltaPos);
}

void Player::rotatePlayer(float& deltaTime) {
	auto mousePos = sf::Mouse::getPosition(*p_targetWindow);
	sf::Vector2f deltaPos = this->getPosition() - sf::Vector2f(mousePos);
	int angle = std::atan2(deltaPos.x, deltaPos.y) * 180 / 3.141592f;
	this->rotate(angle);
	printf("%d\n", angle);
}

Player::~Player() {

}
