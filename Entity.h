#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "map.h"
#include "Window.h"

enum SpriteSheetRows
{
	Link,
	Octorok
};

class Entity
{
protected:
	sf::IntRect frame;
	sf::Texture texture;
	sf::Sprite sprite;

	int width;
	int height;

	short animationFrame { 0 };	// what frame of animation cycle X on sprite sheet
	short totalAnimationFrames { 0 };	// the total number of key frames a sprite has for each direction
	short spriteSheetIndex { 0 }; // what the sprite is Y on sprite sheet
	short spriteSheetXOffset { 0 }; // to identify x offset of entities and help with creature sprite finsing
	float currentAnimationDuration { 0. };
	float secondsPerAnimationUpdate { 0. };

protected:
	void getSpriteSheet(int spriteSheet);
	virtual void updateSprite();

public:
	float x;
	float y;

public:
	virtual void tick(float elapsedTime, const Map &cmap);
	sf::Sprite getSprite();
	
	Entity();
};