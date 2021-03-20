#include "stdafx.h"
#include "Platforms.h"

Platforms::Platforms()
	:side_IsPlayingEndGame(false), platform_position(800.0f, 400.0f)
{
	
    platform_texture.loadFromFile(".\\Assets\\grass_platform.png");
    platform1.setScale(sf::Vector2f(0.5f, 0.5f));
    const sf::Vector2f size(100.0f, 100.0f);
    platform1.setTexture(platform_texture);
    platform1.setOrigin(size * 0.5f);
    platform1.setPosition(platform_position);

    leftSide = platform1.getPosition().x;
    rightSide = platform1.getPosition().x + (platform1.getLocalBounds().width * 200);
    topSide = platform1.getPosition().y;

    platforms.push_back(platform1);
    SetBoundingBox(platform_position, size);
}

void Platforms::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for (int i = 0; i < platforms.size(); i++)
    {
        target.draw(platforms[i]);
    }
    
   
}

void Platforms::StartEndGame()
{
	side_IsPlayingEndGame = true;
}
