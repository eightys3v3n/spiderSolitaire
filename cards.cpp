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
      cards[ 0 + 13 * d].value = "1club";
      cards[ 0 + 13 * d].face = &textures[0];
      cards[ 0 + 13 * d].back = &textures[52];
      cards[ 1 + 13 * d].value = "2club";
      cards[ 1 + 13 * d].face = &textures[1];
      cards[ 1 + 13 * d].back = &textures[52];
      cards[ 2 + 13 * d].value = "3club";
      cards[ 2 + 13 * d].face = &textures[2];
      cards[ 2 + 13 * d].back = &textures[52];
      cards[ 3 + 13 * d].value = "4club";
      cards[ 3 + 13 * d].face = &textures[3];
      cards[ 3 + 13 * d].back = &textures[52];
      cards[ 4 + 13 * d].value = "5club";
      cards[ 4 + 13 * d].face = &textures[4];
      cards[ 4 + 13 * d].back = &textures[52];
      cards[ 5 + 13 * d].value = "6club";
      cards[ 5 + 13 * d].face = &textures[5];
      cards[ 5 + 13 * d].back = &textures[52];
      cards[ 6 + 13 * d].value = "7club";
      cards[ 6 + 13 * d].face = &textures[6];
      cards[ 6 + 13 * d].back = &textures[52];
      cards[ 7 + 13 * d].value = "8club";
      cards[ 7 + 13 * d].face = &textures[7];
      cards[ 7 + 13 * d].back = &textures[52];
      cards[ 8 + 13 * d].value = "9club";
      cards[ 8 + 13 * d].face = &textures[8];
      cards[ 8 + 13 * d].back = &textures[52];
      cards[ 9 + 13 * d].value = "10club";
      cards[ 9 + 13 * d].face = &textures[9];
      cards[ 9 + 13 * d].back = &textures[52];
      cards[10 + 13 * d].value = "jackclub";
      cards[10 + 13 * d].face = &textures[10];
      cards[10 + 13 * d].back = &textures[52];
      cards[11 + 13 * d].value = "queenclub";
      cards[11 + 13 * d].face = &textures[11];
      cards[11 + 13 * d].back = &textures[52];
      cards[12 + 13 * d].value = "kingclub";
      cards[12 + 13 * d].face = &textures[12];
      cards[12 + 13 * d].back = &textures[52];
    }
    else if ( suit == "spades" )
    {
      cards[ 0 + 13 * d].value = "1spade";
      cards[ 0 + 13 * d].face = &textures[13];
      cards[ 0 + 13 * d].back = &textures[52];
      cards[ 1 + 13 * d].value = "2spade";
      cards[ 1 + 13 * d].face = &textures[14];
      cards[ 1 + 13 * d].back = &textures[52];
      cards[ 2 + 13 * d].value = "3spade";
      cards[ 2 + 13 * d].face = &textures[15];
      cards[ 2 + 13 * d].back = &textures[52];
      cards[ 3 + 13 * d].value = "4spade";
      cards[ 3 + 13 * d].face = &textures[16];
      cards[ 3 + 13 * d].back = &textures[52];
      cards[ 4 + 13 * d].value = "5spade";
      cards[ 4 + 13 * d].face = &textures[17];
      cards[ 4 + 13 * d].back = &textures[52];
      cards[ 5 + 13 * d].value = "6spade";
      cards[ 5 + 13 * d].face = &textures[18];
      cards[ 5 + 13 * d].back = &textures[52];
      cards[ 6 + 13 * d].value = "7spade";
      cards[ 6 + 13 * d].face = &textures[19];
      cards[ 6 + 13 * d].back = &textures[52];
      cards[ 7 + 13 * d].value = "8spade";
      cards[ 7 + 13 * d].face = &textures[20];
      cards[ 7 + 13 * d].back = &textures[52];
      cards[ 8 + 13 * d].value = "9spade";
      cards[ 8 + 13 * d].face = &textures[21];
      cards[ 8 + 13 * d].back = &textures[52];
      cards[ 9 + 13 * d].value = "10spade";
      cards[ 9 + 13 * d].face = &textures[22];
      cards[ 9 + 13 * d].back = &textures[52];
      cards[10 + 13 * d].value = "jackspade";
      cards[10 + 13 * d].face = &textures[23];
      cards[10 + 13 * d].back = &textures[52];
      cards[11 + 13 * d].value = "queenspade";
      cards[11 + 13 * d].face = &textures[24];
      cards[11 + 13 * d].back = &textures[52];
      cards[12 + 13 * d].value = "kingspade";
      cards[12 + 13 * d].face = &textures[25];
      cards[12 + 13 * d].back = &textures[52];
    }
/*    cards[26 + 13 * d].value = "1heart";
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

Card* randomCard()
{
  int n = rand() % unusedCards.size();
  Card* returnCard = unusedCards[n];

  unusedCards.erase( unusedCards.begin() + n );

  return returnCard;
}

void setCardPositions()
{
  std::cout << "positions" << std::endl;

  for ( unsigned int x = 0; x < board.size(); x++ )
  {
    for ( unsigned int y = 0; y < board[x].size(); y++ )
    {
      board[x][y]->shape.setPosition( sf::Vector2f( x * window.getSize().x * 1/10, y * window.getSize().y * 1/20 ) );
      std::cout << x << "," << y << ":" << x * window.getSize().x * 1/10 << "," << y * window.getSize().y * 1/20 << std::endl;
    }
  }

  std::cout << "end" << std::endl;
}