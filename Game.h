#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>

#include "map.h"
#include "TileMap.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow window{ sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!" };
	sf::Clock clock;
	sf::Time elapsedTime;

	std::vector<Entity*> entities;

	Player player{ entities };
	Map cmap;
	TileMap background;

	int fps = 0;
	float frame_counter = 0.0;
   
private:
	void getInput(float elapsedTime);

public:
	int GameLoop();
};

