#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::Image textures;
extern std::map< std::string, Card > cards;
extern std::vector< std::string > unusedCards, playingCards, discardCards;
extern std::vector< std::vector< std::string > > board;
extern sf::RenderWindow window;
extern sf::RectangleShape topBar;

void initializeCards()
{
  Card newCard;

  cards["1club"] = newCard;
  cards["2club"] = newCard;
  cards["3club"] = newCard;
  cards["4club"] = newCard;
  cards["5club"] = newCard;
  cards["6club"] = newCard;
  cards["7club"] = newCard;
  cards["8club"] = newCard;
  cards["9club"] = newCard;
  cards["10club"] = newCard;
  cards["jackclub"] = newCard;
  cards["queenclub"] = newCard;
  cards["kingclub"] = newCard;
  cards["1spade"] = newCard;
  cards["2spade"] = newCard;
  cards["3spade"] = newCard;
  cards["4spade"] = newCard;
  cards["5spade"] = newCard;
  cards["6spade"] = newCard;
  cards["7spade"] = newCard;
  cards["8spade"] = newCard;
  cards["9spade"] = newCard;
  cards["10spade"] = newCard;
  cards["jackspade"] = newCard;
  cards["queenspade"] = newCard;
  cards["kingspade"] = newCard;
  cards["1heart"] = newCard;
  cards["2heart"] = newCard;
  cards["3heart"] = newCard;
  cards["4heart"] = newCard;
  cards["5heart"] = newCard;
  cards["6heart"] = newCard;
  cards["7heart"] = newCard;
  cards["8heart"] = newCard;
  cards["9heart"] = newCard;
  cards["10heart"] = newCard;
  cards["jackheart"] = newCard;
  cards["queenheart"] = newCard;
  cards["kingheart"] = newCard;
  cards["1diamond"] = newCard;
  cards["2diamond"] = newCard;
  cards["3diamond"] = newCard;
  cards["4diamond"] = newCard;
  cards["5diamond"] = newCard;
  cards["6diamond"] = newCard;
  cards["7diamond"] = newCard;
  cards["8diamond"] = newCard;
  cards["9diamond"] = newCard;
  cards["10diamond"] = newCard;
  cards["jackdiamond"] = newCard;
  cards["queendiamond"] = newCard;
  cards["kingdiamond"] = newCard;

  cards["1club"].face.loadFromImage( textures, sf::IntRect(1,1,72,96) );
  cards["1club"].shape.setTexture( &cards["1club"].face );
  cards["1club"].id = "1club";
  cards["2club"].face.loadFromImage( textures, sf::IntRect(74,1,72,96) );
  cards["2club"].shape.setTexture( &cards["2club"].face );
  cards["2club"].id = "2club";
  cards["3club"].face.loadFromImage( textures, sf::IntRect(147,1,72,96) );
  cards["3club"].shape.setTexture( &cards["3club"].face );
  cards["3club"].id = "3club";
  cards["4club"].face.loadFromImage( textures, sf::IntRect(220,1,72,96) );
  cards["4club"].shape.setTexture( &cards["4club"].face );
  cards["4club"].id = "4club";
  cards["5club"].face.loadFromImage( textures, sf::IntRect(293,1,72,96) );
  cards["5club"].shape.setTexture( &cards["5club"].face );
  cards["5club"].id = "5club";
  cards["6club"].face.loadFromImage( textures, sf::IntRect(366,1,72,96) );
  cards["6club"].shape.setTexture( &cards["6club"].face );
  cards["6club"].id = "6club";
  cards["7club"].face.loadFromImage( textures, sf::IntRect(439,1,72,96) );
  cards["7club"].shape.setTexture( &cards["7club"].face );
  cards["7club"].id = "7club";
  cards["8club"].face.loadFromImage( textures, sf::IntRect(512,1,72,96) );
  cards["8club"].shape.setTexture( &cards["8club"].face );
  cards["8club"].id = "8club";
  cards["9club"].face.loadFromImage( textures, sf::IntRect(585,1,72,96) );
  cards["9club"].shape.setTexture( &cards["9club"].face );
  cards["9club"].id = "9club";
  cards["10club"].face.loadFromImage( textures, sf::IntRect(658,1,72,96) );
  cards["10club"].shape.setTexture( &cards["10club"].face );
  cards["10club"].id = "10club";
  cards["jackclub"].face.loadFromImage( textures, sf::IntRect(731,1,72,96) );
  cards["jackclub"].shape.setTexture( &cards["jackclub"].face );
  cards["jackclub"].id = "jackclub";
  cards["queenclub"].face.loadFromImage( textures, sf::IntRect(804,1,72,96) );
  cards["queenclub"].shape.setTexture( &cards["queenclub"].face );
  cards["queenclub"].id = "queenclub";
  cards["kingclub"].face.loadFromImage( textures, sf::IntRect(877,1,72,96) );
  cards["kingclub"].shape.setTexture( &cards["kingclub"].face );
  cards["kingclub"].id = "kingclub";
  cards["1spade"].face.loadFromImage( textures, sf::IntRect(1,99,72,96) );
  cards["1spade"].shape.setTexture( &cards["1spade"].face );
  cards["1spade"].id = "1spade";
  cards["2spade"].face.loadFromImage( textures, sf::IntRect(74,99,72,96) );
  cards["2spade"].shape.setTexture( &cards["2spade"].face );
  cards["2spade"].id = "2spade";
  cards["3spade"].face.loadFromImage( textures, sf::IntRect(147,99,72,96) );
  cards["3spade"].shape.setTexture( &cards["3spade"].face );
  cards["3spade"].id = "3spade";
  cards["4spade"].face.loadFromImage( textures, sf::IntRect(220,99,72,96) );
  cards["4spade"].shape.setTexture( &cards["4spade"].face );
  cards["4spade"].id = "4spade";
  cards["5spade"].face.loadFromImage( textures, sf::IntRect(293,99,72,96) );
  cards["5spade"].shape.setTexture( &cards["5spade"].face );
  cards["5spade"].id = "5spade";
  cards["6spade"].face.loadFromImage( textures, sf::IntRect(366,99,72,96) );
  cards["6spade"].shape.setTexture( &cards["6spade"].face );
  cards["6spade"].id = "6spade";
  cards["7spade"].face.loadFromImage( textures, sf::IntRect(439,99,72,96) );
  cards["7spade"].shape.setTexture( &cards["7spade"].face );
  cards["7spade"].id = "7spade";
  cards["8spade"].face.loadFromImage( textures, sf::IntRect(512,99,72,96) );
  cards["8spade"].shape.setTexture( &cards["8spade"].face );
  cards["8spade"].id = "8spade";
  cards["9spade"].face.loadFromImage( textures, sf::IntRect(585,99,72,96) );
  cards["9spade"].shape.setTexture( &cards["9spade"].face );
  cards["9spade"].id = "9spade";
  cards["10spade"].face.loadFromImage( textures, sf::IntRect(658,99,72,96) );
  cards["10spade"].shape.setTexture( &cards["10spade"].face );
  cards["10spade"].id = "10spade";
  cards["jackspade"].face.loadFromImage( textures, sf::IntRect(731,99,72,96) );
  cards["jackspade"].shape.setTexture( &cards["jackspade"].face );
  cards["jackspade"].id = "jackspade";
  cards["queenspade"].face.loadFromImage( textures, sf::IntRect(804,99,72,96) );
  cards["queenspade"].shape.setTexture( &cards["queenspade"].face );
  cards["queenspade"].id = "queenspade";
  cards["kingspade"].face.loadFromImage( textures, sf::IntRect(877,99,72,96) );
  cards["kingspade"].shape.setTexture( &cards["kingspade"].face );
  cards["kingspade"].id = "kingspade";
  cards["1heart"].face.loadFromImage( textures, sf::IntRect(1,197,72,96) );
  cards["1heart"].shape.setTexture( &cards["1heart"].face );
  cards["1heart"].id = "1heart";
  cards["2heart"].face.loadFromImage( textures, sf::IntRect(74,197,72,96) );
  cards["2heart"].shape.setTexture( &cards["2heart"].face );
  cards["2heart"].id = "2heart";
  cards["3heart"].face.loadFromImage( textures, sf::IntRect(147,197,72,96) );
  cards["3heart"].shape.setTexture( &cards["3heart"].face );
  cards["3heart"].id = "3heart";
  cards["4heart"].face.loadFromImage( textures, sf::IntRect(220,197,72,96) );
  cards["4heart"].shape.setTexture( &cards["4heart"].face );
  cards["4heart"].id = "4heart";
  cards["5heart"].face.loadFromImage( textures, sf::IntRect(293,197,72,96) );
  cards["5heart"].shape.setTexture( &cards["5heart"].face );
  cards["5heart"].id = "5heart";
  cards["6heart"].face.loadFromImage( textures, sf::IntRect(366,197,72,96) );
  cards["6heart"].shape.setTexture( &cards["6heart"].face );
  cards["6heart"].id = "6heart";
  cards["7heart"].face.loadFromImage( textures, sf::IntRect(439,197,72,96) );
  cards["7heart"].shape.setTexture( &cards["7heart"].face );
  cards["7heart"].id = "7heart";
  cards["8heart"].face.loadFromImage( textures, sf::IntRect(512,197,72,96) );
  cards["8heart"].shape.setTexture( &cards["8heart"].face );
  cards["8heart"].id = "8heart";
  cards["9heart"].face.loadFromImage( textures, sf::IntRect(585,197,72,96) );
  cards["9heart"].shape.setTexture( &cards["9heart"].face );
  cards["9heart"].id = "9heart";
  cards["10heart"].face.loadFromImage( textures, sf::IntRect(658,197,72,96) );
  cards["10heart"].shape.setTexture( &cards["10heart"].face );
  cards["10heart"].id = "10heart";
  cards["jackheart"].face.loadFromImage( textures, sf::IntRect(731,197,72,96) );
  cards["jackheart"].shape.setTexture( &cards["jackheart"].face );
  cards["jackheart"].id = "jackheart";
  cards["queenheart"].face.loadFromImage( textures, sf::IntRect(804,197,72,96) );
  cards["queenheart"].shape.setTexture( &cards["queenheart"].face );
  cards["queenheart"].id = "queenheart";
  cards["kingheart"].face.loadFromImage( textures, sf::IntRect(877,197,72,96) );
  cards["kingheart"].shape.setTexture( &cards["kingheart"].face );
  cards["kingheart"].id = "kingheart";
  cards["1diamond"].face.loadFromImage( textures, sf::IntRect(1,295,72,96) );
  cards["1diamond"].shape.setTexture( &cards["1diamond"].face );
  cards["1diamond"].id = "1diamond";
  cards["2diamond"].face.loadFromImage( textures, sf::IntRect(74,295,72,96) );
  cards["2diamond"].shape.setTexture( &cards["2diamond"].face );
  cards["2diamond"].id = "2diamond";
  cards["3diamond"].face.loadFromImage( textures, sf::IntRect(147,295,72,96) );
  cards["3diamond"].shape.setTexture( &cards["3diamond"].face );
  cards["3diamond"].id = "3diamond";
  cards["4diamond"].face.loadFromImage( textures, sf::IntRect(220,295,72,96) );
  cards["4diamond"].shape.setTexture( &cards["4diamond"].face );
  cards["4diamond"].id = "4diamond";
  cards["5diamond"].face.loadFromImage( textures, sf::IntRect(293,295,72,96) );
  cards["5diamond"].shape.setTexture( &cards["5diamond"].face );
  cards["5diamond"].id = "5diamond";
  cards["6diamond"].face.loadFromImage( textures, sf::IntRect(366,295,72,96) );
  cards["6diamond"].shape.setTexture( &cards["6diamond"].face );
  cards["6diamond"].id = "6diamond";
  cards["7diamond"].face.loadFromImage( textures, sf::IntRect(439,295,72,96) );
  cards["7diamond"].shape.setTexture( &cards["7diamond"].face );
  cards["7diamond"].id = "7diamond";
  cards["8diamond"].face.loadFromImage( textures, sf::IntRect(512,295,72,96) );
  cards["8diamond"].shape.setTexture( &cards["8diamond"].face );
  cards["8diamond"].id = "8diamond";
  cards["9diamond"].face.loadFromImage( textures, sf::IntRect(585,295,72,96) );
  cards["9diamond"].shape.setTexture( &cards["9diamond"].face );
  cards["9diamond"].id = "9diamond";
  cards["10diamond"].face.loadFromImage( textures, sf::IntRect(658,295,72,96) );
  cards["10diamond"].shape.setTexture( &cards["10diamond"].face );
  cards["10diamond"].id = "10diamond";
  cards["jackdiamond"].face.loadFromImage( textures, sf::IntRect(731,295,72,96) );
  cards["jackdiamond"].shape.setTexture( &cards["jackdiamond"].face );
  cards["jackdiamond"].id = "jackdiamond";
  cards["queendiamond"].face.loadFromImage( textures, sf::IntRect(804,295,72,96) );
  cards["queendiamond"].shape.setTexture( &cards["queendiamond"].face );
  cards["queendiamond"].id = "queendiamond";
  cards["kingdiamond"].face.loadFromImage( textures, sf::IntRect(877,295,72,96) );
  cards["kingdiamond"].shape.setTexture( &cards["kingdiamond"].face );
  cards["kingdiamond"].id = "kingdiamond";
}

std::string randomCard()
{
  int n = rand() % unusedCards.size();
  std::string returnCard = unusedCards[n];

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
      cards[ board[x][y] ].shape.setPosition( sf::Vector2f( x * window.getSize().x * 1/10, y * window.getSize().y * 1/20 ) );
      std::cout << x << "," << y << ":" << x * window.getSize().x * 1/10 << "," << y * window.getSize().y * 1/20 << std::endl;
    }
  }

  std::cout << "end" << std::endl;
}