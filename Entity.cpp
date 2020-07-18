#include "Entity.h"

Entity::Entity()
{
	x = WINDOW_WIDTH / 2;
	y = WINDOW_HEIGHT / 3;
	width = 0;
	height = 0;
}

sf::Sprite Entity::getSprite()
{
	return sprite;
}

void Entity::getSpriteSheet(int spriteSheet)
{
	switch (spriteSheet)
	{
	case(0):
		texture.loadFromFile("Sprites/link.png");
		break;
	default:
		texture.loadFromFile("Sprites/link.png");
		break;
	}
}

void Entity::tick(float elapsedTime, const Map& cmap)
{
	currentAnimationDuration += elapsedTime;
	if (currentAnimationDuration > secondsPerAnimationUpdate)
	{
		animationFrame = (animationFrame + 1) % totalAnimationFrames;
		currentAnimationDuration = 0;
	}
	updateSprite();
}

void Entity::updateSprite()
{
	sf::IntRect frame((animationFrame * 16), spriteSheetIndex, width, height);
	sprite.setTextureRect(frame);
}