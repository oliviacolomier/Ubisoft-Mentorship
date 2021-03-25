#pragma once
class World: public sf::Drawable, public sf::Transformable
{
public:
	World();
	
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	

};

