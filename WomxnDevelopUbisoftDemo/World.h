#pragma once
class World: public sf::Drawable
{
public:
	World();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	
	sf::Sprite background;
	sf::Texture backgroundImage;
	sf::Vector2f windowSize;


};

