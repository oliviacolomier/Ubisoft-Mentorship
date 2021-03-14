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
                if (event.type == sf::Event::EventType::Closed)
                    m_Window.close();
            }
           //Update the scene

            //Render Cycle
            m_Window.clear(sf::Color::Black);

            //render the objects

            m_Window.display();


     }
	return 0;
}