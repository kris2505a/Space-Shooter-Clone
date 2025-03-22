#include "Player.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.hpp>


Player::Player(){
	if (!m_texture.loadFromFile("resources/player.png")) {
		throw std::runtime_error("Failed to load texture: " + m_path);
	}
	this->setTexture(m_texture);
	m_health = 0;
	m_ammo = 0;
	m_ammoDamage = 0;
	m_speed = 0.0f;
	this->setPosition({ 512, 384 });
}

void Player::update(float& deltaTime) {

}

void Player::handleInput(float& deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->rotate(-15);
}


Player::~Player() {

}
