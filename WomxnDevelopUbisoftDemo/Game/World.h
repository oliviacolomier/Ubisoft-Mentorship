#pragma once
class World: public sf::Drawable
{
public:
	World();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setView(); //changes views based on location

private:
	sf::Sprite world_sprite1;
	sf::Texture world_texture1;
	sf::Sprite world_sprite2;
	sf::Texture world_texture2;
	sf::Texture box_texture;

	sf::Sprite rect;

	

};

