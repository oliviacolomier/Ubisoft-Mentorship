#include "stdafx.h"
#include "Platforms.h"

Platforms::Platforms()
	:side_IsPlayingEndGame(false), platform_position(800.0f, 400.0f)
{
	

    platform_texture.loadFromFile(".\\Assets\\grass_platform.png");
    const sf::Vector2f size(static_cast<float>(platform_texture.getSize().x), static_cast<float>(platform_texture.getSize().y));
    
    platform1.setTexture(platform_texture);
    platform1.setPosition(platform_position);
    platform1.setScale(sf::Vector2f(0.5f, 0.5f));
    platforms.push_back(platform1);

    SetBoundingBox(platform_position, size);
}

void Platforms::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(sideSprite);

    for (int i = 0; i < platforms.size(); i++)
    {
        target.draw(platforms[i]);
    }
    
   
}

void Platforms::StartEndGame()
{
	side_IsPlayingEndGame = true;
}
