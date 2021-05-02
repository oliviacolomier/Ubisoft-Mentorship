#include "stdafx.h"
#include "Game/MainMenu.h"

MainMenu::MainMenu()
{

	m_Font.loadFromFile(".\\Assets\\BunnyBaby.otf");
	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	m_MenuBackground.setTexture(m_Texture);
	m_MenuBackground.setScale(0.6f, 0.6f);
	
	m_TextRect.setFillColor(sf::Color::White);
	m_TextRect.setOutlineColor(sf::Color::Black);
	m_TextRect.setOutlineThickness(5.0f);
	m_TextRect.setSize(sf::Vector2f(500.0f, 100.0f));
	m_TextRect.setPosition(sf::Vector2f(150.0f, 250.0f));
	
	m_Text.setFont(m_Font);
	m_Text.setPosition(225.0f, 250.0f);
	m_Text.setCharacterSize(50.0f);
	m_Text.setString("Press 'P' to Play");
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);

	m_Text2.setFont(m_Font);
	m_Text2.setPosition(300.0f, 300.0f);
	m_Text2.setCharacterSize(20.0f);
	m_Text2.setString("Press 'I' for instructions");
	m_Text2.setFillColor(sf::Color::Black);
	

	if (!m_Music.openFromFile(".\\Assets\\ForestHaven.ogg"))
	{
		printf("Error, music doesn't load");
	}

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_MenuBackground);
	target.draw(m_TextRect);
	target.draw(m_Text);
	target.draw(m_Text2);
	
	
}

void MainMenu::playMusic()
{
	m_Music.play();
}

void MainMenu::stopMusic()
{
	m_Music.stop();
}
