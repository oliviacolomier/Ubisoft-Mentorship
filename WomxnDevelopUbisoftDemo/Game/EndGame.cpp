#include "stdafx.h"
#include "Game/EndGame.h"

EndGame::EndGame()
{
	m_Font.loadFromFile(".\\Assets\\CaviarDreams.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(150.0f, 250.0f);
	m_Text.setCharacterSize(50.0f);
	m_Text.setString("You finished the game!");
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);

}

void EndGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Text);
}
