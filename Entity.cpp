#include "Entity.h"

Entity::Entity()
{

}

void Entity::setUpSprite()
{
	setSpriteSheet(id);	// Opens specific png file and set's texture to that image
	sprite.setTexture(texture);
	sprite.setOrigin(width / 2.0f, height / 2.0f);
	sprite.setPosition(x, y);

	updateSprite();
}

sf::Sprite Entity::getSprite()
{
	return sprite;
}

void Entity::setSpriteSheet(int id)	// set's texture to specified png
{
	switch (id)
	{
	case(0):
		texture.loadFromFile("Sprites/link.png");
		break;
	case(1):
		texture.loadFromFile("Sprites/octorok.png");
		break;
	default:
		texture.loadFromFile("Sprites/tiles.png");
	}
}

void Entity::tick(float elapsedTime, const Map& cmap) { }

void Entity::updateSprite() { }