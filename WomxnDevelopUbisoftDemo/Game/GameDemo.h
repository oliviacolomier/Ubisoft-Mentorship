#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/World.h>
#include <Game/MainMenu.h>

class GameDemo : public Game
{
public:
    GameDemo();

    void update(float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void renderDebugMenu(sf::RenderTarget& target) override;

    enum class Gamestate{ Menu, Gameplay, Dialogue};


    

private:

    sf::Font m_EndgameTextFont;
    sf::Text m_EndgameText;
    sf::SoundBuffer m_EndgameSoundBuffer;
    sf::Sound m_EndgameSound;
   
    MainMenu m_Menu;
    Gamestate m_CurrentState = Gamestate::Menu;
    MainCharacter m_MainCharacter;
    World m_World;
    bool m_IsFinished;
    
};