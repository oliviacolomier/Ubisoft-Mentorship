#pragma once
class World: public sf::Drawable, public sf::Transformable
{
public:
	World();
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);

private:
	sf::Sprite world_sprite1;
	sf::Texture world_texture1;
	sf::Sprite world_sprite2;
	sf::Texture world_texture2;
	sf::Texture box_texture;

	sf::Sprite rect;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	

};

