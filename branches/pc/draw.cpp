#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "gameClass.hpp"

// sets position & texture of menu elements.

void Game::resizeNewLayers()
{
  for ( unsigned int l = 0; l < layers.size(); l++ )
  {
    sf::Vector2f p;

    // height is relative to the bar.
    p.y = topBar.getSize().y * 3/4;

    // width is relative to height to keep aspect ratio of the textures.
    p.x = p.y * texture_loader.cardSize.x / texture_loader.cardSize.y;

    layers[l].setSize(p);

    // y position is in the middle of the top bar.
    p.y = (topBar.getSize().y / 2) - (layers[l].getSize().y / 2);

    // always 1/24th the screen witdh away from the edge.
    p.x = window.getSize().x / 24;

    // offset by 1/4th the width from the previous shape.
    p.x += (layers[l].getSize().x / 4) * l;
    layers[l].setPosition(p);
  }
}

void Game::resizeCompletedStacks()
{
  for ( unsigned int c = 0; c < completedStacks.size(); c++ )
  {
    sf::Vector2f p;

    // height is relative to the bar.
    p.y = topBar.getSize().y * 3/4;

    // width is relative to height to keep aspect ratio of the textures.
    p.x = p.y * texture_loader.cardSize.x / texture_loader.cardSize.y;
    completedStacks[c].setSize(p);

    // y position is in the middle of the top bar.
    p.y = (topBar.getSize().y / 2) - (completedStacks[c].getSize().y / 2);

    // always 1/24th of the screen width away from the edge.
    p.x = window.getSize().x - (window.getSize().x / 24) - completedStacks[c].getSize().x;

    // offset by 1/4 the widthfrom the previous shape.
    p.x -= (completedStacks[c].getSize().x / 4) * c;
    completedStacks[c].setPosition(p);
  }
}

void Game::resizeTopBar(unsigned int n = 6)
{
  sf::Vector2f p;

  topBar = sf::RectangleShape();

  topBar.setPosition( sf::Vector2f(0.,0.) );

  p.x = window.getSize().x;
  p.y = window.getSize().y / n;

  topBar.setSize(p);

  resizeNewLayers();
  resizeCompletedStacks();
}

void Game::resizeElements()
{
  // addP("resizeElements()");

  if (window.getSize().x > window.getSize().y)
    resizeTopBar();
  else
    resizeTopBar(8);


  // removeP();
}

void Game::loadTextures()
{
  topBar.setFillColor( sf::Color::Black );

  // newGameButton texture is at 74x389 in the textures.png and it is 128x32 pixels.
  // sf::IntRect texture_rect = sf::IntRect(74,389,128,32);
  // newGameTexture.loadFromImage( texture_loader.textureFile, texture_rect );
  newGameButton.setTexture( &texture_loader.newGameTexture, true );

  for (auto& layer:layers)
  {
    // texture 13 is always the card back.
    layer.setTexture( &texture_loader.textures[13] );
  }

  for (auto& stack:completedStacks)
  {
    // texture 13 is always the card back.
    stack.setTexture( &texture_loader.textures[13] );
  }
}

void Game::initializeGraphics()
{
  // addP("initializeGraphics()");
  resizeElements();
  loadTextures();
  // removeP();
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
int Game::draw()
{
  window.clear( sf::Color::Green );

  drawLayers();
  drawCompletedStacks();
  drawCards();

  // draw the floating cards again so their on top.
  if ( holdingCards )
    drawFloatingCards();

  window.display();

  return 0;
}