#pragma once
class MainMenu: public sf::Drawable
{
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void playMusic();
	void stopMusic();

private:

	sf::Sprite menuBackground;
	sf::Texture m_Texture;
	sf::Text m_Text;
	sf::Text m_Text2;
	sf::Font m_Font;
	sf::Music m_Music;

};

