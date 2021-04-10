#pragma once
#include <Game/World.h>

class Dialogue: public sf::Drawable
{
public:
	Dialogue();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	World m_World;
};

