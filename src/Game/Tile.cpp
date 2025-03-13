#include "Tile.hpp"
#include <stdio.h>

Tile::Tile(sf::Vector2f& pos, unsigned int type) {
	m_type = type;

	switch (m_type) {
	case 1:
		m_path = "resources/tiles/grass.png";
		break;
	case 2:
		m_path = "resources/tiles/wood.png";
		break;
	case 3:
		m_path = "resources/tiles/water.png";
		break;
	}

	m_texture.loadFromFile(m_path);
	this->setTexture(m_texture);
	this->setPosition(pos);
}

Tile::~Tile() {

}

