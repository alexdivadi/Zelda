#pragma once

#include "Creature.h"

class Player : public Creature
{
public:
	bool upFlag{}, downFlag{}, leftFlag{}, rightFlag{}, aFlag{};
	void tick(float elapsedTime, const Map& cmap) override;

	Player(std::vector<Entity*>& e);
	Player() {};
};
