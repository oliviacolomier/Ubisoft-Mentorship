#include "stdafx.h"
#include "Game/Dialogue.h"


Dialogue::Dialogue()
{
	m_TextBox.setFillColor(sf::Color::White);
	m_TextBox.setOutlineColor(sf::Color::Black);
	m_TextBox.setOutlineThickness(5.0f);
	m_TextBox.setSize(sf::Vector2f(500.0f, 100.0f));
	m_TextBox.setPosition(sf::Vector2f(150.0f, 430.0f));
	

	m_Text.setPosition(150.0f, 430.0f);
	m_Font.loadFromFile(".\\Assets\\arial.ttf");
	m_Text.setFont(m_Font);
	m_Text.setCharacterSize(20);
	m_Text.setString("Hello Traveler. I am dying. \nThere is magical water in the building that can help.\n Alas, I am a tree and cannot walk. \nPerhaps you can retrieve it for me ? ");
	m_Text.setFillColor(sf::Color::Black);

}

void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_TextBox);
	target.draw(m_Text);
}

void Dialogue::updateDialogue(std::string line)
{
	m_Text.setPosition(150.0f, 430.0f);
	m_Text.setString(line);
}

