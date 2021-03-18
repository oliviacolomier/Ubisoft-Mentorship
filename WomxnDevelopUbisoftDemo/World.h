#pragma once
#include <vector>
#include <Game/MainCharacter.h>

class World: public sf::Drawable
{
public:
	World()= delete;
	World(MainCharacter* character);
	void CreatePlatform();//sf::Vector2f position, sf::Vector2f size);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

private:
	
	sf::Sprite background;
	sf::Texture backgroundImage;
	sf::Vector2f windowSize;
	std::vector<sf::Sprite> m_platforms;
	sf::Texture sprite_texture;
	MainCharacter& m_mainCharacter;
	
	float groundHeight;


};

