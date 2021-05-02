#pragma once


class MainCharacter : public sf::Drawable, public BoxCollideable
{
public:	

	MainCharacter();

	void update(float deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void updateFrameCounter();
	void resetPosition(sf::Vector2f position);
	void updateCharacterTexture();


private:

	enum Direction{Down, Left, Right, Up};

	float m_FrameCounter, m_SwitchFrame, m_FrameSpeed;

	sf::Texture m_Texture;
	sf::Texture m_WaterTexture;
	sf::Sprite m_Sprite;
	sf::Clock m_Clock;

	sf::Vector2u m_Source;
	sf::Vector2f m_Position; 
	sf::Vector2f m_Velocity;

};