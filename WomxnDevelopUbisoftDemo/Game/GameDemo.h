#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/Platforms.h>
#include <World.h>
#include <vector>


class GameDemo :  public Game //inheritance
{
public:
    GameDemo();

    void Update(float deltaTime) override;
    void Render(sf::RenderTarget& target) override;
    void RenderDebugMenu(sf::RenderTarget& target) override;
  
private:
    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;
    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;
    MainCharacter m_MainCharacter;
    World create_world;
    Platforms platform;
    sf::Vector2f mainPosition;
    sf::Vector2f sidePosition;
  
    bool m_IsFinished;
};