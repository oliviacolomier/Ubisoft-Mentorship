#pragma once
class EndGame: public sf::Drawable
{
public:
	EndGame();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text m_Text;
	sf::Font m_Font;


};

