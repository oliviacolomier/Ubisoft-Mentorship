#pragma once
class EndGame: public sf::Drawable
{
public:
	EndGame();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void playDeathSound();

private:
	sf::Text m_Text;
	sf::Font m_Font;
	sf::SoundBuffer m_Buffer;
	sf::Sound m_DeathSound;

};

