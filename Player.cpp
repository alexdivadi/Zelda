
#include "Player.h"

Player::Player(std::vector<Entity*>& e)
{
	// Defining sprite size
	width = 16.0f;
	height = 16.0f;

	// Setting SFML sprite up
	getSpriteSheet(Link);	// Opens specific png file and set's texture to that image
	sprite.setTexture(texture);
	sprite.setOrigin(width / 2.0f, height / 2.0f);
	sprite.setPosition(x, y);

	secondsPerAnimationUpdate = 0.10f;
	totalAnimationFrames = 2;
	updateSprite();

	e.push_back(this);
}

void Player::tick(float elapsedTime, const Map& cmap)
{
	if ((aFlag && aFlagUsed == false) || isPerformingAction) 
	{
		performAction(elapsedTime);
	}

	else if (isPerformingAction == false) // Cant move while doing action
	{
		if (downFlag) { yVel = 1; xVel = 0; } // South
		else if (upFlag) { yVel = -1; xVel = 0; } // North
		else if (leftFlag) { xVel = -1; yVel = 0; } // East
		else if (rightFlag) { xVel = 1; yVel = 0; } // West
		else { xVel = 0; yVel = 0; } // Idle

		if (rightFlag && leftFlag) { xVel = 0; }
		if (upFlag && downFlag) { yVel = 0; }

		if (getDirection() != -1)
			direction = getDirection();

		updatePosition(elapsedTime, cmap);
	}

}