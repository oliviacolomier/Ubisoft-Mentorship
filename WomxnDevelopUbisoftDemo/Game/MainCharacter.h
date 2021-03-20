#pragma once
#include <Game/Platforms.h>
//#include <World.h>




class MainCharacter : public sf::Drawable, public BoxCollideable
{
public:	

	MainCharacter();
	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void jump();
	void StartEndGame();

	void setVelocity(sf::Vector2f main_velocity);
	sf::Vector2f getVelocity();


private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
	sf::Vector2f m_Velocity{ sf::Vector2f(0,0) };
	sf::Vector2f m_Acceleration{ sf::Vector2f(0,0) };


	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;
	const float gravity = 4;
	bool isJumping;
	float jumpHeight = 35.0f;
	bool m_IsPlayingEndGame;


	//World* world;//creates new object which calls constructor
	float groundHeight = 500.0f;;
};