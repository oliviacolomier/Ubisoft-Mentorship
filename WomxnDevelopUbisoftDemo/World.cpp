#include "stdafx.h"
#include "World.h"

World::World()
{
	world_texture.loadFromFile(".\\Assets\\background.bmp");
	const sf::Vector2f size(static_cast<float>(world_texture.getSize().x), static_cast<float>(world_texture.getSize().y));
	world_sprite.setTexture(world_texture);
	world_sprite.setOrigin(size * 0.5f);
	world_sprite.setPosition(sf::Vector2f(500.0f, 400.0f));
	world_sprite.setScale(sf::Vector2f(1.4f, 1.4f));
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(world_sprite);
}

