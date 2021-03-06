#include "stdafx.h"
#include "Game/World.h"

World::World()
{
	m_MoveOffScreen = sf::Vector2f(-100.0f, -100.0f);

	updatePosition(sf::Vector2f(70.0f, 30.0f));
	m_BuildingRect.setSize(sf::Vector2f(50.0f, 50.0f));
	m_BuildingRect.setFillColor(sf::Color::Red);
	m_BuildingRect.setPosition(m_Position);

	updatePosition(sf::Vector2f(650.0f, 350.0f));
	m_TreeRect.setSize(sf::Vector2f(50.0f, 50.0f));
	m_TreeRect.setFillColor(sf::Color::Blue);
	m_TreeRect.setPosition(sf::Vector2f(610.0f,325.0f));
	
	updatePosition(sf::Vector2f(700.0f, 300.0f));
	m_WaterRect.setSize(sf::Vector2f(50.0f, 50.0f));
	m_WaterRect.setFillColor(sf::Color::Magenta);
	m_WaterRect.setPosition(sf::Vector2f(550.0f, 350.0f));

	m_DoorRect.setSize(sf::Vector2f(50.0f, 50.0f));
	m_DoorRect.setFillColor(sf::Color::Green);
	
	m_TreeTexture.loadFromFile(".\\Assets\\tree.gif");
	m_Tree.setTexture(m_TreeTexture);
	m_Tree.setPosition(m_Position);
	m_Tree.setScale(-0.9f, 0.9f);

	updatePosition(sf::Vector2f(27.0f,470.0f));
	m_CaveTexture.loadFromFile(".\\Assets\\cave.png");
	m_Cave.setTexture(m_CaveTexture);
	m_Cave.setPosition(m_Position);
	m_Cave.setScale(0.2f, 0.2f);

	m_WaterTexture.loadFromFile(".\\Assets\\water.gif");
	m_Water.setTexture(m_WaterTexture);
	m_Water.setPosition(sf::Vector2f(100.0f,100.0f));
	m_Water.setScale(0.09f, 0.09f);

	m_DoorTexture.loadFromFile(".\\Assets\\door.png");
	m_Door.setTexture(m_DoorTexture);
	m_Door.setPosition(m_MoveOffScreen);
	m_Door.setScale(0.1f, 0.1f);

	
	m_TorchTexture.loadFromFile(".\\Assets\\torch.gif");
	m_Torch.setTexture(m_TorchTexture);
	m_Torch.setScale(0.2f, 0.2f);
	m_Torch2.setTexture(m_TorchTexture);
	m_Torch2.setScale(0.2f, 0.2f);


	m_TableTexture.loadFromFile(".\\Assets\\table.gif");
	m_Table.setTexture(m_TableTexture);
	m_Table.setScale(0.1f, 0.1f);

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
		
		m_BuildingRect.setPosition(m_MoveOffScreen);
		m_TreeRect.setPosition(m_MoveOffScreen);
		m_DoorRect.setPosition(30.0f, 520.0f);
		m_Tree.setPosition(m_MoveOffScreen);
		m_Water.setPosition(700.0f, 300.0f);
		m_WaterRect.setPosition(700.0f,300.0f);
		m_Torch.setPosition(110.0f, 3.0f);
		m_Torch2.setPosition(570.0f, 3.0f);
		m_Table.setPosition(705.0f, 340.0f);
		m_Cave.setPosition(m_MoveOffScreen);

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
		m_DoorRect.setPosition(m_MoveOffScreen);
		m_Water.setPosition(m_MoveOffScreen);
		m_WaterRect.setPosition(m_MoveOffScreen);
		m_Torch.setPosition(m_MoveOffScreen);
		m_Torch2.setPosition(m_MoveOffScreen);
		m_Table.setPosition(m_MoveOffScreen);
		m_Cave.setPosition(27.0f, 470.0f);
		

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
	
	target.draw(m_WaterRect);
	target.draw(m_BuildingRect);
	target.draw(m_TreeRect);
	target.draw(m_DoorRect);

	//apply the transform
	states.transform *= getTransform();

	//apply the tileset Texture
	states.texture = &m_Tileset;

	//draw the vertex array
	target.draw(m_Vertices, states);

	target.draw(m_Tree);
	target.draw(m_Table);
	target.draw(m_Water);
	target.draw(m_Door);
	target.draw(m_Torch);
	target.draw(m_Torch2);
	target.draw(m_Cave);

	
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
	m_TreeRect.setPosition(position);
}
void World::waterResetPosition(sf::Vector2f position)
{
	m_Water.setPosition(position);
}
void World::updateTree()
{

	newTree = true;

	m_TreeTexture.loadFromFile("Assets\\happy_tree.png");
	m_HealthyTree.setTexture(m_TreeTexture);
	m_HealthyTree.setScale(0.3f, 0.3f);
	m_HealthyTree.setPosition(500.0f, 150.0f);
	m_Tree.setPosition(m_MoveOffScreen);

}

void World::playBuildingMusic()
{
	m_BuildingMusic.play();
	m_BuildingMusic.setLoop(true);
}

void World::stopBuildingMusic()
{
	m_BuildingMusic.stop();
}





