#pragma once
class MainMenu: public sf::Drawable
{
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::Sprite menuBackground;
	sf::Texture m_Texture;
	sf::Text m_text;
	sf::Font m_font;
};

