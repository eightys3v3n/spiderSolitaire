#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton, topBar;
extern std::vector< sf::RectangleShape > layers, completedStacks;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::Texture > textures;
extern std::vector< Card > cards;
extern sf::Vector2i clickedCard;
extern int suit;
extern bool playing, holdingCards;
extern unsigned int layersToDraw, completedStacksToDraw;

void initializeGraphics()
{
  newGameButton.setSize( sf::Vector2f( window.getSize().x * 1/10, window.getSize().y * 1/20 ) );
  newGameButton.setPosition( sf::Vector2f( window.getSize().x * 1/2 - newGameButton.getSize().x / 2, window.getSize().y * 2/49 ) );
  newGameButton.setFillColor( sf::Color::Blue );

  topBar.setPosition( sf::Vector2f(0,0) );
  topBar.setSize( sf::Vector2f( window.getSize().x, window.getSize().y * 1/7 ) );
  topBar.setFillColor( sf::Color::Black );

  for ( unsigned int l = 0; l < layers.size(); l++ )
  {
    layers[l].setPosition( 10 * l + 10, window.getSize().y * 1/49 );
    layers[l].setSize( sf::Vector2f( window.getSize().x * 1/20, window.getSize().y * 5/49 ) );
    layers[l].setTexture( &textures[13] );
  }

  for ( unsigned int c = 0; c < completedStacks.size(); c++ )
  {
    completedStacks[c].setPosition( window.getSize().x - ( 10 * c ) - 52, window.getSize().y * 1/49 );
    completedStacks[c].setSize( sf::Vector2f( window.getSize().x * 1/20, window.getSize().y * 5/49 ) );
    completedStacks[c].setTexture( &textures[13] );
  }
}

void drawLayers()
{
  if ( layersToDraw > 5 )
  {
    std::cout << "more than 5 layers left?\nwhat kind of wizard ARE YOU?!" << std::endl;
    return;
  }

  for ( unsigned int l = 0; l < layersToDraw; l++ )
    window.draw( layers[l] );
}

void drawCompletedStacks()
{
  if ( completedStacksToDraw > 8 )
  {
    std::cout << "more than 8 completed stacks?!\nare you a wizard?" << std::endl;
    return;
  }

  for ( unsigned int c = 0; c < completedStacksToDraw; c++ )
    window.draw( completedStacks[c] );
}

void drawCards()
{
  for ( unsigned int x = 0; x < board.size(); x++ )
    for ( unsigned int y = 0; y < board[x].size(); y++ )
      window.draw( board[x][y]->shape );
}

void drawFloatingCards()
{
  window.draw( board[clickedCard.x][clickedCard.y]->shape );
}

void draw()
{
  window.clear( sf::Color::Green );
  // window.clear( sf::Color::Black );
  // window.draw( background );

  //window.draw( topBar );
  window.draw( newGameButton );

  drawLayers();
  drawCompletedStacks();
  drawCards();

  // draw the floating cards again so their on top.
  if ( holdingCards )
    drawFloatingCards();

  window.display();
}