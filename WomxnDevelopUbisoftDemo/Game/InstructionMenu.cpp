#include "stdafx.h"
#include "InstructionMenu.h"

InstructionMenu::InstructionMenu()
{
	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");

	m_Text.setFont(m_Font);
	m_Text.setPosition(100.0f, 250.0f);
	m_Text.setCharacterSize(30.0f);
	m_Text.setString("Use 'A' 'W' 'S' 'D' to control the character");
	m_Text.setFillColor(sf::Color::Red);
	m_Text.setStyle(sf::Text::Bold);
}

void InstructionMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Text);

}
