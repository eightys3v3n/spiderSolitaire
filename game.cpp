#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"
#include "cards.hpp"

extern std::vector< std::vector< std::string > > board;
extern std::vector< std::string > unusedCards, playingCards, discardCards;
extern std::map< std::string, Card > cards;
extern sf::RenderWindow window;

void newGame()
{
  unsigned int faceDownCount = 5;

  discardCards.resize( 0 );
  unusedCards.resize( 0 );

  for ( unsigned int decks = 0; decks < 8; decks++ )
    for ( auto& card : cards )
      unusedCards.push_back( card.first );

  board.resize( 10 );

  for ( unsigned int c = 0; c < board.size(); c++ )
  {
    if ( c > 4 )
      faceDownCount = 4;

    board[c].resize( faceDownCount );

    for ( unsigned int d = 0; d < faceDownCount; d++ )
    {
      board[c][d] = randomCard();
      cards[ board[c][d] ].shape.setPosition( sf::Vector2f( c * window.getSize().x * 1/10, d * window.getSize().y * 1/20 ) );
      cards[ board[c][d] ].shape.setTexture( cards[ board[c][d] ].back, true ); // set texture to the card back
    }

    board[c].push_back( randomCard() );
    cards[ board[c][ board[c].size() - 1 ] ].shape.setPosition( sf::Vector2f( c * window.getSize().x * 1/10, ( board[c].size() - 1 ) * window.getSize().y * 1/20 ) );
    cards[ board[c][ board[c].size() - 1 ] ].shape.setTexture( &cards[ board[c][ board[c].size() - 1 ] ].face, true ); // set texture to the card front
  }

  //setCardPositions();
}