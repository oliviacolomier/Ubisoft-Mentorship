#include "stdafx.h"
#include "Game/World.h"

World::World()
{
	world_texture1.loadFromFile(".\\Assets\\background.bmp");
	const sf::Vector2f size(static_cast<float>(world_texture1.getSize().x), static_cast<float>(world_texture1.getSize().y));
	world_sprite1.setTexture(world_texture1);
	world_sprite1.setOrigin(size * 0.5f);
	world_sprite1.setPosition(sf::Vector2f(500.0f, 400.0f));
	world_sprite1.setScale(sf::Vector2f(1.4f, 1.4f));

	world_texture2.loadFromFile(".\\Assets\\background.bmp");
	world_sprite2.setOrigin(size * 0.5f);
	world_sprite2.setPosition(sf::Vector2f(300.0f, 500.0f));
	world_sprite2.setScale(sf::Vector2f(1.4f, 1.4f));

	box_texture.loadFromFile(".\\Assets\\box.bmp");
	rect.setTexture(box_texture);
	rect.setOrigin(700.0f, 800.0f);
	rect.setPosition(500.0f, 800.0f);
	rect.setScale(sf::Vector2f(0.4f, 0.4f));


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
	if (!m_tileset.loadFromFile(tileset))
	{
		return false;
	}

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(static_cast<size_t>(width) * height * 4);


			//populate vertex array, with one quad per tile
			for(unsigned int i = 0; i < width; i++)
				for (unsigned int j = 0; j < height; ++j)
				{
					//get the current tile number
					int tileNumber = tiles[i + j * width];

					//find its position in the tileset texture
					int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
					int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

					//get a pointer to the current tile's quad
					sf::Vertex* quad = &m_vertices[(i + static_cast<size_t>(j) * width) * 4];

					//define its 4 corners
					quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					//define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
					quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
					quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
					quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

				}

	return false;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//apply the transform
	states.transform *= getTransform();


	//apply the tileset Texture
	states.texture = &m_tileset;

	//draw the vertex array
	target.draw(m_vertices, states);

}

