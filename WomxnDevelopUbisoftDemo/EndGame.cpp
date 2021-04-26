#include "stdafx.h"
#include "Game/EndGame.h"

EndGame::EndGame()
{
	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(50.0f, 250.0f);
	m_Text.setCharacterSize(50.0f);
	m_Text.setString("You finished the game!");
	m_Text.setFillColor(sf::Color::Red);
	m_Text.setStyle(sf::Text::Bold);

	if(!m_Buffer.loadFromFile(".\\Assets\\deathsound.ogg"))
	{
		printf("Error loading sound");
	}

	m_DeathSound.setBuffer(m_Buffer);
}

void EndGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Text);
}

void EndGame::playDeathSound()
{
	m_DeathSound.play();

}
