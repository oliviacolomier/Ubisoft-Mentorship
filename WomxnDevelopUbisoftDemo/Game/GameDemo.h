#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/World.h>
#include <Game/MainMenu.h>
#include <Game/EndGame.h>
#include <Game/Dialogue.h>
#include <Game/InstructionMenu.h>



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
    Dialogue m_Dialogue;
    EndGame m_Endgame;
    InstructionMenu m_Instruction;
    World* m_CurrentWorld = nullptr;

    bool level2 = false;
    bool endGame;

    

    
};