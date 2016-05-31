#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::Image textureFile;
extern std::vector< Card > cards;
extern std::vector< Card* > unusedCards;
extern std::vector< std::vector< Card* > > board;
extern std::vector< sf::Texture > textures;
extern sf::RenderWindow window;
extern sf::RectangleShape topBar;
extern int suit;
extern unsigned int completedStacksToDraw;
extern sf::Vector2i cardSize, cardSpacing, cardBoarder, texturesStart;

// create textures from the texture file.
void initializeTextures()
{
  textures.resize(14);

  for ( unsigned int card = 0; card < 13; card++ )
  {
    //std::cerr << "card " << card << " @ " << card * cardSpacing.x + card * cardSize.x + texturesStart.x << "," << suit * cardSpacing.y + suit * cardSize.y + texturesStart.y << std::endl;
    textures[ card ].loadFromImage( textureFile, sf::IntRect(
  /*x*/ card * cardSpacing.x + card * cardSize.x + texturesStart.x,
  /*y*/ suit * cardSpacing.y + suit * cardSize.y + texturesStart.y,
       cardSize.x, cardSize.y
      ) );
  }

  textures[13].loadFromImage( textureFile, sf::IntRect(  texturesStart.x, 4 * cardSize.y + 4 * cardSpacing.y + texturesStart.y, cardSize.x, cardSize.y) ); // card back
}

// create 8 stacks of ace-king in cards and set their face & back texture.
void initializeCards()
{
  cards.resize( 13 * 8 );

  for ( unsigned int d = 0; d < 8; d++ )
  {
    for ( unsigned int c = 0; c < 13; c++ )
    {
      cards[ c + 13 * d ].value = c;
      cards[ c + 13 * d ].face = &textures[c];
      cards[ c + 13 * d ].back = &textures[13];
    }
  }
}

// if the board has no cards, return true.
bool finishedGame()
{
  for ( unsigned int x = 0; x < board.size(); x++ )
    if ( board[x].size() != 0 )
      return false;

  std::cout << "game finished!" << std::endl;
  return true;
}

// returns a pointer to a random card in unusedCards.
Card* randomCard()
{
  int n = rand() % unusedCards.size();
  Card* returnCard = unusedCards[n];

  unusedCards.erase( unusedCards.begin() + n );

  return returnCard;
}

// returns the position in pixels of the board position x,y.
sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y) // returns the position of a card at board position (x,y)
{
  sf::Vector2f r;

  r.x = ( x * window.getSize().x * .1 ) + ( .5 * ( window.getSize().x / 10 - 72 ) );
  r.y = y * ( window.getSize().y / 20 ) + topBar.getSize().y ;

  return r;
}

// returns the position in pixels of card x,y-1, + ( 1/20 of the window height ).
sf::Vector2f relativeCardPosition( unsigned int x, unsigned int y )
{
  sf::Vector2f r;

  r.x = ( x * window.getSize().x * .1 ) + ( .5 * ( window.getSize().x / 10 - 72 ) );

  if ( y == 0 )
    r.y = topBar.getSize().y;
  else if ( board[x].size() == y )
    r.y = board[x][ board[x].size() - 1 ]->shape.getPosition().y + window.getSize().y / 20;
  else if ( y > 0 && board[x].size() > y )
    r.y = board[x][ y - 1 ]->shape.getPosition().y + window.getSize().y / 20;
  else
    r.y = y * ( window.getSize().y / 20 ) + topBar.getSize().y ;

  return r;
}

// returns true if the card can be moved; all the cards after card x,y are stacked correctly.
// make this return true all the time to allow moving cards to any stack you want regardless of the card order.
bool movableStack( unsigned int x, unsigned int y )
{
  if ( board[x].size() - 1 == y )
    return true;

  for ( unsigned int c = y + 1; c < board[x].size(); c++ )
  {
    if ( board[x][ c - 1 ]->value - 1 != board[x][c]->value )
      return false;
  }

  return true;
}

// returns true if the card(s) at and on top of card x,y can be moved to columb newX.
bool validMove( unsigned int x, unsigned int y, unsigned int newX )
{
  if ( x == newX )
    return false;

  if ( !movableStack( x, y ) )
    return false;

  if ( board[newX].size() == 0 )
    return true;

  if ( board[x][y]->value + 1 == board[newX][ board[newX].size() - 1 ]->value )
    return true;
  else
    return false;

  return false;
}

// removes completed stacks (ace-king).
void completeStack( unsigned int x )
{
  if ( board[x].size() < 13 )
    return;

  for ( int c = 1; c < 14; c++ )
  {
    //std::cout << "checking " << board[x].size() - c << ":" << board[x][board[x].size() - c]->value << " != " << c << std::endl;
    if ( board[x][ board[x].size() - c ]->value != c - 1 )
      return;
  }

  //std::cout << "complete stack at " << x << std::endl;
  board[x].resize( board[x].size() - 13 );

  if ( board[x].size() > 0 )
    if ( board[x][ board[x].size() - 1 ]->shape.getTexture() == board[x][ board[x].size() - 1 ]->back )
      board[x][ board[x].size() - 1 ]->shape.setTexture( board[x][ board[x].size() - 1 ]->face );

  completedStacksToDraw++;

  finishedGame();
}

// returns the number of correctly stacked cards on columb x.
unsigned int getMovableStackSize( unsigned int x )
{
  unsigned int stackSize = 1;

  if ( board[x].size() == 0 )
    return 0;

  for ( unsigned int y = board[x].size() - 1; y > 0; y-- )
  {
    if ( board[x][y]->value + 1 != board[x][ y - 1 ]->value || board[x][y]->shape.getTexture() == board[x][y]->back )
      break;

    stackSize++;
  }

  return stackSize;
}

// (de)compress stacks to fit on the screen.
void resizeStack( unsigned int x )
{
  unsigned int movableStackSize = getMovableStackSize( x );

  // i don't remember what this is for so i'll leave it here for now, i'll remove it if nothing breaks.
  //if ( board[x][ board[x].size() - 1 ]->shape.getPosition().y + window.getSize().y / 20 <= window.getSize().y + topBar.getSize().y )
    //return;

  // all cards fit
  if ( window.getSize().y - topBar.getSize().y - board[x].size() * window.getSize().y / 20 >= 0 )
  {
    for ( unsigned int y = 1; y < board[x].size(); y++ )
      board[x][y]->shape.setPosition( absoluteCardPosition( x, y ) );
  }
  // the movable stack fits when all other cards are compressed
  else if ( ( window.getSize().y - topBar.getSize().y ) - ( movableStackSize * window.getSize().y / 20 ) - ( ( board[x].size() - movableStackSize ) * window.getSize().y / 40 ) >= window.getSize().y / 20 )
  {
    std::cout << "half shrunk " << x << std::endl;

    for ( unsigned int y = 0; y < board[x].size(); y++ )
    {
      sf::Vector2f cachePosition = relativeCardPosition( x, y );

      // if the card is under the second card in the movable stack
      if ( y < board[x].size() + 1 - movableStackSize && y != 0 )
        cachePosition.y -= window.getSize().y / 40;

      board[x][y]->shape.setPosition( cachePosition );
    }
  }
  // the movable stack fits if all other cards are hidden
  else if ( window.getSize().y - topBar.getSize().y - movableStackSize * window.getSize().y / 20 >= 0 )
  {
    std::cout << "stack only " << x << std::endl;

    for ( unsigned int y = 0; y < board[x].size(); y++ )
    {
      if ( y < board[x].size() - movableStackSize - 1 )
        board[x][y]->shape.setPosition( absoluteCardPosition( x, 0 ) );
      else
        board[x][y]->shape.setPosition( absoluteCardPosition( x, movableStackSize - ( board[x].size() - y ) ) );
    }
  }
  else
  {
    std::cout << "screen is too small mate" << std::endl;
  }
}

// set all the cards to the un-compressed position, then re-compress them.
void resetStack( sf::Vector2i card )
{
  for ( unsigned int y = card.y; y < board[card.x].size(); y++ )
    board[ card.x ][ y ]->shape.setPosition( absoluteCardPosition( card.x, y ) );

  resizeStack( card.x );
}

// moves the card(s) on top of, and including, card x,y onto the top of stack newX.
void moveCards( unsigned int x, unsigned int y, unsigned int newX )
{
  for ( unsigned int i = y; i < board[x].size(); i++ )
  {
    board[x][i]->shape.setPosition( relativeCardPosition( newX, board[newX].size() ) );
    board[newX].push_back( board[x][i] );
    board[x].erase( board[x].begin() + i );
    i--; // is this sloppy? i feel like i should have found a way to do this without changing i.
  }

  if ( board[x].size() > 0 )
    if ( board[x][ y - 1 ]->shape.getTexture() == board[x][ y - 1 ]->back )
      board[x][ y - 1 ]->shape.setTexture( board[x][ y - 1 ]->face );

  if ( board[ newX ].size() > 12 )
    completeStack( newX );

  resizeStack( newX );
  resizeStack( x );
}

// moves card(s) at, and on top of, position x,y to the "best" position on the board.
// moves to the left most columb in the case of a tie.
// moves to the columb that will create the largest stack of correctly stacked cards.
void autoMoveCards( unsigned int x, unsigned int y )
{
  std::vector< sf::Vector2i > validMoves; // .x is the position, .y is the size of the stack

  if ( ! movableStack( x, y ) )
    return;

  for ( unsigned int i = 0; i < board.size(); i++ )
    if ( i != x )
      if ( validMove( x, y, i ) )
        validMoves.push_back( sf::Vector2i( i, getMovableStackSize(i) ) );

  sf::Vector2i bestMove( -1, -1 );
  for ( unsigned int i = 0; i < validMoves.size(); i++ )
  {
    //std::cout << bestMove.x << ":" << bestMove.y << " & " << validMoves[i].x << ":" << validMoves[i].y << std::endl;

    if ( bestMove.y < validMoves[i].y )
    {
      //std::cout << "new best move" << std::endl;
      bestMove = validMoves[i];
    }
  }

  if ( bestMove.x != -1 )
    moveCards( x, y, bestMove.x );
}