#include "stdafx.h"
#include "Game/MainMenu.h"

MainMenu::MainMenu()
{

	m_font.loadFromFile(".\\Assets\\BunnyBaby.otf");

	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	menuBackground.setTexture(m_Texture);

	m_text.setFont(m_font);
	m_text.setPosition(225.0f, 250.0f);
	m_text.setCharacterSize(50.0f);
	m_text.setString("Press 'P' to Play");
	m_text.setFillColor(sf::Color::Black);
	m_text.setStyle(sf::Text::Bold);

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(menuBackground);
	target.draw(m_text);
	
}
