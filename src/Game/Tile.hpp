#pragma once
#include <SFML/Graphics.hpp>


class Tile {

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::RenderTarget* p_window;

public:
	Tile() {}
	Tile(sf::Vector2f& pos, sf::RenderWindow* target);
	~Tile();
	void render();
};