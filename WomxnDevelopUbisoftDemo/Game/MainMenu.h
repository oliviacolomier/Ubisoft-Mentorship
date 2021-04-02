#pragma once
class MainMenu: public sf::Drawable
{
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void playMusic();

private:

	sf::Sprite menuBackground;
	sf::Texture m_Texture;
	sf::Text m_Text;
	sf::Font m_Font;
	sf::Music m_Music;
};

