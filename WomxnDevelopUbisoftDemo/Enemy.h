#pragma once
class Enemy: public sf::Drawable
{
public:
	Enemy();

private:
	sf::Sprite m_Enemy;
	sf::Texture m_Texture;

};

