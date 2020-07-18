
#include "Creature.h"

void Creature::performAction(float elapsedTime)
{
	attackAnimationFrameIndex += elapsedTime;

	if (attackAnimationFrameIndex > attackCooldown + attackDuration)
		attackAnimationFrameIndex = attackCooldown + attackDuration;

	if (isPerformingAction == false)
	{
		isPerformingAction = true;
		updateSprite();
	}
	else
	{
		if (attackAnimationFrameIndex > attackDuration)
		{	
			aFlagUsed = true;
			isPerformingAction = false;
			attackAnimationFrameIndex = 0;
			updateSprite();
		}
	}

}

void Creature::updateSprite()
{
	int xOffset;

	// This conditional makes is so that if something is performing an action, it ensures it displays it's attacking key frame
	if (isPerformingAction)
		xOffset = totalAnimationFrames;
	else
		xOffset = animationFrame;

	sf::IntRect frame((((direction * 3) + xOffset) * 16), spriteSheetIndex, width, height);
	sprite.setTextureRect(frame);
}

void Creature::updatePosition(float elapsedTime, const Map& cmap)
{
	checkCollision(cmap, elapsedTime);

	y += yVel * elapsedTime * speed;
	x += xVel * elapsedTime * speed;

	//static_cast<int>(x);
	//static_cast<int>(y);

	sprite.setPosition(x, y);

	if (xVel || yVel)
	{
		currentAnimationDuration += elapsedTime;
		if (currentAnimationDuration > secondsPerAnimationUpdate)
		{
			animationFrame = (animationFrame + 1) % totalAnimationFrames;
			currentAnimationDuration = 0;
		}
		updateSprite();
	}
}

int Creature::getDirection()
{
	if (yVel == 1) return 0;	// South / Down
	else if (yVel == -1) return 1;	// North / Up
	else if (xVel == -1) return 2;	// West / Left
	else if (xVel == 1) return 3;	// East / Right
	else return -1;
}

/* HITBOX:
_________________
| <----80%----> |
|               |
|   ^   o       |
|50%|           |
____V___________|
*/

void Creature::checkCollision(Map cmap, float elapsedTime) {
	float new_y = y + yVel * elapsedTime * speed;
	float new_x = x + xVel * elapsedTime * speed;

	if (xVel <= 0) {

		if (cmap.GetSolid(new_x / 16 - 0.4f, y / 16) || cmap.GetSolid(new_x / 16 - 0.4f, y / 16 + 0.5f)) {
			xVel = 0;
		}
	}
	else {
		if (cmap.GetSolid(new_x / 16 + 0.4f, y / 16) || cmap.GetSolid(new_x / 16 + 0.4f, y / 16 + 0.5f)) {
			xVel = 0;
		}
	}
	if (yVel <= 0) {
		if (cmap.GetSolid(x / 16 + 0.4f, new_y / 16) || cmap.GetSolid(x / 16 - 0.4f, new_y / 16)) {
			yVel = 0;
		}
	}
	else {
		if (cmap.GetSolid(x / 16 + 0.4f, new_y / 16 + 0.5f) || cmap.GetSolid(x / 16 - 0.4f, new_y / 16 + 0.5f)) {
			yVel = 0;
		}
	}
}
