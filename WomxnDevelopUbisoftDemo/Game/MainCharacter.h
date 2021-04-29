#pragma once


class MainCharacter : public sf::Drawable, public BoxCollideable
{
public:	

	MainCharacter();

	void update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void startEndGame();
	void updateFrameCounter();
	void resetPosition(sf::Vector2f position);


private:

	enum Direction{Down, Left, Right, Up};

	float m_FrameCounter = 0, m_SwitchFrame = 100, m_FrameSpeed = 500;

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Clock m_Clock;


	sf::Vector2u source = sf::Vector2u(48, Down);
	sf::Vector2f m_Position; 
	sf::Vector2f m_Velocity;

};