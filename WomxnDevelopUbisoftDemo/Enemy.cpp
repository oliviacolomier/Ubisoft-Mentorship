#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_Texture.loadFromFile(".\\Assets\\firesprite.jpg");
	m_Enemy.setTexture(m_Texture);

}
