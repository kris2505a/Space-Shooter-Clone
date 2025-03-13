#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdio.h>


class Entity : public sf::Sprite {
private:
	sf::Texture m_texture;
	std::string m_path;

public:
	Entity(std::string path) : m_path(path) {
		if (!m_texture.loadFromFile(path))
			printf("Unable to load texture\n");
		this->setTexture(m_texture);
	}

	virtual void update(float& deltaTime) { }
	virtual void handleInput(float& deltaTime) { }
};