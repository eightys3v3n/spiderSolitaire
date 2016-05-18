#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"

extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::RectangleShape > layers;
extern std::vector< Card* > unusedCards;
extern std::vector< Card > cards;
extern sf::RenderWindow window;
extern unsigned int layersToDraw, completedStacksToDraw;

void newGame()
{
  unsigned int faceDownCount = 5;

  unusedCards.resize( 0 );
  layersToDraw = 5;
  completedStacksToDraw = 0;

  for ( unsigned int c = 0; c < cards.size(); c++ )
    unusedCards.push_back( &cards[c] );

  board.resize( 10 );

  for ( unsigned int x = 0; x < board.size(); x++ )
  {
    if ( x > 3 )
      faceDownCount = 4;

    board[x].resize( faceDownCount );

    for ( unsigned int y = 0; y < faceDownCount; y++ )
    {
      board[x][y] = randomCard();
      board[x][y]->shape.setPosition( absoluteCardPosition( x, y ) );
      board[x][y]->shape.setTexture( board[x][y]->back, true ); // set texture to the card back
    }

    board[x].push_back( randomCard() );
    board[x][ board[x].size() - 1 ]->shape.setPosition( absoluteCardPosition( x, board[x].size() - 1 ) );
    board[x][ board[x].size() - 1 ]->shape.setTexture( board[x][ board[x].size() - 1 ]->face, true ); // set texture to the card front
  }
}

void newLayer()
{
  Card* cardCache;

  for ( unsigned int x = 0; x < board.size(); x++ )
    if ( board[x].size() == 0 )
      return;

  if ( layersToDraw != 0 )
  {
    for ( unsigned int x = 0; x < board.size(); x++ )
    {
      cardCache = randomCard();
      board[x].push_back( cardCache );
      cardCache->shape.setPosition( absoluteCardPosition( x, board[x].size() - 1 ) );
      cardCache->shape.setTexture( cardCache->face );

      if ( board[x].size() >= 13 )
        completeStack( x );
      resizeStack( x );
    }

    layersToDraw--;
  }
}