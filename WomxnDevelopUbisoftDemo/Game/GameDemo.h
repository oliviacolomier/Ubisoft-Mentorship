#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/Platforms.h>
#include <World.h>
#include <vector>


class GameDemo :  public Game//inheritance
{
public:
    GameDemo();

    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;
    
  
private:
  
    MainCharacter m_character;
    World* m_world; //world instance
    Platforms platform;
    sf::Vector2f mainPosition;
   
    
    bool m_IsFinished;
};