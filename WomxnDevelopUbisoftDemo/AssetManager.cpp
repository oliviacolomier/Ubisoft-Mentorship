#include "stdafx.h"
#include "AssetManager.h"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	//Only allow one AssestManager to exist
	//Otherwise throw an exception

	assert(sInstance == nullptr); //checks whether expression is true, will terminate program if false
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Textures;

	//See if texture is already loaded
	auto pairFound = texMap.find(filename);
	//If yes, return the texture
	if (pairFound != texMap.end())
	{
		return pairFound->second;

	}
	else //Else, load the texture and return it
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}


}

