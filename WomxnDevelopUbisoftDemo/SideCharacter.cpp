#include "stdafx.h"
#include "Game/SideCharacter.h"

SideCharacter::SideCharacter() //sets inital values for the side character
	:side_IsPlayingEndGame(false), sidePosition(800.0f, 500.0f)
{
	sideTexture.loadFromFile(".\\Assets\\blue_ball.bmp");

	const sf::Vector2f size(static_cast<float>(sideTexture.getSize().x), static_cast<float>(sideTexture.getSize().y));

	sideSprite.setTexture(sideTexture);
	sideSprite.setOrigin(size * 0.5f); //origin center of circle
	sideSprite.setPosition(sidePosition);

}

void SideCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sideSprite);
}

void SideCharacter::StartEndGame()
{
	side_IsPlayingEndGame = true;
}
