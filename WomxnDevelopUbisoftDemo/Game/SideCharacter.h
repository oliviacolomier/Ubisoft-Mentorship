#pragma once

class SideCharacter: public sf::Drawable
{

public:
	SideCharacter(); //constructor

	void Update(float deltaTime); //create definition for floating effect
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void StartEndGame();

private:
	sf::Texture sideTexture;
	sf::Sprite sideSprite;

	sf::Vector2f sidePosition;
	
	bool side_IsPlayingEndGame;




};

