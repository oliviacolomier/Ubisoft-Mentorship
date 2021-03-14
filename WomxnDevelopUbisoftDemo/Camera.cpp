#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
	
   

}

void Camera::sprite_manager()
{
    m_Texture.loadFromFile(".\\Assets\\red_ball.bmp"); //sprite image
    const sf::Vector2f size(static_cast<float>(m_Texture.getSize().x), static_cast<float>(m_Texture.getSize().y));
    mainCharacter.setTexture(m_Texture); //set sprite texture
    mainCharacter.setOrigin(size * 0.5f); //set origin for sprite
    mainCharacter.setPosition(m_Position); //set position for sprite

    sprites.push_back(mainCharacter);
    sprites.push_back(sideCharacter);
    sprites.push_back(rect);
}

void Render(sf::RenderTarget& target, sf::RenderStates states, std::vector<sf::Drawable>& sprites )
{
    
    target.draw(sprites[0]);

}


