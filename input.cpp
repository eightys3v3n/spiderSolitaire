#include <iostream>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"
#include "game.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::RectangleShape > layers;
extern std::vector< Card > cards;
extern std::chrono::high_resolution_clock::time_point timeClicked;
extern sf::Vector2i clickedCard;
extern sf::Vector2i moveTo;
extern std::vector< sf::FloatRect > columbs;
extern bool running, playing, holdingCard;
extern unsigned int layersToDraw, completedStacksToDraw;
sf::Vector2f offset;

bool layerClicks( sf::Event* event )
{
  for ( unsigned int l = 0; l < layersToDraw; l++ )
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
      if ( board[x][y]->shape.getGlobalBounds().contains( event->mouseButton.x, event->mouseButton.y ) )
        clickedCard = {.x = (int)x, .y = (int)y};

  if ( clickedCard == sf::Vector2i( -1, -1 ) )
  {
    for ( unsigned int x = 0; x < 10; x++ )
      if ( columbs[x].contains( event->mouseButton.x, event->mouseButton.y) )
        clickedCard = {.x = (int)x, .y = 0};
  }

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
            newGame();

          if ( layerClicks( &event ) )
            newLayer();
          else if ( ( clickedCard = cardClicks( &event ) ) != sf::Vector2i( -1, -1 ) )
          {
            holdingCard = true;
            offset.x = event.mouseButton.x - board[clickedCard.x][clickedCard.y]->shape.getPosition().x;
            offset.y = event.mouseButton.y - board[clickedCard.x][clickedCard.y]->shape.getPosition().y;
            timeClicked = std::chrono::high_resolution_clock::now();
          }
        }
        else if ( event.mouseButton.button == sf::Mouse::Right )
        {
          if ( ( clickedCard = cardClicks( &event ) ) != sf::Vector2i( -1, -1 ) )
          {
            //resizeStack( clickedCard.x );
            //std::cout << getMovableStackSize( clickedCard.x ) << std::endl;
            //std::cout << "+1 completed stacks" << std::endl;
            //completedStacksToDraw++;
          }
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
                holdingCard = false;

                if ( validMove( clickedCard.x, clickedCard.y, moveTo.x ) )
                  moveCards( clickedCard.x, clickedCard.y, moveTo.x );
                else
                  board[clickedCard.x][clickedCard.y]->shape.setPosition( absoluteCardPosition( clickedCard.x, clickedCard.y ) );
              }
            }
            else
            {
              std::cout << "auto-move" << std::endl;
              autoMoveCards( clickedCard.x, clickedCard.y );
            }
          }
        }
        break;

      case sf::Event::MouseMoved:
          if ( holdingCard )
          {
            board[clickedCard.x][clickedCard.y]->shape.setPosition( event.mouseMove.x + offset.x, event.mouseMove.y + offset.y );
          }
        break;
    }
  }
}