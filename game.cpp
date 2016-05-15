#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"

extern std::vector< std::vector< Card* > > board;
extern std::vector< Card* > unusedCards, playingCards, discardCards;
extern std::map< std::string, Card* > cards;

void newGame()
{
  unsigned int faceDownCount = 5;

  discardCards.resize( 0 );
  unusedCards.resize( 0 );

  for ( auto& card : cards )
    unusedCards.push_back( card.second );

  board.resize( 10 );

  for ( unsigned int c = 0; c < board.size(); c++ )
  {
    if ( c > 4 )
      faceDownCount = 4;

    board[c].resize( faceDownCount );

    for ( unsigned int d = 0; d < faceDownCount; d++ )
    {
      board[c][d] = randomCard();
      board[c][d]->shape.setTexture( board[c][d]->back, true );
    }

    board[c].push_back( randomCard() );
    board[c][ board[c].size() - 1 ]->shape.setTexture( &board[c][ board[c].size() - 1 ]->face, true );
  }
}