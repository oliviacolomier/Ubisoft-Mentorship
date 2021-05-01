#include "stdafx.h"
#include "Game/World.h"

World::World()
{
	m_MoveOffScreen = sf::Vector2f(-100.0f, -100.0f);

	updatePosition(sf::Vector2f(70.0f, 30.0f));
	rect1.setSize(sf::Vector2f(50.0f, 50.0f));
	rect1.setFillColor(sf::Color::Red);
	rect1.setPosition(m_Position);

	updatePosition(sf::Vector2f(650.0f, 350.0f));
	rect2.setSize(sf::Vector2f(50.0f, 50.0f));
	rect2.setFillColor(sf::Color::Blue);
	rect2.setPosition(sf::Vector2f(550.0f,350.0f));
	
	updatePosition(sf::Vector2f(700.0f, 300.0f));
	waterRect.setSize(sf::Vector2f(50.0f, 50.0f));
	waterRect.setFillColor(sf::Color::Magenta);
	waterRect.setPosition(sf::Vector2f(550.0f, 350.0f));

	rect3.setSize(sf::Vector2f(50.0f, 50.0f));
	rect3.setFillColor(sf::Color::Green);
	

	m_Texture.loadFromFile(".\\Assets\\tree.gif");
	m_Tree.setTexture(m_Texture);
	m_Tree.setPosition(m_Position);
	m_Tree.setScale(-0.9f, 0.9f);

	m_Texture2.loadFromFile(".\\Assets\\water.gif");
	m_Water.setTexture(m_Texture2);
	m_Water.setPosition(sf::Vector2f(100.0f,100.0f));
	m_Water.setScale(0.09f, 0.09f);

	m_Texture3.loadFromFile(".\\Assets\\door.png");
	m_Door.setTexture(m_Texture3);
	m_Door.setPosition(m_MoveOffScreen);
	m_Door.setScale(0.1f, 0.1f);


	createWorld("level1");

	if (!m_BuildingMusic.openFromFile(".\\Assets\\buildingmusic.ogg"))
	{
		printf("Error, music doesn't load");
	}


}


bool World::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	if (!m_Tileset.loadFromFile(tileset))
	{
		return false;
	}

	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(static_cast<size_t>(width) * height * 4);


			//populate vertex array, with one quad per tile
			for(unsigned int i = 0; i < width; i++)
				

				for (unsigned int j = 0; j < height; ++j)
				{
					float iAsFloat = static_cast<float>(i);
					float jAsFloat = static_cast<float>(j);
					float tileSizeX = static_cast<float>(tileSize.x);
					float tileSizeY = static_cast<float>(tileSize.y);

					//get the current tile number
					int tileNumber = tiles[i + j * width];

					//find its position in the tileset texture
					int tu = tileNumber % (m_Tileset.getSize().x / tileSize.x);
					int tv = tileNumber / (m_Tileset.getSize().x / tileSizeX);
					
					//get a pointer to the current tile's quad
					sf::Vertex* quad = &m_Vertices[(i + static_cast<size_t>(j) * width) * 4];

					//define its 4 corners
					//add static_cast
					quad[0].position = sf::Vector2f(i * tileSizeX, j * tileSizeY);
					quad[1].position = sf::Vector2f((i + 1) * tileSizeX, j * tileSizeY);
					quad[2].position = sf::Vector2f((i + 1) * tileSizeX, (j + 1) * tileSizeY);
					quad[3].position = sf::Vector2f(i * tileSizeX, (j + 1) * tileSizeY);

					//define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(tu * tileSizeX, tv * tileSizeY);
					quad[1].texCoords = sf::Vector2f((tu + 1) * tileSizeX, tv * tileSizeY);
					quad[2].texCoords = sf::Vector2f((tu + 1) * tileSizeX, (tv + 1) * tileSizeY);
					quad[3].texCoords = sf::Vector2f(tu * tileSizeX, (tv + 1) * tileSizeY);

				}

	return false;
}

void World::createWorld(std::string worldName)
{

	if (worldName == "level2") 
	{
		
		rect1.setPosition(m_MoveOffScreen);
		rect2.setPosition(m_MoveOffScreen);
		rect3.setPosition(30.0f, 520.0f);
		m_Tree.setPosition(m_MoveOffScreen);
		m_Water.setPosition(700.0f, 300.0f);
		waterRect.setPosition(700.0f,300.0f);
		

		const int level2[] =
		{
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
			20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
		};


		load(("Assets\\RockTile.png"), sf::Vector2u(32, 32), level2, 25, 20);
		m_Door.setPosition(30.0f, 520.0f);
	}
	else
	{
		rect3.setPosition(m_MoveOffScreen);
		m_Water.setPosition(m_MoveOffScreen);
		waterRect.setPosition(m_MoveOffScreen);
		

		const int level[] =
		{
			72, 27, 72, 72, 27, 72, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,24,24,24,24, 24,
			95, 96, 98, 98, 96, 95, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 34, 35, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 149, 150, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 149, 150, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 149, 150, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47,47 , 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,
			46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47,47,47, 47, 47, 47, 47,

		};

		load(("Assets\\tile_map.bmp"), sf::Vector2u(32, 32), level, 25, 19);
		m_Door.setPosition(m_MoveOffScreen);
	}
}

void World::updatePosition(sf::Vector2f newPosition)
{
	m_Position = newPosition;
}


void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rect1);
	target.draw(rect2);
	target.draw(rect3);
	target.draw(waterRect);
	

	//apply the transform
	states.transform *= getTransform();

	//apply the tileset Texture
	states.texture = &m_Tileset;

	//draw the vertex array
	target.draw(m_Vertices, states);

	target.draw(m_Tree);
	target.draw(m_Water);
	target.draw(m_Door);
	
	


	if (newTree == true)
	{
		target.draw(m_HealthyTree);
	}



}
void World::treeResetPositon(sf::Vector2f position)
{
	m_Tree.setPosition(position);
}

void World::treeRectResetPoisiton(sf::Vector2f position)
{
	rect2.setPosition(position);
}
void World::waterResetPosition(sf::Vector2f position)
{
	m_Water.setPosition(position);
}
void World::updateTree()
{

	newTree = true;

	m_Texture2.loadFromFile("Assets\\happy_tree.png");
	m_HealthyTree.setTexture(m_Texture2);
	m_HealthyTree.setScale(0.3f, 0.3f);
	m_HealthyTree.setPosition(500.0f, 150.0f);
	m_Tree.setPosition(m_MoveOffScreen);

}

void World::playBuildingMusic()
{
	m_BuildingMusic.play();
}

void World::stopBuildingMusic()
{
	m_BuildingMusic.stop();
}



