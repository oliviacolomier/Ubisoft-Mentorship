#pragma once
#include <Game/Platforms.h>



class MainCharacter : public sf::Drawable, public BoxCollideable
{
public:	

	MainCharacter();
	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void jump();
	void StartEndGame();


	float topSide;
	float rightSide;
	float leftSide;



	

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	float groundHeight = 500.0f;

	

	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	sf::Vector2f m_Position; 
	sf::Vector2f m_Velocity{ sf::Vector2f(0,0) };
	sf::Vector2f m_Acceleration{ sf::Vector2f(0,0) };
	
	const float gravity = 4;
	bool isJumping;
	float jumpHeight = 35.0f;

	bool m_IsPlayingEndGame;
};