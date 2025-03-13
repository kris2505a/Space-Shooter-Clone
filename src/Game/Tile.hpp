#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Tile : public sf::Sprite {

private:
	sf::Texture m_texture;
	unsigned int m_type;
	std::string m_path;


public:
	Tile(sf::Vector2f& pos, unsigned int tileType);
	~Tile();
};

/*
1 - GRASS
2 - WOOD
3 - WATER
*/