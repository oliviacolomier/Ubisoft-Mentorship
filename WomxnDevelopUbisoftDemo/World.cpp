#include "stdafx.h"
#include "Game/World.h"

World::World()
{

	rect1.setSize(sf::Vector2f(50.0f, 50.0f));
	rect1.setFillColor(sf::Color::Red);
	rect1.setPosition(sf::Vector2f(290.0f, 350.0f));

	rect2.setSize(sf::Vector2f(50.0f, 50.0f));
	rect2.setFillColor(sf::Color::Red);
	rect2.setPosition(sf::Vector2f(70.0f, 30.0f));


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
		46, 47, 47, 47, 47, 47, 47, 47, 47, 292, 293, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
		70, 70, 70, 70, 70, 70, 47, 47, 47, 264, 265, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
		376, 376, 376, 376, 421, 376, 46, 47, 47, 258, 259, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
		23, 24, 24,24 , 25, 419, 46, 47, 47, 258, 259, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
		46, 47, 47, 47, 48, 442, 46, 47, 47, 258, 259, 47, 47, 47, 47, 47, 47, 47, 47, 47,47, 47, 47, 47, 47,
		69, 70, 70, 70, 71, 421, 69, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70,70, 70, 70, 70, 70,
		368, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,376, 376, 376, 376, 376,
		368, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376, 376,376, 376, 376, 376, 378,
		


	};

	// create the tilemap from the level definition
	load(("Assets\\tile_map.bmp"), sf::Vector2u(32, 32), level, 25, 19);

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

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//apply the transform
	states.transform *= getTransform();

	//apply the tileset Texture
	states.texture = &m_Tileset;

	//draw the vertex array
	target.draw(m_Vertices, states);

	target.draw(rect1);
	target.draw(rect2);

}

