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
	sf::RectangleShape m_BuildingRect;
	sf::RectangleShape m_TreeRect;
	sf::RectangleShape m_DoorRect;
	sf::RectangleShape m_WaterRect;

private:

	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
	sf::Sprite m_Tree;
	sf::Sprite m_HealthyTree;
	sf::Sprite m_Water;
	sf::Sprite m_Door;
	sf::Sprite m_Torch;
	sf::Sprite m_Torch2;
	sf::Sprite m_Table;
	sf::Sprite m_Cave;

	sf::Texture m_TreeTexture;
	sf::Texture m_WaterTexture;
	sf::Texture m_DoorTexture;
	sf::Texture m_TorchTexture;
	sf::Texture m_TableTexture;
	sf::Texture m_CaveTexture;

	sf::Vector2f m_Position;
	sf::Vector2f m_MoveOffScreen;
	sf::Music m_BuildingMusic;

	bool newTree;

};

