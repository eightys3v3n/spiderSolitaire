#include <iostream>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::RectangleShape > layers;
extern std::vector< Card > cards;
extern std::chrono::high_resolution_clock::time_point timeClicked;
extern sf::Vector2i clickedCard;
extern sf::Vector2i moveTo;
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
            timeClicked = std::chrono::high_resolution_clock::now();
        }
        break;

      case sf::Event::MouseButtonReleased:
        if ( event.mouseButton.button == sf::Mouse::Left )
        {
          if ( clickedCard != sf::Vector2i( -1, -1 ) )
          {
            if( std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now() - timeClicked ).count() > 120 )
            {
              if ( ( moveTo = cardClicks( &event ) ) != sf::Vector2i( -1, -1 ) )
              {
                if ( validMove( clickedCard.x, clickedCard.y, moveTo.x ) )
                  moveCard( clickedCard.x, clickedCard.y, moveTo.x );
                else
                  std::cout << "can't move (" << clickedCard.x << "," << clickedCard.y << ") onto (" << moveTo.x << "," << moveTo.y << ")" << std::endl;

              }
            }
          }
        }
        break;
    }
  }
}