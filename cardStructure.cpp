#include "cardStructure.hpp"

Card::Card()
{
  back = &cardBack;
  //shape.setFillColor( sf::Color::Black );
  shape.setSize( sf::Vector2f(72,96) );
  shape.setTexture( back, true );
}
