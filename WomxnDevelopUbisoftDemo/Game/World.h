#pragma once
class World : public sf::Drawable, public sf::Transformable, public BoxCollideable
{
public:

	World();
	
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);
	void createWorld(std::string worldName);
	void updatePosition(sf::Vector2f position);
	void treeResetPoisiton(sf::Vector2f position);
	void rect3ResetPoisiton(sf::Vector2f position);

	//make private with accessors
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
	sf::Sprite m_Tree;
	sf::Sprite m_Water;
	sf::Texture m_Texture;
	sf::Texture m_Texture2;
	sf::Vector2f m_Position;

	
	

};

