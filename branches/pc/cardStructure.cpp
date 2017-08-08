#include "gameClass.hpp"

Game::Card::Card(unsigned int x, unsigned int y)
{
  shape.setPosition( sf::Vector2f(0,0) );
  shape.setSize( sf::Vector2f(x, y) );
}