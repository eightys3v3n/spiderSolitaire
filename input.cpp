#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

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

Card* cardClicks( sf::Event* event )
{
  Card* clickedCard = nullptr;

  for ( unsigned int x = 0; x < board.size(); x++ )
  {
    for ( unsigned int y = 0; y < board[x].size(); y++ )
    {
      if ( board[x][y]->shape.getGlobalBounds().contains( sf::Vector2f( event->mouseButton.x, event->mouseButton.y ) ) )
      {
        clickedCard = board[x][y];
        std::cout << "clicked card " << x << "," << y << std::endl;
      }
    }
  }

  return clickedCard;
}

void input()
{
  sf::Event event;
  Card* clickedCard = nullptr;

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
            std::cout << "newGameButton clicked" << std::endl;

          if ( layerClicks( &event ) )
            std::cout << "new layer clicked" << std::endl;
          else if ( ( clickedCard = cardClicks( &event ) ) != nullptr )
            std::cout << "card clicked " << clickedCard->value << std::endl;
        }
        break;
    }
  }
}