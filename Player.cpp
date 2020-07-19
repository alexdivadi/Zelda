#include "Player.h"

Player::Player(std::vector<Entity*>& e, short w, short h, bool l, short i, float s, short a)
{
	width = w;
	height = h;
	isLink = l;
	id = i;
	secondsPerAnimationUpdate = s;
	totalAnimationFrames = a;

	setUpSprite();

	e.push_back(this);
}

void Player::updateSprite()
{
	int xOffset;

	// This conditional makes is so that if something is performing an action, it ensures it displays it's attacking key frame
	if (isPerformingAction && isLink)
		xOffset = totalAnimationFrames;
	else
		xOffset = animationFrame;

	sf::IntRect frame((((direction * (totalAnimationFrames + isLink)) + xOffset) * width), 0, width, height);	// (x,y,width,height)
	sprite.setTextureRect(frame);
}

void Player::tick(float elapsedTime, const Map& cmap)
{
	if ((aFlag && aFlagUsed == false) || isPerformingAction) // makes it so link cant walk while attacking, and holds his attacks for the right ammount of time
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