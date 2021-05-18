#include "stdafx.h"
#include "InstructionMenu.h"

InstructionMenu::InstructionMenu()
{
	m_Font.loadFromFile(".\\Assets\\CaviarDreams.ttf");
	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	m_Background.setTexture(m_Texture);
	m_Background.setScale(0.6f, 0.6f);

	m_TextRect.setFillColor(sf::Color::White);
	m_TextRect.setOutlineColor(sf::Color::Black);
	m_TextRect.setOutlineThickness(5.0f);
	m_TextRect.setSize(sf::Vector2f(500.0f, 100.0f));
	m_TextRect.setPosition(sf::Vector2f(150.0f, 250.0f));

	m_Text.setFont(m_Font);
	m_Text.setPosition(130.0f, 260.0f);
	m_Text.setCharacterSize(30.0f);
	m_Text.setString("\t\t\t  Use 'A' 'W' 'S' 'D' to\n\t\t\tcontrol the character");
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);
}

void InstructionMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Background);
	target.draw(m_TextRect);
	target.draw(m_Text);
}


