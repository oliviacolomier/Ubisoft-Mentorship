#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_Enemies.push_back(m_Enemy1);
	m_Enemies.push_back(m_Enemy2);
	m_Enemies.push_back(m_Enemy3);
	m_Enemies.push_back(m_Enemy4);

	m_Position = sf::Vector2f(100.0f, 535.0f);

	m_Texture.loadFromFile(".\\Assets\\fire.png");

	for (int i = 0; i < m_Enemies.size(); i++)
	{
		GetBoundingBox();
		m_Enemies[i].setTexture(m_Texture);
		m_Enemies[i].setScale(0.1f, 0.1f);
		m_Enemies[i].setPosition(m_Position);
		m_Position.x += 200.0f;
	}
	
	elapsedTime = clock.restart();
	delta = elapsedTime.asSeconds() * 60;
	speed = 30;
	
	m_targetPosition = sf::Vector2f(-500.0f, -500.0f);
	
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_Enemies.size(); i++)
	{
		target.draw(m_Enemies[i]);
	}
}


