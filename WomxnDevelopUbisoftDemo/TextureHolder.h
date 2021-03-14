#pragma once
namespace Textures
{
	enum ID { MainCharacter, SideCharacter };
}

class TextureHolder
{
public:
	void load(Textures::ID id, const std::string& filename);

	sf::Texture& get(Textures::ID id);
	
	const sf::Texture& get(Textures::ID id) const;

	



private:
	std::map<Textures::ID,
		std::unique_ptr<sf::Texture>>mTextureMap;


};

