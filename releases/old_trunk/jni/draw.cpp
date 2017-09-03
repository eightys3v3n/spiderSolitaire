#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "gameClass.hpp"

// sets position & texture of menu elements.
void Game::initializeGraphics()
{
  {
    sf::Vector2f p;

    p.x = window.getSize().x / 8;
    p.y = 32/128 * p.x;
    newGameButton.setSize(p);

    p.x = window.getSize().x * 1/2 - newGameButton.getSize().x / 2;
    p.y = window.getSize().y * 2/49;
    newGameButton.setPosition(p);

    newGameTexture.loadFromImage( textureFile, sf::IntRect(74,389,128,32) );
    newGameButton.setTexture( &newGameTexture, true );
  }

  {
    sf::Vector2f p;

    topBar.setPosition( sf::Vector2f(0,0) );

    p.x = window.getSize().x;
    p.y = window.getSize().y / 6;
    topBar.setSize(p);
    topBar.setFillColor( sf::Color::Black );
  }

  for ( unsigned int l = 0; l < layers.size(); l++ )
  {
    sf::Vector2f p;

    p.x = (window.getSize().x / 60) * l + (window.getSize().x / 24);
    p.y = window.getSize().y * 2/49;
    layers[l].setPosition(p);

    layers[l].setSize( sf::Vector2f( window.getSize().x * 1/20, window.getSize().y * 5/49 ) );
    layers[l].setTexture( &textures[13] );
  }

  for ( unsigned int c = 0; c < completedStacks.size(); c++ )
  {
    sf::Vector2f p;

    p.x = window.getSize().x - ( (window.getSize().x / 60) * c ) - (window.getSize().x / 20) - (window.getSize().x / 24);
    p.y = window.getSize().y * 2/49 ;
    completedStacks[c].setPosition(p);

    p.x = window.getSize().x / 20;
    p.y = window.getSize().y * 5/49;
    completedStacks[c].setSize(p);
    completedStacks[c].setTexture( &textures[13] );
  }
}

// draw how many more layers the player has left.
void Game::drawLayers()
{

  for ( unsigned int l = 0; l < layersToDraw; l++ )
    window.draw( layers[l] );
}

// draws how many stacks the player has completed.
void Game::drawCompletedStacks()
{
  for ( unsigned int c = 0; c < completedStacksToDraw; c++ )
    window.draw( completedStacks[c] );
}

// draws all the cards on the board.
void Game::drawCards()
{
  for ( unsigned int x = 0; x < board.size(); x++ )
    for ( unsigned int y = 0; y < board[x].size(); y++ )
      window.draw( board[x][y]->shape );
}

// draws the cards that are being dragged.
void Game::drawFloatingCards()
{

  for ( unsigned int c = clickedCard.y; c < board[clickedCard.x].size(); c++ )
    window.draw( board[clickedCard.x][c]->shape );
}

// re-draws all elements.
void Game::draw()
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