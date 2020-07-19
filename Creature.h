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

	short animationFrame{ 0 };	// what frame of animation cycle X on sprite sheet
	short totalAnimationFrames;	// the total number of key frames a sprite has for each direction
	//short spriteSheetIndex{ 0 }; // what the sprite is Y on sprite sheet
	//short spriteSheetXOffset{ 0 }; // to identify x offset of entities and help with creature sprite finsing
	float currentAnimationDuration{ 0.0f };
	float secondsPerAnimationUpdate;

	float xVel{ 0 };
	float yVel{ 0 };
	short direction{ 0 };

	int health{ 1 };
	int speed{ 80 };

	float attackAnimationFrameIndex{ 0 };
	float attackDuration{ 0.25f };	// in sec
	float attackCooldown{ 0.25f };	// also in sec

protected:
	int getDirection();
	void updatePosition(float elapsedTime, const Map& cmap);
	void checkCollision(Map cmap, float elapsedTime);
	void updateSprite();

	Creature() : Entity() {}
};
