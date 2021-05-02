#pragma once
class InstructionMenu: public sf::Drawable
{
public:
	InstructionMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::Sprite m_Background;
	sf::Texture m_Texture;
	sf::Text m_Text;
	sf::Font m_Font;

	sf::RectangleShape m_TextRect;
};

