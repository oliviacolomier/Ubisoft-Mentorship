#include "stdafx.h"
#include "GameDemo.h"
#include "camera.h"

GameDemo::GameDemo() : Game{ "Game Demo" }
{

}

void GameDemo::Update()
{
	
}

void GameDemo::Render(sf::RenderTarget& target)
{
	Camera::Render();


}

