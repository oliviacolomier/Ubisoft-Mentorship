#pragma once

#include <Engine/Game.h>
#include <Game/MainCharacter.h>
#include <Game/SideCharacter.h>
#include <Camera.h>


class GameDemo :  public Game, public Camera //inheritance
{
public:

	//functions here override functions in game.h
	GameDemo();
	void Update() override; //INCLUDE MOVEMENT
	void Render(sf::RenderTarget& target) override; //DRAW THE CHARACTER
	void RenderDebugMenu() override;

};