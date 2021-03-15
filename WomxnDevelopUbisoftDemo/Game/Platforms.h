#pragma once
#include <vector>

class Platforms: public sf::Drawable, public BoxCollideable
{

public:
	Platforms(); //constructor

	
	std::vector<sf::Sprite> platforms;


	void Update(float deltaTime); //create definition for floating effect
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void StartEndGame();
	sf::Vector2f platform_position;
	
	

private:
	sf::Texture sideTexture;
	sf::Texture platform_texture;
	sf::Sprite platform1;
	sf::Sprite sideSprite;
	bool side_IsPlayingEndGame;




};

