#include "stdafx.h"
#include "GameDemo.h"

GameDemo::GameDemo()
    : Game{ "Game Demo" }
    , m_MainCharacter{}

{
    m_CurrentState = Gamestate::Menu;
   // m_Menu.playMusic();

  
    

}

void GameDemo::update(float deltaTime)
{

   switch (m_CurrentState)
   {

    case Gamestate::Gameplay:
    {
        m_MainCharacter.update(deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            m_CurrentState = Gamestate::Menu;
        }

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.rect1.getGlobalBounds()))
        {
            m_Endgame.playDeathSound();
            m_CurrentState = Gamestate::Endgame;
        }

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.rect2.getGlobalBounds()))
        {
            m_Endgame.playDeathSound();
            m_CurrentState = Gamestate::Endgame;
        }
        if (m_MainCharacter.GetBoundingBox().intersects(m_World.rect3.getGlobalBounds()))
        {
            m_CurrentState = Gamestate::Dialogue;
        }
        
        break;
    }

    case Gamestate::Dialogue:
    { 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_MainCharacter.resetPosition();
            m_CurrentState = Gamestate::Gameplay;
        }

        break;
    }

    case Gamestate::Menu:
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            m_CurrentState = Gamestate::Gameplay;
        }

        break;
    }

    case Gamestate::Endgame:
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_MainCharacter.resetPosition();
            m_CurrentState = Gamestate::Menu;

        }

        break;

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
    if (m_CurrentState == Gamestate::Dialogue)
    {
        target.draw(m_World);
        target.draw(m_MainCharacter);
        target.draw(m_Dialogue);
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

    ImGui::End();
}