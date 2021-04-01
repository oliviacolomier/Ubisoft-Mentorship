#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{

	m_font.loadFromFile("Assets\\arial.tff");
	
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f( 150.0f, 100.0f));
	rect.setPosition(300.0f, 200.0f);

	m_text.setFont(m_font);
	m_text.setPosition(300.0f, 400.0f);
	m_text.setCharacterSize(25.0f);
	m_text.setString("Text");
	m_text.setFillColor(sf::Color::White);

	


	
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text);
	target.draw(rect);
	
}
