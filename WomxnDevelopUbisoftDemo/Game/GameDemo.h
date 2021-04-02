#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/World.h>
#include <Game/MainMenu.h>
#include <Game/EndGame.h>

class GameDemo : public Game
{
public:
    GameDemo();

    void update(float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void renderDebugMenu(sf::RenderTarget& target) override;

    enum class Gamestate{ Menu, Gameplay, Dialogue, Endgame};


    

private:


   
    MainMenu m_Menu;
    Gamestate m_CurrentState;
    MainCharacter m_MainCharacter;
    World m_World;
    EndGame m_Endgame;

    
};