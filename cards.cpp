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
extern std::string suit;
extern unsigned int completedStacksToDraw;

void initializeTextures()
{
  textures.resize(53);

  textures[ 0].loadFromImage( textureFile, sf::IntRect( 1,   1,72,96) ); // 1 clubs
  textures[ 1].loadFromImage( textureFile, sf::IntRect( 74,  1,72,96) );
  textures[ 2].loadFromImage( textureFile, sf::IntRect(147,  1,72,96) );
  textures[ 3].loadFromImage( textureFile, sf::IntRect(220,  1,72,96) );
  textures[ 4].loadFromImage( textureFile, sf::IntRect(293,  1,72,96) );
  textures[ 5].loadFromImage( textureFile, sf::IntRect(366,  1,72,96) );
  textures[ 6].loadFromImage( textureFile, sf::IntRect(439,  1,72,96) );
  textures[ 7].loadFromImage( textureFile, sf::IntRect(512,  1,72,96) );
  textures[ 8].loadFromImage( textureFile, sf::IntRect(585,  1,72,96) );
  textures[ 9].loadFromImage( textureFile, sf::IntRect(658,  1,72,96) );
  textures[10].loadFromImage( textureFile, sf::IntRect(731,  1,72,96) );
  textures[11].loadFromImage( textureFile, sf::IntRect(804,  1,72,96) );
  textures[12].loadFromImage( textureFile, sf::IntRect(877,  1,72,96) ); // king clubs
  textures[13].loadFromImage( textureFile, sf::IntRect(  1, 99,72,96) ); // 1 spades
  textures[14].loadFromImage( textureFile, sf::IntRect( 74, 99,72,96) );
  textures[15].loadFromImage( textureFile, sf::IntRect(147, 99,72,96) );
  textures[16].loadFromImage( textureFile, sf::IntRect(220, 99,72,96) );
  textures[17].loadFromImage( textureFile, sf::IntRect(293, 99,72,96) );
  textures[18].loadFromImage( textureFile, sf::IntRect(366, 99,72,96) );
  textures[19].loadFromImage( textureFile, sf::IntRect(439, 99,72,96) );
  textures[20].loadFromImage( textureFile, sf::IntRect(512, 99,72,96) );
  textures[21].loadFromImage( textureFile, sf::IntRect(585, 99,72,96) );
  textures[22].loadFromImage( textureFile, sf::IntRect(658, 99,72,96) );
  textures[23].loadFromImage( textureFile, sf::IntRect(731, 99,72,96) );
  textures[24].loadFromImage( textureFile, sf::IntRect(804, 99,72,96) );
  textures[25].loadFromImage( textureFile, sf::IntRect(877, 99,72,96) ); // king spaces
  textures[26].loadFromImage( textureFile, sf::IntRect(  1,197,72,96) ); // 1 hearts
  textures[27].loadFromImage( textureFile, sf::IntRect( 74,197,72,96) );
  textures[28].loadFromImage( textureFile, sf::IntRect(147,197,72,96) );
  textures[29].loadFromImage( textureFile, sf::IntRect(220,197,72,96) );
  textures[30].loadFromImage( textureFile, sf::IntRect(293,197,72,96) );
  textures[31].loadFromImage( textureFile, sf::IntRect(366,197,72,96) );
  textures[32].loadFromImage( textureFile, sf::IntRect(439,197,72,96) );
  textures[33].loadFromImage( textureFile, sf::IntRect(512,197,72,96) );
  textures[34].loadFromImage( textureFile, sf::IntRect(585,197,72,96) );
  textures[35].loadFromImage( textureFile, sf::IntRect(658,197,72,96) );
  textures[36].loadFromImage( textureFile, sf::IntRect(731,197,72,96) );
  textures[37].loadFromImage( textureFile, sf::IntRect(804,197,72,96) );
  textures[38].loadFromImage( textureFile, sf::IntRect(877,197,72,96) ); // king hearts
  textures[39].loadFromImage( textureFile, sf::IntRect(  1,295,72,96) ); // 1 diamonds
  textures[40].loadFromImage( textureFile, sf::IntRect( 74,295,72,96) );
  textures[41].loadFromImage( textureFile, sf::IntRect(147,295,72,96) );
  textures[42].loadFromImage( textureFile, sf::IntRect(220,295,72,96) );
  textures[43].loadFromImage( textureFile, sf::IntRect(293,295,72,96) );
  textures[44].loadFromImage( textureFile, sf::IntRect(366,295,72,96) );
  textures[45].loadFromImage( textureFile, sf::IntRect(439,295,72,96) );
  textures[46].loadFromImage( textureFile, sf::IntRect(512,295,72,96) );
  textures[47].loadFromImage( textureFile, sf::IntRect(585,295,72,96) );
  textures[48].loadFromImage( textureFile, sf::IntRect(658,295,72,96) );
  textures[49].loadFromImage( textureFile, sf::IntRect(731,295,72,96) );
  textures[50].loadFromImage( textureFile, sf::IntRect(804,295,72,96) );
  textures[51].loadFromImage( textureFile, sf::IntRect(877,295,72,96) ); // kind diamonds
  textures[52].loadFromImage( textureFile, sf::IntRect(  1,393,72,96) ); // card back
}

void initializeCards()
{
  cards.resize( 13 * 8 );

  for ( unsigned int d = 0; d < 8; d++ )
  {
    if ( suit == "clubs" )
    {
      cards[ 0 + 13 * d].value = 1;
      cards[ 0 + 13 * d].suit = "clubs";
      cards[ 0 + 13 * d].face = &textures[0];
      cards[ 0 + 13 * d].back = &textures[52];
      cards[ 1 + 13 * d].value = 2;
      cards[ 1 + 13 * d].suit = "clubs";
      cards[ 1 + 13 * d].face = &textures[1];
      cards[ 1 + 13 * d].back = &textures[52];
      cards[ 2 + 13 * d].value = 3;
      cards[ 2 + 13 * d].suit = "clubs";
      cards[ 2 + 13 * d].face = &textures[2];
      cards[ 2 + 13 * d].back = &textures[52];
      cards[ 3 + 13 * d].value = 4;
      cards[ 3 + 13 * d].suit = "clubs";
      cards[ 3 + 13 * d].face = &textures[3];
      cards[ 3 + 13 * d].back = &textures[52];
      cards[ 4 + 13 * d].value = 5;
      cards[ 4 + 13 * d].suit = "clubs";
      cards[ 4 + 13 * d].face = &textures[4];
      cards[ 4 + 13 * d].back = &textures[52];
      cards[ 5 + 13 * d].value = 6;
      cards[ 5 + 13 * d].suit = "clubs";
      cards[ 5 + 13 * d].face = &textures[5];
      cards[ 5 + 13 * d].back = &textures[52];
      cards[ 6 + 13 * d].value = 7;
      cards[ 6 + 13 * d].suit = "clubs";
      cards[ 6 + 13 * d].face = &textures[6];
      cards[ 6 + 13 * d].back = &textures[52];
      cards[ 7 + 13 * d].value = 8;
      cards[ 7 + 13 * d].suit = "clubs";
      cards[ 7 + 13 * d].face = &textures[7];
      cards[ 7 + 13 * d].back = &textures[52];
      cards[ 8 + 13 * d].value = 9;
      cards[ 8 + 13 * d].suit = "clubs";
      cards[ 8 + 13 * d].face = &textures[8];
      cards[ 8 + 13 * d].back = &textures[52];
      cards[ 9 + 13 * d].value = 10;
      cards[ 9 + 13 * d].suit = "clubs";
      cards[ 9 + 13 * d].face = &textures[9];
      cards[ 9 + 13 * d].back = &textures[52];
      cards[10 + 13 * d].value = 11;
      cards[10 + 13 * d].suit = "clubs";
      cards[10 + 13 * d].face = &textures[10];
      cards[10 + 13 * d].back = &textures[52];
      cards[11 + 13 * d].value = 12;
      cards[11 + 13 * d].suit = "clubs";
      cards[11 + 13 * d].face = &textures[11];
      cards[11 + 13 * d].back = &textures[52];
      cards[12 + 13 * d].value = 13;
      cards[12 + 13 * d].suit = "clubs";
      cards[12 + 13 * d].face = &textures[12];
      cards[12 + 13 * d].back = &textures[52];
    }
    else if ( suit == "spades" )
    {
      cards[ 0 + 13 * d].value = 1;
      cards[ 0 + 13 * d].suit = "spades";
      cards[ 0 + 13 * d].face = &textures[13];
      cards[ 0 + 13 * d].back = &textures[52];
      cards[ 1 + 13 * d].value = 2;
      cards[ 1 + 13 * d].suit = "spades";
      cards[ 1 + 13 * d].face = &textures[14];
      cards[ 1 + 13 * d].back = &textures[52];
      cards[ 2 + 13 * d].value = 3;
      cards[ 2 + 13 * d].suit = "spades";
      cards[ 2 + 13 * d].face = &textures[15];
      cards[ 2 + 13 * d].back = &textures[52];
      cards[ 3 + 13 * d].value = 4;
      cards[ 3 + 13 * d].suit = "spades";
      cards[ 3 + 13 * d].face = &textures[16];
      cards[ 3 + 13 * d].back = &textures[52];
      cards[ 4 + 13 * d].value = 5;
      cards[ 4 + 13 * d].suit = "spades";
      cards[ 4 + 13 * d].face = &textures[17];
      cards[ 4 + 13 * d].back = &textures[52];
      cards[ 5 + 13 * d].value = 6;
      cards[ 5 + 13 * d].suit = "spades";
      cards[ 5 + 13 * d].face = &textures[18];
      cards[ 5 + 13 * d].back = &textures[52];
      cards[ 6 + 13 * d].value = 7;
      cards[ 6 + 13 * d].suit = "spades";
      cards[ 6 + 13 * d].face = &textures[19];
      cards[ 6 + 13 * d].back = &textures[52];
      cards[ 7 + 13 * d].value = 8;
      cards[ 7 + 13 * d].suit = "spades";
      cards[ 7 + 13 * d].face = &textures[20];
      cards[ 7 + 13 * d].back = &textures[52];
      cards[ 8 + 13 * d].value = 9;
      cards[ 8 + 13 * d].suit = "spades";
      cards[ 8 + 13 * d].face = &textures[21];
      cards[ 8 + 13 * d].back = &textures[52];
      cards[ 9 + 13 * d].value = 10;
      cards[ 9 + 13 * d].suit = "spades";
      cards[ 9 + 13 * d].face = &textures[22];
      cards[ 9 + 13 * d].back = &textures[52];
      cards[10 + 13 * d].value = 11;
      cards[10 + 13 * d].suit = "spades";
      cards[10 + 13 * d].face = &textures[23];
      cards[10 + 13 * d].back = &textures[52];
      cards[11 + 13 * d].value = 12;
      cards[11 + 13 * d].suit = "spades";
      cards[11 + 13 * d].face = &textures[24];
      cards[11 + 13 * d].back = &textures[52];
      cards[12 + 13 * d].value = 13;
      cards[12 + 13 * d].suit = "spades";
      cards[12 + 13 * d].face = &textures[25];
      cards[12 + 13 * d].back = &textures[52];
    }
    /*cards[26 + 13 * d].value = "1heart";
    cards[26 + 13 * d].face = &textures[26];
    cards[26 + 13 * d].back = &textures[52];
    cards[27 + 13 * d].value = "2heart";
    cards[27 + 13 * d].face = &textures[27];
    cards[27 + 13 * d].back = &textures[52];
    cards[28 + 13 * d].value = "3heart";
    cards[28 + 13 * d].face = &textures[28];
    cards[28 + 13 * d].back = &textures[52];
    cards[29 + 13 * d].value = "4heart";
    cards[29 + 13 * d].face = &textures[29];
    cards[29 + 13 * d].back = &textures[52];
    cards[30 + 13 * d].value = "5heart";
    cards[30 + 13 * d].face = &textures[30];
    cards[30 + 13 * d].back = &textures[52];
    cards[31 + 13 * d].value = "6heart";
    cards[31 + 13 * d].face = &textures[31];
    cards[31 + 13 * d].back = &textures[52];
    cards[32 + 13 * d].value = "7heart";
    cards[32 + 13 * d].face = &textures[32];
    cards[32 + 13 * d].back = &textures[52];
    cards[33 + 13 * d].value = "8heart";
    cards[33 + 13 * d].face = &textures[33];
    cards[33 + 13 * d].back = &textures[52];
    cards[34 + 13 * d].value = "9heart";
    cards[34 + 13 * d].face = &textures[34];
    cards[34 + 13 * d].back = &textures[52];
    cards[35 + 13 * d].value = "10heart";
    cards[35 + 13 * d].face = &textures[35];
    cards[35 + 13 * d].back = &textures[52];
    cards[36 + 13 * d].value = "jackheart";
    cards[36 + 13 * d].face = &textures[36];
    cards[36 + 13 * d].back = &textures[52];
    cards[37 + 13 * d].value = "queenheart";
    cards[37 + 13 * d].face = &textures[37];
    cards[37 + 13 * d].back = &textures[52];
    cards[38 + 13 * d].value = "kingheart";
    cards[38 + 13 * d].face = &textures[38];
    cards[38 + 13 * d].back = &textures[52];
    cards[39 + 13 * d].value = "1diamond";
    cards[39 + 13 * d].face = &textures[39];
    cards[39 + 13 * d].back = &textures[52];
    cards[40 + 13 * d].value = "2diamond";
    cards[40 + 13 * d].face = &textures[40];
    cards[40 + 13 * d].back = &textures[52];
    cards[41 + 13 * d].value = "3diamond";
    cards[41 + 13 * d].face = &textures[41];
    cards[41 + 13 * d].back = &textures[52];
    cards[42 + 13 * d].value = "4diamond";
    cards[42 + 13 * d].face = &textures[42];
    cards[42 + 13 * d].back = &textures[52];
    cards[43 + 13 * d].value = "5diamond";
    cards[43 + 13 * d].face = &textures[43];
    cards[43 + 13 * d].back = &textures[52];
    cards[44 + 13 * d].value = "6diamond";
    cards[44 + 13 * d].face = &textures[44];
    cards[44 + 13 * d].back = &textures[52];
    cards[45 + 13 * d].value = "7diamond";
    cards[45 + 13 * d].face = &textures[45];
    cards[45 + 13 * d].back = &textures[52];
    cards[46 + 13 * d].value = "8diamond";
    cards[46 + 13 * d].face = &textures[46];
    cards[46 + 13 * d].back = &textures[52];
    cards[47 + 13 * d].value = "9diamond";
    cards[47 + 13 * d].face = &textures[47];
    cards[47 + 13 * d].back = &textures[52];
    cards[48 + 13 * d].value = "10diamond";
    cards[48 + 13 * d].face = &textures[48];
    cards[48 + 13 * d].back = &textures[52];
    cards[49 + 13 * d].value = "jackdiamond";
    cards[49 + 13 * d].face = &textures[49];
    cards[49 + 13 * d].back = &textures[52];
    cards[50 + 13 * d].value = "queendiamond";
    cards[50 + 13 * d].face = &textures[50];
    cards[50 + 13 * d].back = &textures[52];
    cards[51 + 13 * d].value = "kingdiamond";
    cards[51 + 13 * d].face = &textures[51];
    cards[51 + 13 * d].back = &textures[52];*/
  }

  for ( unsigned int c = 0; c < cards.size(); c++ )
    cards[c].shape.setTexture( cards[c].face, true );
}

void finishedGame()
{
  for ( unsigned int x = 0; x < board.size(); x++ )
    if ( board[x].size() != 0 )
      return;

  std::cout << "game finished!" << std::endl;
}

Card* randomCard()
{
  int n = rand() % unusedCards.size();
  Card* returnCard = unusedCards[n];

  unusedCards.erase( unusedCards.begin() + n );

  return returnCard;
}

sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y) // returns the position of a card at board position (x,y)
{
  sf::Vector2f r;

  r.x = ( x * window.getSize().x * .1 ) + ( .5 * ( window.getSize().x / 10 - 72 ) );
  r.y = y * ( window.getSize().y / 20 ) + topBar.getSize().y ;

  return r;
}

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

bool validMove( unsigned int x, unsigned int y, unsigned int newX )
{
  if ( x == newX )
    return false;

  // temp for debugging
  //return true;

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

void completeStack( unsigned int x )
{
  if ( board[x].size() < 13 )
    return;

  for ( unsigned int c = 0; c < 13; c++ )
  {
    std::cout << "checking " << board[x].size() - 1 - c << ":" << board[x][ board[x].size() - 1 - c ]->value << " != " << c << std::endl;
    if ( board[x][ board[x].size() - 1 - c ]->value != c + 1 )
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

void resizeStack( unsigned int x )
{
  unsigned int movableStackSize = getMovableStackSize( x );

  // i don't remember what this is for so i'll leave it here for now.
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
    std::cout << bestMove.x << ":" << bestMove.y << " & " << validMoves[i].x << ":" << validMoves[i].y << std::endl;

    if ( bestMove.y < validMoves[i].y )
    {
      std::cout << "new best move" << std::endl;
      bestMove = validMoves[i];
    }
  }

  if ( bestMove.x != -1 )
    moveCards( x, y, bestMove.x );
}