#pragma once
class World: public sf::Drawable
{
public:
	World();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
	sf::Sprite world_sprite;
	sf::Texture world_texture;
	

};

