#pragma once
#include "Game/MainCharacter.h"
class Camera: public MainCharacter
{
public:
	MainCharacter mainCharacter;
	virtual void Render(sf::RenderTarget& sprite_character);


};