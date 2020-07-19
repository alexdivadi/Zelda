#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "EntityIdEnum.h"
#include "map.h"
#include "Window.h"

class Entity
{
protected:
	sf::Texture texture;
	sf::IntRect frame;
	sf::Sprite sprite;

	short width;
	short height;
	short id;
	//bool isOtherKeyFrame;	// I've noticed that just about everything but link and enemies that can face multiple directions only has 2 keyframes

protected:
	void setUpSprite();
	void setSpriteSheet(int id);
	virtual void updateSprite();

public:
	float x;
	float y;

public:
	virtual void tick(float elapsedTime, const Map &cmap);
	sf::Sprite getSprite();
	
	Entity();
};