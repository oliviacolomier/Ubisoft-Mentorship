#include <stdafx.h>
#include <Engine/Game.h>
#include <Game/GameDemo.h>
#include <AssetManager.h>
int main()
{
    
    GameDemo game{};
    game.RunGameLoop();

    return EXIT_SUCCESS;
}