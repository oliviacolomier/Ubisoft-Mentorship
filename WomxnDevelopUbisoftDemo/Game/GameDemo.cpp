#include "stdafx.h"
#include "GameDemo.h"


//where window is created - constructor//
GameDemo::GameDemo(): Game{ "Game Demo" }
//end of constructor//
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
}

void GameDemo::Update(float deltaTime)
{
  
    m_MainCharacter.jump();
    m_MainCharacter.Update(deltaTime);
   
}

void GameDemo::Render(sf::RenderTarget& target) //only rendering target?? no the window??
{
    Camera::Render(target);
    //const auto& main_position = m_MainCharacter.GetCenter();
   // sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));
   // view.setCenter(main_position);
   // target.clear(sf::Color(0, 0, 0));
   //target.setView(view);
  // target.draw(m_MainCharacter);

    //if (m_IsFinished)
    //{
       // target.draw(m_EndgameText);
    //}
}

void GameDemo::RenderDebugMenu(sf::RenderTarget& target)
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