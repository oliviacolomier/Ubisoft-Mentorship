#pragma once
#include <vector>
class Camera: public sf::Drawable //: public MainCharacter
{
public:
	Camera();
	//MainCharacter mainCharacter;

	//virtual void Render(sf::RenderTarget& sprite_character);
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	std::string sprite_name;

	sf::Vector2f m_Position{ sf::Vector2f(100.0f,500.0f) };
	sf::Sprite mainCharacter;
	sf::Sprite sideCharacter;
	sf::RectangleShape rect;
	
	std::vector<sf::Drawable> sprites;
	void sprite_manager();

	void Render();
	


	


};