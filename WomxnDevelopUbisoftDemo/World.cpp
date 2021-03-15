#include "stdafx.h"
#include "World.h"

World::World()
{
	backgroundImage.loadFromFile(".\\Assets\\background_forest.bmp");
	const sf::Vector2f size(static_cast<float>(backgroundImage.getSize().x), static_cast<float>(backgroundImage.getSize().y));
	background.setTexture(backgroundImage);
	background.setOrigin(size * 0.5f);
	background.setPosition(sf::Vector2f(500.0f, 400.0f));
	background.setScale(sf::Vector2f(1.4f, 1.4f));
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
}
