#include "stdafx.h"
#include "Camera.h"

void Camera::Render(sf::RenderTarget& sprite_character)
{
	sprite_character.clear(sf::Color(0, 0, 0));
	sprite_character.draw(mainCharacter);
	
	
}
