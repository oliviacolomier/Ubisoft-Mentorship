#pragma once


class MainCharacter : public sf::Drawable, public BoxCollideable
{
public:	
	MainCharacter();

	void Update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void StartEndGame();


private:

	enum Direction{Down, Left, Right, Up};

	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Clock clock;


	int sourceX = 48; //where we start drawing from
	int sourceY = Down; //start drawing for Y coordinate


	bool m_IsUsingJoystick;
	unsigned int m_JoystickIndex;
	bool m_WasButtonPressed;

	sf::Vector2f m_Position; 
	sf::Vector2f m_Velocity;
	bool m_IsPlayingEndGame;
};