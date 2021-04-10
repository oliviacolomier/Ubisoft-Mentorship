#pragma once
#include <Game/World.h>
#include <Game/MainCharacter.h>

class Dialogue: public sf::Drawable
{
public:
	Dialogue();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
private:
	World m_World;
	MainCharacter m_MainCharacter;
};

