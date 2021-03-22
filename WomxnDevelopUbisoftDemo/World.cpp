#include "stdafx.h"
#include "Game/World.h"

World::World()
{
	world_texture1.loadFromFile(".\\Assets\\background.bmp");
	const sf::Vector2f size(static_cast<float>(world_texture1.getSize().x), static_cast<float>(world_texture1.getSize().y));
	world_sprite1.setTexture(world_texture1);
	world_sprite1.setOrigin(size * 0.5f);
	world_sprite1.setPosition(sf::Vector2f(500.0f, 400.0f));
	world_sprite1.setScale(sf::Vector2f(1.4f, 1.4f));

	world_texture2.loadFromFile(".\\Assets\\background.bmp");
	world_sprite2.setOrigin(size * 0.5f);
	world_sprite2.setPosition(sf::Vector2f(300.0f, 500.0f));
	world_sprite2.setScale(sf::Vector2f(1.4f, 1.4f));

	box_texture.loadFromFile(".\\Assets\\box.bmp");
	rect.setTexture(box_texture);
	rect.setOrigin(700.0f, 800.0f);
	rect.setPosition(500.0f, 800.0f);
	rect.setScale(sf::Vector2f(0.4f, 0.4f));
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	
	target.draw(world_sprite1);
	target.draw(world_sprite2);
	//target.draw(rect);
}

