#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton;
extern std::vector< sf::RectangleShape > layers;
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

std::string cardClicks( sf::Event* event )
{
  return "none";
}

void input()
{
  sf::Event event;
  std::string clickedCard = "";

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
          else if ( ( clickedCard = cardClicks( &event ) ) != "none" )
            std::cout << "card clicked " << clickedCard << std::endl;
        }
        break;
    }
  }
}