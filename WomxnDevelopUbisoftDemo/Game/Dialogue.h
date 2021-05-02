#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Game/World.h>
#include <Game/MainCharacter.h>

class Dialogue : public sf::Drawable
{
public:

	Dialogue();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void updateDialogue(std::string);


private:

	sf::RectangleShape m_TextBox;
	sf::Text m_Text;
	sf::Font m_Font;
	sf::String m_Dialogue;

};

