#include "stdafx.h"
#include "Game/InstructionMenu.h"

InstructionMenu::InstructionMenu()
{
	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");
	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	m_Background.setTexture(m_Texture);
	m_Background.setScale(0.6f, 0.6f);

	m_Text.setFont(m_Font);
	m_Text.setPosition(200.0f, 250.0f);
	m_Text.setCharacterSize(30.0f);
	m_Text.setString("Use 'A' 'W' 'S' 'D' to control the character");
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);
}

void InstructionMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(m_Background);
	target.draw(m_Text);

}
