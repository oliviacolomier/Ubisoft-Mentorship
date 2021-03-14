#include <stdafx.h>
#include <Engine/Game.h>
#include <Game/GameDemo.h>
#include <AssetManager.h>
int main()
{
	sf::RenderWindow m_Window(sf::VideoMode(300, 200), "The Title");

	//Game loop

     while (m_Window.isOpen())
     {
            sf::Event event;
            while (m_Window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                {
                    m_Window.close();
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        m_Window.close();
                    }

                }
            }
     }
	return 0;
}