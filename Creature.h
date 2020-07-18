#pragma once

#include "Entity.h"

class Creature : public Entity
{
public:
	bool isMoving{ false };
	bool isPerformingAction{ false };
	bool aFlagUsed { true }; // rename to has finished attack or something
	
public:
	void performAction(float elapsedTime);	// should take in a bool for what button is pressed, A or B

protected:
	float xVel{ 0 };
	float yVel{ 0 };
	short direction{ 0 };

	int health{ 1 };
	int speed{ 80 };

	float attackAnimationFrameIndex{ 0 };
	float attackDuration{ .2 };	// in sec
	float attackCooldown{ .2 };	// also in sec

protected:
	int getDirection();
	void updatePosition(float elapsedTime, const Map& cmap);
	void checkCollision(Map cmap, float elapsedTime);
	void updateSprite();

	Creature() : Entity() {}
};
