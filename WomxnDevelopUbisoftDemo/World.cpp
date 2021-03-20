#include "stdafx.h"
#include "World.h"


World::World(MainCharacter* character):m_mainCharacter(*character)
{
	backgroundImage.loadFromFile(".\\Assets\\background_forest.bmp");
	const sf::Vector2f size(static_cast<float>(backgroundImage.getSize().x), static_cast<float>(backgroundImage.getSize().y));
	background.setTexture(backgroundImage);
	background.setOrigin(size * 0.5f);
	background.setPosition(sf::Vector2f(500.0f, 400.0f));
	background.setScale(sf::Vector2f(1.4f, 1.4f));

	onPlatform = sf::Vector2f(0.0f, 0.0f);


}

void World::CreatePlatform() // sf::Vector2f position, sf::Vector2f size)
{
	
	sf::Sprite platform1;
	sf::Sprite platform2;
	sf::Sprite platform3;
	sf::Sprite platform4;

	m_platforms.push_back(platform1);
	m_platforms.push_back(platform2);
	m_platforms.push_back(platform3);
	m_platforms.push_back(platform4);

	sf::Vector2f size = sf::Vector2f(100.0f, 100.0f);
	sf::Vector2f position = sf::Vector2f(500.0f, 300.0f);

	sprite_texture.loadFromFile(".\\Assets\\grass_platform.png");
	

	for (int i = 0; i < m_platforms.size(); i++)
	{
		m_platforms[i].setTexture(sprite_texture);
		m_platforms[i].setScale(0.5f, 0.5f);
		m_platforms[i].setOrigin(size * 0.5f);
		m_platforms[i].setPosition(position);
		position.x += 100;
		position.y += 100;
	}


}

void World::collide(MainCharacter* character, Platforms platform)
{

	if (character->IsColliding(platform))
	{
		printf("Yes");
		player_box = character->GetBoundingBox();
		platform_box = platform.GetBoundingBox();

		player_position = character->GetPosition();
		platform_position = platform.GetPosition();

		


	}
	


}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{


	target.draw(background);

	for (int i = 0; i < m_platforms.size(); i++)
	{
		target.draw(m_platforms[i]);
	}
	

	
}

void World::setGroundHeight(float groundHeight)
{
	groundHeight = groundHeight;
}

float World::getGroundHeight()
{
	return groundHeight;
}
