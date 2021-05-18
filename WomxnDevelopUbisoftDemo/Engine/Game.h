#pragma once

class Game
{
public:
    Game(const char* windowTitle);
    virtual ~Game();

    void runGameLoop();

protected:
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void renderDebugMenu(sf::RenderTarget& target) = 0;

private:
    sf::RenderWindow m_Window;
};