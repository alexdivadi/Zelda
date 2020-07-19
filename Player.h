#pragma once

#include "Creature.h"

class Player : public Creature
{
private:
	bool isLink;

private:
	void updateSprite();

public:
	bool upFlag{}, downFlag{}, leftFlag{}, rightFlag{}, aFlag{};

public:
	void tick(float elapsedTime, const Map& cmap);

	Player(std::vector<Entity*>& e, short w, short h, bool l, short i, float s, short a);
};
