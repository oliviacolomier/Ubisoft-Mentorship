#include "stdafx.h"
#include<iostream>
#include "GameDemo.h"



//where window is created - constructor//
GameDemo::GameDemo() : Game{ "Game Demo" }
{
    m_IsFinished = false;
    m_world = new World(&m_character);
    m_world->CreatePlatform();//sf::Vector2f(500.0f, 300.0f), sf::Vector2f(100.0f, 100.0f));
   

}

void GameDemo::Update(float deltaTime)
{
 
    m_world->collide(&m_character, platform); //prints yes if the two collide
    m_character.Update(deltaTime);
    m_character.jump();
   
}

void GameDemo::Render(sf::RenderTarget& target) 
{

    target.clear(sf::Color(0, 0, 0));
    target.draw(*m_world);
    target.draw(platform);
    target.draw(m_character);

}

void GameDemo::RenderDebugMenu(sf::RenderTarget& target)
{
    ImGui::Begin("Debug Menu");
    ImGui::Text("Press F1 to close this debug menu");
    ImGui::NewLine();

    if (ImGui::CollapsingHeader("Main character position"))
    {
        
        const auto& mainCharCenterPos = m_character.GetCenter();
        ImGui::Text("X: %f", mainCharCenterPos.x);
        ImGui::Text("Y: %f", mainCharCenterPos.y);
    }

    ImGui::NewLine();

  

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

