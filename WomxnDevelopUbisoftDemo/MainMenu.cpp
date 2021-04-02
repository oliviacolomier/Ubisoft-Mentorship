#include "stdafx.h"
#include "Game/MainMenu.h"

MainMenu::MainMenu()
{

	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");

	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	menuBackground.setTexture(m_Texture);

	m_Text.setFont(m_Font);
	m_Text.setPosition(225.0f, 250.0f);
	m_Text.setCharacterSize(50.0f);
	m_Text.setString("Press 'P' to Play");
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(menuBackground);
	target.draw(m_Text);
	
}
