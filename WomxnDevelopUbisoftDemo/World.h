#pragma once
#include <vector>
#include <Game/MainCharacter.h>

class World: public sf::Drawable
{
public:
	World()= delete;
	World(MainCharacter* character);
	void CreatePlatform();//sf::Vector2f position, sf::Vector2f size);
	void collide(MainCharacter* character, Platforms platform);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setGroundHeight(float groundHeight);
	float getGroundHeight();



	


private:
	
	sf::Sprite background;
	sf::Texture backgroundImage;
	sf::Vector2f windowSize;
	std::vector<sf::Sprite> m_platforms;
	sf::Texture sprite_texture;
	sf::FloatRect player_box;
	sf::FloatRect platform_box;

	sf::Vector2f onPlatform;

	sf::Vector2f player_position;
	sf::Vector2f platform_position;
	MainCharacter& m_mainCharacter;
	float groundHeight;


};

