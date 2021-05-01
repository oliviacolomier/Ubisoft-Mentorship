#pragma once
class World : public sf::Drawable, public sf::Transformable, public BoxCollideable
{
public:

	World();
	
	bool load(const std::string& tileset, sf::Vector2u tilesize, const int* tiles, unsigned int width, unsigned int height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void createWorld(std::string worldName);
	void updatePosition(sf::Vector2f position);
	void treeResetPositon(sf::Vector2f position);
	void treeRectResetPoisiton(sf::Vector2f position);
	void waterResetPosition(sf::Vector2f position);
	void updateTree();
	void playBuildingMusic();
	void stopBuildingMusic();


	//make private with accessors
	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape waterRect;

private:

	
	
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
	sf::Sprite m_Tree;
	sf::Sprite m_HealthyTree;
	sf::Sprite m_Water;
	sf::Sprite m_Door;


	sf::Texture m_Texture;
	sf::Texture m_Texture2;
	sf::Texture m_Texture3;
	sf::Vector2f m_Position;
	sf::Vector2f m_MoveOffScreen;
	sf::Music m_BuildingMusic;

	bool newTree;

};

