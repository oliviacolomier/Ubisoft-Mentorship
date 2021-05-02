#include <stdafx.h>
#include <Game/MainCharacter.h>

using namespace sf;

MainCharacter::MainCharacter()
    : m_Position(400.0f, 300.0f)
{
    m_Texture.loadFromFile(".\\Assets\\tiger.gif");
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(m_Position);
    m_Sprite.setScale(0.9f, 0.9f);

    m_WaterTexture.loadFromFile(".\\Assets\\tiger_blue.gif");
  
    SetBoundingBox(50.0f,50.0f,50.0f,50.0f);
}


void MainCharacter::update(float deltaTime)
{
    const float SPEED_MAX = 150.0f;
    const float SPEED_INC = 10.0f;
    const float DEAD_ZONE = 5.0f;
    const float SLOWDOWN_RATE = 0.5f;


   if (Keyboard::isKeyPressed(Keyboard::D))
      {
            updateFrameCounter();
            source.y = Right;
            m_Velocity.x = fmin(m_Velocity.x + SPEED_INC, SPEED_MAX);
    
      }

   else if (Keyboard::isKeyPressed(Keyboard::A))
      {
            source.y = Left;
            m_Velocity.x = fmax(m_Velocity.x - SPEED_INC, -SPEED_MAX);
            updateFrameCounter();
      }

   else
      {
            m_Velocity.x *= SLOWDOWN_RATE;
      }

   if (Keyboard::isKeyPressed(Keyboard::S))
      {
            source.y = Down;
            m_Velocity.y = fmin(m_Velocity.y + SPEED_INC, SPEED_MAX);
            updateFrameCounter();
      }

   else if (Keyboard::isKeyPressed(Keyboard::W))
      {
            source.y = Up;
            m_Velocity.y = fmax(m_Velocity.y - SPEED_INC, -SPEED_MAX);
            updateFrameCounter();
      }

   else
      {
            m_Velocity.y *= SLOWDOWN_RATE;
      }
     
    m_Sprite.setTextureRect(sf::IntRect(source.x * 48, source.y * 50, 48, 48));
    m_Position += m_Velocity * deltaTime;
    m_Sprite.setPosition(m_Position);
    SetCenter(m_Position);

//Window Collision
// 
    //Left Collision
    if (m_Sprite.getPosition().x < 0.f)
        m_Sprite.setPosition(0, m_Sprite.getPosition().y);
    //Top Collision
    if (m_Sprite.getPosition().y < 0.f)
        m_Sprite.setPosition(m_Sprite.getPosition().x, 0.0f);
    //Right Collision
    if (m_Sprite.getPosition().x + m_Sprite.getGlobalBounds().width > 800.0f)
        m_Sprite.setPosition(800 - m_Sprite.getGlobalBounds().width, m_Sprite.getPosition().y);
    //Bottom Collision
    if (m_Sprite.getPosition().y + m_Sprite.getGlobalBounds().height > 600.0f)
        m_Sprite.setPosition(m_Sprite.getPosition().x, 600 - m_Sprite.getGlobalBounds().height);
    
}

void MainCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite);
}


void MainCharacter::updateFrameCounter()
{
    m_FrameCounter += m_FrameSpeed * m_Clock.restart().asSeconds();
    if (m_FrameCounter >= m_SwitchFrame)
    {
        m_FrameCounter = 0;
        source.x++;
        if (source.x * 48 >= m_Texture.getSize().x)
            source.x = 0;
    }
}

void MainCharacter::resetPosition(sf::Vector2f position)
{
    m_Position = position;
}

void MainCharacter::updateCharacterTexture()
{
    
    m_Sprite.setTexture(m_WaterTexture);

}

