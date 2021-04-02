#pragma once
class World : public sf::Drawable, public sf::Transformable, public BoxCollideable
{
public:
	World();
	
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);
	
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;

	

};

