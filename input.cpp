#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::RectangleShape > layers;
extern std::vector< Card > cards;
extern bool running, playing;

bool layerClicks( sf::Event* event )
{
  for ( unsigned int l = 0; l < layers.size(); l++ )
  {
    if ( layers[l].getGlobalBounds().contains( sf::Vector2f( event->mouseButton.x, event->mouseButton.y ) ) )
      return true;
  }

  return false;
}

sf::Vector2i cardClicks( sf::Event* event )
{
  sf::Vector2i clickedCard( -1, -1 );

  for ( unsigned int x = 0; x < board.size(); x++ )
    for ( unsigned int y = 0; y < board[x].size(); y++ )
      if ( board[x][y]->shape.getGlobalBounds().contains( sf::Vector2f( event->mouseButton.x, event->mouseButton.y ) ) )
        clickedCard = {.x = (int)x, .y = (int)y};

  return clickedCard;
}

void input()
{
  sf::Event event;
  sf::Vector2i clickedCard;

  while( window.pollEvent( event ) )
  {
    switch( event.type )
    {
      case sf::Event::Closed:
        running = false;
        break;

      case sf::Event::MouseButtonPressed:
        if ( event.mouseButton.button == sf::Mouse::Left )
        {
          if ( newGameButton.getGlobalBounds().contains( sf::Vector2f( event.mouseButton.x, event.mouseButton.y ) ) )
            std::cout << "new game" << std::endl;

          if ( layerClicks( &event ) )
            std::cout << "new layer" << std::endl;
          else if ( ( clickedCard = cardClicks( &event ) ) != sf::Vector2i( -1, -1 ) )
          {
            std::cout << "card clicked " << board[clickedCard.x][clickedCard.y]->value << std::endl;
            std::cout << movableStack( clickedCard.x, clickedCard.y ) << std::endl;
          }
        }
        break;
    }
  }
}