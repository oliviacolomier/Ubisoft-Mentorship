#include "stdafx.h"
#include "AssetManager.h"

namespace state_space
{
	void AssetManager::LoadTexture(std::string name, std::string filename)
	{
		sf::Texture texture;
		if (texture.loadFromFile(filename))
		{
			this->_textures[name] = texture;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string filename)
	{
		sf::Font font;
		if (font.loadFromFile(filename))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}


}