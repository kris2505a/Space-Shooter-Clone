#include "Tile.hpp"
#include <stdio.h>

Tile::Tile(sf::Vector2f& pos, sf::RenderWindow* target) {
	p_window = target;
	m_texture.loadFromFile("resources/tiles/grass.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos);
}

Tile::~Tile() {

}

void Tile::render() {
	p_window->draw(m_sprite);
}
