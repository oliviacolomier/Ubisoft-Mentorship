#pragma once
#include <fstream>
#include <iostream>
#include <String>
#include <Game/World.h>
#include <Game/MainCharacter.h>

class Dialogue: public sf::Drawable
{
public:

	Dialogue();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void updateDialogue();


private:

	sf::RectangleShape m_TextBox;
	sf::Text m_Text;
	//sf::Text m_Text2;
	sf::Font m_Font;
	//std::string m_Input;
	//std::vector<std::string> dialogue;


};

