#pragma once
#include "Player.hpp"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>


class Game {

private:
	
	//WINDOW MEMBERS
	unsigned int m_width, m_height, m_fps;
	std::string m_title;
	bool m_fullScreen;
	bool m_vSync;
	sf::RenderWindow* m_window;
	
	//DELTATIME ELEMENTS
	float m_deltaTime;
	sf::Clock m_dtClock;


	//INIT FUNCTIONS
	void initWindow();

	//GAME FUNCTIONS
	void render();
	void update();
	void handleInput();


	Player* m_player;
	

public:
	Game();
	~Game();
	void run();

};