#include "stdafx.h"
#include "GameDemo.h"

GameDemo::GameDemo()
    : Game{ "Game Demo" }
    , m_MainCharacter{}
    , m_IsFinished{ false }
{

    m_EndgameTextFont.loadFromFile("Assets\\arial.ttf");

    m_EndgameText.setFont(m_EndgameTextFont);
    m_EndgameText.setPosition(500, 400);
    m_EndgameText.setString("!!! WIN !!!");
    m_EndgameText.setCharacterSize(24);
    m_EndgameText.setFillColor(sf::Color::Red);
    m_EndgameSoundBuffer.loadFromFile("Assets\\Test.wav");
    m_EndgameSound.setBuffer(m_EndgameSoundBuffer);

    m_CurrentState = Gamestate::Menu;
    
    
    
}

void GameDemo::update(float deltaTime)
{


    switch (m_CurrentState)
    {
    case Gamestate::Gameplay:
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            m_CurrentState = Gamestate::Menu;
        }
        
        m_MainCharacter.update(deltaTime);

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.rect1.getGlobalBounds()))
            //printf("yes");
            m_CurrentState = Gamestate::Endgame;

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.rect2.getGlobalBounds()))
            //printf("yes");
            m_CurrentState = Gamestate::Endgame;
        

        break;

    case Gamestate::Dialogue:
        //update dialogue
        break;

    case Gamestate::Menu:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            m_CurrentState = Gamestate::Gameplay;
        }
        
        break;

    case Gamestate::Endgame:
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_MainCharacter.resetPosition();
            m_CurrentState = Gamestate::Menu;
            
        }
    }

    }
}

void GameDemo::render(sf::RenderTarget& target)
{
    target.clear(sf::Color(0, 0, 0));

    if (m_CurrentState == Gamestate::Menu)
    {
        target.draw(m_Menu);
    }
    if(m_CurrentState == Gamestate::Gameplay)
    {
        target.draw(m_World);
        target.draw(m_MainCharacter);
    }
    if (m_CurrentState == Gamestate::Endgame)
    {
        target.draw(m_Endgame);

    }
    if (m_IsFinished)
    {
        target.draw(m_EndgameText);
    }

}

void GameDemo::renderDebugMenu(sf::RenderTarget& target)
{
    ImGui::Begin("Debug Menu");
    ImGui::Text("Press F1 to close this debug menu");
    ImGui::NewLine();

    if (ImGui::CollapsingHeader("Main character position"))
    {
        const auto& mainCharCenterPos = m_MainCharacter.GetCenter();

        ImGui::Text("X: %f", mainCharCenterPos.x);
        ImGui::Text("Y: %f", mainCharCenterPos.y);
    }

    if (ImGui::CollapsingHeader("Game status"))
    {
        if (m_IsFinished)
        {
            ImGui::TextColored(ImVec4(255.f, 0.f, 0.f, 1.f), "GAME ENDED");
        }
        else
        {
            ImGui::TextColored(ImVec4(0.f, 255.0f, 0.f, 1.f), "GAME IN PROGRESS");
        }
    }

    ImGui::End();
}