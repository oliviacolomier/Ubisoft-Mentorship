#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{

	font.loadFromFile(".\\Assets\\arial.tff");
	
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f( 150.0f, 100.0f));
	rect.setPosition(300.0f, 200.0f);

	text.setString("Hello");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(400.0f, 300.0f);
	//text.setScale(1.0f, 1.0f);
	text.setCharacterSize(100);
	


	
}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect);
	target.draw(text);
}
