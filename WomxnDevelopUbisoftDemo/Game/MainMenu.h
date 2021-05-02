#pragma once
class MainMenu: public sf::Drawable
{
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void playMusic();
	void stopMusic();

private:

	sf::Sprite m_MenuBackground;
	sf::Texture m_Texture;

	sf::Text m_TitleText;
	sf::Text m_PlayText;
	sf::Text m_InstructionText;
	sf::Text m_StoryText;
	
	sf::Font m_Font;
	sf::Font m_TitleFont;

	sf::Music m_Music;
	sf::RectangleShape m_TextRect;

};

