#pragma once

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include "map.h"
#include "Player.h"
#include "TileMap.h"

class Game
{
private:
	sf::RenderWindow window{ sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!" };
	sf::Clock clock;
	sf::Time elapsedTime;

	std::vector<Entity*> entities;

	Player player{ entities, 16, 16, true, 0, 0.2f, 2};	//entity vector, width, height, link, entity id, keyframeduration, numkeyframes
	Map cmap;
	TileMap background;

	int fps = 0;
	float frame_counter = 0;
   
private:
	void getInput(float elapsedTime);

public:
	int GameLoop();
};