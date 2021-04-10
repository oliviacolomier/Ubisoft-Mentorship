#pragma once
class World : public sf::Drawable, public sf::Transformable, public BoxCollideable
{
public:
	World();
	
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);
	
	//make private with accessors
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
	sf::Sprite m_Tree;
	sf::Texture m_Texture;
	

	

};

