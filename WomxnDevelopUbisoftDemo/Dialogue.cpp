#include "stdafx.h"
#include "Game/Dialogue.h"


Dialogue::Dialogue()
{
	m_TextBox.setFillColor(sf::Color::White);
	m_TextBox.setOutlineColor(sf::Color::Black);
	m_TextBox.setOutlineThickness(5.0f);
	m_TextBox.setSize(sf::Vector2f(500.0f, 100.0f));
	m_TextBox.setPosition(sf::Vector2f(150.0f, 430.0f));
	

	m_Text.setPosition(200.0f, 430.0f);
	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");
	m_Text.setFont(m_Font);
	m_Text.setCharacterSize(30.0f);
	m_Text.setString("Hello, go to the building.");
	m_Text.setFillColor(sf::Color::Black);

	/*m_Text2.setPosition(200.0f, 430.0f);
	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");
	m_Text2.setFont(m_Font);
	m_Text2.setCharacterSize(30.0f);
	m_Text2.setFillColor(sf::Color::Black);*/

}

void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_TextBox);
	target.draw(m_Text);
}

void Dialogue::updateDialogue()
{
	m_Text.setString("Thank you for the water. Have a good day.");
}

