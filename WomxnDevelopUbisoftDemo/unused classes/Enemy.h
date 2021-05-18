#pragma once
#include <vector>
#include <iostream>
class Enemy: public sf::Drawable, public BoxCollideable
{
public:
	Enemy();
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void enemyMovement();

private:
	
	std::vector<sf::Sprite> m_Enemies;
	sf::Sprite m_Enemy1;
	sf::Sprite m_Enemy2;
	sf::Sprite m_Enemy3;
	sf::Sprite m_Enemy4;

	sf::Texture m_Texture;
	sf::Vector2f m_Position;

	sf::Vector2f m_targetPosition;
	sf::Vector2f m_currentPosition;
	sf::Clock clock;
	int speed;
	sf::Time elapsedTime;
	float delta;
	

};

