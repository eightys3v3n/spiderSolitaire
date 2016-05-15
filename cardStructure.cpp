#include "cardStructure.hpp"

Card::Card()
{
  back = &cardBack;
  shape.setPosition( sf::Vector2f(0,0) );
  shape.setSize( sf::Vector2f(72,96) );
  shape.setTexture( back, true );
}
