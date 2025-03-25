#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Player : public sf::Sprite {

private:

	const sf::RenderWindow* p_targetWindow;

	sf::Texture m_texture;
	std::string m_path;
	float m_speed;
	unsigned int m_health;
	unsigned int m_ammo;
	unsigned int m_ammoDamage;

	void movePlayer(int x, int y, float& deltaTime);
	void rotatePlayer(float& deltaTime);
	void limitPlayer();

public:
	Player(const sf::RenderWindow* window);
	~Player();

	void update(float& deltaTime);
	void handleInput(float& deltaTime);
};