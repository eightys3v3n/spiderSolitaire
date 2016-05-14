#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern std::vector< std::vector< Card > > board;

void newGame()
{
  int faceDownCount = 5;

  board.setSize( 10 );

  for ( unsigned int c = 0; c < board.size(); c++ )
  {
    if ( c > 4 )
      faceDownCount = 4;

    board[c].setSize( faceDownCount + 1 );

    for ( unsigned int d = 0; d < faceDownCount; d++ )
    {
      board[d] =
    }
  }
}