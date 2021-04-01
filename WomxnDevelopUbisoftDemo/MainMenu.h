#pragma once
class MainMenu: public sf::Drawable
{
public:
	MainMenu();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape rect;
	sf::Text text;
	sf::Font font;
};

