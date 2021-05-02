#include "stdafx.h"
#include "GameDemo.h"

GameDemo::GameDemo()
    : Game{ "Game Demo" }
    , m_MainCharacter{}

{
    m_CurrentState = Gamestate::Menu;
    m_Menu.playMusic();
    m_CurrentWorld = &m_World;
    level2 = false;
    endGame = false;
    gotWater = false;
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

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.m_BuildingRect.getGlobalBounds()))
        {
                m_CurrentWorld->createWorld("level2");
                m_MainCharacter.resetPosition(sf::Vector2f(40.0f, 400.0f));
                level2 = true;
                m_World.playBuildingMusic();
                m_Menu.stopMusic();  
        }

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.m_TreeRect.getGlobalBounds()))
        {
            m_CurrentState = Gamestate::Dialogue;
        }

        if (m_MainCharacter.GetBoundingBox().intersects(m_World.m_DoorRect.getGlobalBounds()))
        {
            if (gotWater == true)
            {
                m_CurrentWorld->createWorld("level1");
                m_World.treeResetPositon(sf::Vector2f(650.0f, 320.0f));
                m_World.treeRectResetPoisiton(sf::Vector2f(550.0f, 320.0f));
                m_MainCharacter.resetPosition(sf::Vector2f(70.0f, 30.0f));
                m_Dialogue.updateDialogue("Thank you for the water. Have a good day.");
                m_World.stopBuildingMusic();
                m_Menu.playMusic();
            }
  
            level2 = false;
            endGame = true;

        }
        if (m_MainCharacter.GetBoundingBox().intersects(m_World.m_WaterRect.getGlobalBounds()))
        {
            m_World.waterResetPosition(sf::Vector2f(-100.0f,-100.0f));
            m_MainCharacter.updateCharacterTexture();
            gotWater = true;
        }

        break;
    }

    case Gamestate::Dialogue:
    { 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_MainCharacter.resetPosition(sf::Vector2f(520.0f,360.0f));
            m_CurrentState = Gamestate::Gameplay;

            if (endGame == true)
            {
                m_World.updateTree();
                m_CurrentState = Gamestate::Endgame;
            }
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            m_MainCharacter.resetPosition(sf::Vector2f(400.0f,300.0f));
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
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            target.draw(m_Instruction);
        }
        else
            target.draw(m_Menu);
    }
    if(m_CurrentState == Gamestate::Gameplay)
    {
      
         target.draw(m_World);
         target.draw(m_MainCharacter);
  
    }
    if (m_CurrentState == Gamestate::Endgame)
    {
        target.draw(m_World);
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