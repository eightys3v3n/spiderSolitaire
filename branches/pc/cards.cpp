#include <iostream>
#include <map>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "gameClass.hpp"

void Game::scaleCards()
{
  for (auto& card: cards)
  {
    // scale card width relative to the screen width.
    // 1/12th so there are 2/12ths of the screen width used for spacing the cards out.
    if (card.shape.getSize().x != window.getSize().x / 12)
      card.shape.setSize( sf::Vector2f(window.getSize().x / 12, card.shape.getSize().y) );

    // scale y to correct perportions relative to x
    if (card.shape.getSize().y != (texture_loader.cardSize.y * card.shape.getSize().x) / texture_loader.cardSize.x)
      card.shape.setSize( sf::Vector2f(card.shape.getSize().x, (texture_loader.cardSize.y * card.shape.getSize().x) / texture_loader.cardSize.x) );
  }
}

// create textures from the texture file.
// void Game::initializeTextures()
// {
//   textures.resize(14);

//   for ( unsigned int card = 0; card < 13; card++ )
//   {
//     sf::Texture texture = sf::Texture();

//     //std::cerr << "card " << card << " @ " << card * cardSpacing.x + card * cardSize.x + texturesStart.x << "," << suit * cardSpacing.y + suit * cardSize.y + texturesStart.y << std::endl;
//     //std::cerr << "  size " << cardSize.x << "," << cardSize.y << std::endl;
//     sf::IntRect rect(
// /*x*/ card * cardSpacing.x + card * cardSize.x + texturesStart.x,
// /*y*/ suit * cardSpacing.y + suit * cardSize.y + texturesStart.y,
//       cardSize.x,
//       cardSize.y );

//     texture.loadFromImage( textureFile, rect );
//     textures[card] = texture;
//   }

//   textures[13].loadFromImage( textureFile, sf::IntRect(  texturesStart.x, 4 * cardSize.y + 4 * cardSpacing.y + texturesStart.y, cardSize.x, cardSize.y) ); // card back
// }

// create 8 stacks of ace-king in cards and set their face & back texture.
void Game::initializeCards()
{
  //cards.resize( 13 * 8 );

  for ( unsigned int d = 0; d < 8; d++ )
  {
    for ( unsigned int c = 0; c < 13; c++ )
    {
      Card te(texture_loader.cardSize.x, texture_loader.cardSize.y);
      te.value = c;
      te.face = &texture_loader.textures[c];
      // te.face = &textures[c];
      te.back = &texture_loader.textures[13];
      // te.back = &textures[13];
      cards.push_back(te);
    }
  }

  scaleCards();
}

// if the board has no cards, return true.
bool Game::finishedGame()
{

  for ( unsigned int x = 0; x < board.size(); x++ )
    if ( board[x].size() != 0 )
      return false;

  endTime = std::chrono::high_resolution_clock::now();
  std::cout << "game finished in " << std::chrono::duration_cast< std::chrono::seconds > ( endTime - startTime ).count() << "s" << std::endl;

  return true;
}

// returns a pointer to a random card in unusedCards.
Game::Card* Game::randomCard()
{

  int n = rand() % unusedCards.size();
  Card* returnCard = unusedCards[n];

  unusedCards.erase( unusedCards.begin() + n );

  return returnCard;
}

// returns the position in pixels of the board position x,y.
sf::Vector2f Game::absoluteCardPosition(unsigned int x, unsigned int y) // returns the position of a card at board position (x,y)
{
  sf::Vector2f r;

  // cards every 1/10th the screen width.
  r.x = (x * window.getSize().x / 10);

  // cards are offset right by 1/2 the spacing between cards to avoid cards touching the left edge of the screen.
  r.x += ((window.getSize().x / 10) - (window.getSize().x / 12)) / 2;

  // cards are stacked 1/20th of the screen height down from the one under it.
  r.y = y * ( window.getSize().y / 20 ) + topBar.getSize().y;

  return r;
}

// returns the position of the card at (x,y) relative to the previous card in that stack.
// used in resizeStack() to compress stacks of cards.
sf::Vector2f Game::relativeCardPosition(unsigned int x, unsigned int y)
{
  sf::Vector2f r;

  r.x = absoluteCardPosition(x,y).x;

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
bool Game::movableStack( unsigned int x, unsigned int y )
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
bool Game::validMove( unsigned int x, unsigned int y, unsigned int newX )
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
void Game::completeStack( unsigned int x )
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
unsigned int Game::getMovableStackSize( unsigned int x )
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
void Game::resizeStack( unsigned int x )
{

  unsigned int movableStackSize = getMovableStackSize( x );

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
void Game::resetStack( sf::Vector2i card )
{

  for ( unsigned int y = card.y; y < board[card.x].size(); y++ )
    board[ card.x ][ y ]->shape.setPosition( absoluteCardPosition( card.x, y ) );

  resizeStack( card.x );
}

// moves the card(s) on top of, and including, card x,y onto the top of stack newX.
void Game::moveCards( unsigned int x, unsigned int y, unsigned int newX )
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
void Game::autoMoveCards( unsigned int x, unsigned int y )
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