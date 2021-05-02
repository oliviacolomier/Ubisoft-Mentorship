#include "stdafx.h"
#include "Game/MainMenu.h"

MainMenu::MainMenu()
{

	m_Font.loadFromFile(".\\Assets\\CaviarDreams.ttf");
	m_TitleFont.loadFromFile(".\\Assets\\JungleTree.ttf");

	m_Texture.loadFromFile(".\\Assets\\menu_background.jpg");
	m_MenuBackground.setTexture(m_Texture);
	m_MenuBackground.setScale(0.6f, 0.6f);
	
	m_TextRect.setFillColor(sf::Color::White);
	m_TextRect.setOutlineColor(sf::Color::Black);
	m_TextRect.setOutlineThickness(5.0f);
	m_TextRect.setSize(sf::Vector2f(500.0f, 500.0f));
	m_TextRect.setPosition(sf::Vector2f(150.0f, 50.0f));
	
	m_TitleText.setFont(m_TitleFont);
	m_TitleText.setPosition(235.0f, 30.0f);
	m_TitleText.setCharacterSize(150.0f);
	m_TitleText.setString("The Tree");
	m_TitleText.setFillColor(sf::Color::Black);
	m_TitleText.setStyle(sf::Text::Bold);
	
	m_PlayText.setFont(m_Font);
	m_PlayText.setPosition(300.0f, 200.0f);
	m_PlayText.setCharacterSize(30.0f);
	m_PlayText.setString("Press 'P' to Play");
	m_PlayText.setFillColor(sf::Color::Black);
	m_PlayText.setStyle(sf::Text::Bold);

	m_InstructionText.setFont(m_Font);
	m_InstructionText.setPosition(300.0f, 250.0f);
	m_InstructionText.setCharacterSize(20.0f);
	m_InstructionText.setString("Press 'I' for instructions");
	m_InstructionText.setFillColor(sf::Color::Black);

	m_StoryText.setFont(m_Font);
	m_StoryText.setPosition(180.0f, 300.0f);
	m_StoryText.setCharacterSize(20.0f);
	m_StoryText.setString("\t\t\t\t\t\t\tSTORY: \n\n\t\tYou are walking through the jungle \nand enter an area you have never seen before.\nYou spot a rotting tree. It wants to speak to you.");
	m_StoryText.setFillColor(sf::Color::Black);

	if (!m_Music.openFromFile(".\\Assets\\ForestHaven.ogg"))
	{
		printf("Error, music doesn't load");
	}

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_MenuBackground);
	target.draw(m_TextRect);
	target.draw(m_TitleText);
	target.draw(m_PlayText);
	target.draw(m_InstructionText);
	target.draw(m_StoryText);
	
	
}

void MainMenu::playMusic()
{
	m_Music.play();
	m_Music.setLoop(true);
}

void MainMenu::stopMusic()
{
	m_Music.stop();
}
