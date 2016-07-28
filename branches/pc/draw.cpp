#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::RenderWindow window;
extern sf::RectangleShape newGameButton, topBar;
extern sf::Image textureFile;
extern sf::Texture newGameTexture;
extern std::vector< sf::RectangleShape > layers, completedStacks;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::Texture > textures;
extern std::vector< Card > cards;
extern sf::Vector2i clickedCard;
extern int suit;
extern bool playing, holdingCards;
extern unsigned int layersToDraw, completedStacksToDraw;

// sets position & texture of menu elements.
void initializeGraphics()
{
  newGameButton.setSize( sf::Vector2f( window.getSize().x * 1/8, window.getSize().y * 1/16 ) );
  newGameButton.setPosition( sf::Vector2f( window.getSize().x * 1/2 - newGameButton.getSize().x / 2, window.getSize().y * 2/49 ) );
  newGameTexture.loadFromImage( textureFile, sf::IntRect(74,389,128,32) );
  newGameButton.setTexture( &newGameTexture, true );

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

// draw how many more layers the player has left.
void drawLayers()
{
  for ( unsigned int l = 0; l < layersToDraw; l++ )
    window.draw( layers[l] );
}

// draws how many stacks the player has completed.
void drawCompletedStacks()
{
  for ( unsigned int c = 0; c < completedStacksToDraw; c++ )
    window.draw( completedStacks[c] );
}

// draws all the cards on the board.
void drawCards()
{
  for ( unsigned int x = 0; x < board.size(); x++ )
    for ( unsigned int y = 0; y < board[x].size(); y++ )
      window.draw( board[x][y]->shape );
}

// draws the cards that are being dragged.
void drawFloatingCards()
{
  for ( unsigned int c = clickedCard.y; c < board[clickedCard.x].size(); c++ )
    window.draw( board[clickedCard.x][c]->shape );
}

// re-draws all elements.
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