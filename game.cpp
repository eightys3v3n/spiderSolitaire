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
      unusedCards.push_back( card.first + ":" + std::to_string(decks) );

  board.resize( 2 );

  std::cout << "original" << std::endl;

  for ( unsigned int x = 0; x < board.size(); x++ )
  {
    if ( x > 4 )
      faceDownCount = 4;

    board[x].resize( faceDownCount + 1 );

    for ( unsigned int y = 0; y <= faceDownCount; y++ )
    {
      if ( y < faceDownCount )
      {
        board[x][y] = randomCard();
        cards[ board[x][y] ].shape.setPosition( sf::Vector2f( x * window.getSize().x * 1/10, y * window.getSize().y * 1/20 ) );
        cards[ board[x][y] ].shape.setTexture( cards[ board[x][y] ].back, true ); // set texture to the card back
      }
      else
      {
        board[x][y] = randomCard();
        cards[ board[x][y] ].shape.setPosition( sf::Vector2f( x * window.getSize().x * 1/10, y * window.getSize().y * 1/20 ) );
        cards[ board[x][y] ].shape.setTexture( &cards[ board[x][y] ].face, true ); // set texture to the card front
      }

      std::cout << x << "," << y << ":" << cards[ board[x][y] ].id  << "(" << cards[ board[x][y] ].shape.getPosition().x << "," << cards[ board[x][y] ].shape.getPosition().y << ")" << std::endl;
    }
  }

  std::cout << "end" << std::endl;
  std::cout << "board" << std::endl;

  for ( unsigned int x = 0; x < board.size(); x++ )
  {
    for ( unsigned int y = 0; y < board[x].size(); y++  )
    {
      std::cout << x << "," << y << ":" << cards[ board[x][y] ].id  << "(" << cards[ board[x][y] ].shape.getPosition().x << "," << cards[ board[x][y] ].shape.getPosition().y << ")" << std::endl;
    }
  }

  std::cout << "end" << std::endl;

  //setCardPositions();
}