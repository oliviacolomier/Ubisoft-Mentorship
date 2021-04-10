#include "stdafx.h"
#include "Dialogue.h"


Dialogue::Dialogue()
{

}

void Dialogue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_MainCharacter);
	target.draw(m_World);
}
