#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

extern sf::Image textures;
extern std::map< std::string, Card > cards;

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
  cards["2club"].face.loadFromImage( textures, sf::IntRect(74,1,72,96) );
  cards["3club"].face.loadFromImage( textures, sf::IntRect(147,1,72,96) );
  cards["4club"].face.loadFromImage( textures, sf::IntRect(220,1,72,96) );
  cards["5club"].face.loadFromImage( textures, sf::IntRect(293,1,72,96) );
  cards["6club"].face.loadFromImage( textures, sf::IntRect(366,1,72,96) );
  cards["7club"].face.loadFromImage( textures, sf::IntRect(439,1,72,96) );
  cards["8club"].face.loadFromImage( textures, sf::IntRect(512,1,72,96) );
  cards["9club"].face.loadFromImage( textures, sf::IntRect(585,1,72,96) );
  cards["10club"].face.loadFromImage( textures, sf::IntRect(658,1,72,96) );
  cards["jackclub"].face.loadFromImage( textures, sf::IntRect(731,1,72,96) );
  cards["queenclub"].face.loadFromImage( textures, sf::IntRect(804,1,72,96) );
  cards["kingclub"].face.loadFromImage( textures, sf::IntRect(877,1,72,96) );
  cards["1spade"].face.loadFromImage( textures, sf::IntRect(1,99,72,96) );
  cards["2spade"].face.loadFromImage( textures, sf::IntRect(74,99,72,96) );
  cards["3spade"].face.loadFromImage( textures, sf::IntRect(147,99,72,96) );
  cards["4spade"].face.loadFromImage( textures, sf::IntRect(220,99,72,96) );
  cards["5spade"].face.loadFromImage( textures, sf::IntRect(293,99,72,96) );
  cards["6spade"].face.loadFromImage( textures, sf::IntRect(366,99,72,96) );
  cards["7spade"].face.loadFromImage( textures, sf::IntRect(439,99,72,96) );
  cards["8spade"].face.loadFromImage( textures, sf::IntRect(512,99,72,96) );
  cards["9spade"].face.loadFromImage( textures, sf::IntRect(585,99,72,96) );
  cards["10spade"].face.loadFromImage( textures, sf::IntRect(658,99,72,96) );
  cards["jackspade"].face.loadFromImage( textures, sf::IntRect(731,99,72,96) );
  cards["queenspade"].face.loadFromImage( textures, sf::IntRect(804,99,72,96) );
  cards["kingspade"].face.loadFromImage( textures, sf::IntRect(877,99,72,96) );
  cards["1heart"].face.loadFromImage( textures, sf::IntRect(1,197,72,96) );
  cards["2heart"].face.loadFromImage( textures, sf::IntRect(74,197,72,96) );
  cards["3heart"].face.loadFromImage( textures, sf::IntRect(147,197,72,96) );
  cards["4heart"].face.loadFromImage( textures, sf::IntRect(220,197,72,96) );
  cards["5heart"].face.loadFromImage( textures, sf::IntRect(293,197,72,96) );
  cards["6heart"].face.loadFromImage( textures, sf::IntRect(366,197,72,96) );
  cards["7heart"].face.loadFromImage( textures, sf::IntRect(439,197,72,96) );
  cards["8heart"].face.loadFromImage( textures, sf::IntRect(512,197,72,96) );
  cards["9heart"].face.loadFromImage( textures, sf::IntRect(585,197,72,96) );
  cards["10heart"].face.loadFromImage( textures, sf::IntRect(658,197,72,96) );
  cards["jackheart"].face.loadFromImage( textures, sf::IntRect(731,197,72,96) );
  cards["queenheart"].face.loadFromImage( textures, sf::IntRect(804,197,72,96) );
  cards["kingheart"].face.loadFromImage( textures, sf::IntRect(877,197,72,96) );
  cards["1diamond"].face.loadFromImage( textures, sf::IntRect(1,295,72,96) );
  cards["2diamond"].face.loadFromImage( textures, sf::IntRect(74,295,72,96) );
  cards["3diamond"].face.loadFromImage( textures, sf::IntRect(147,295,72,96) );
  cards["4diamond"].face.loadFromImage( textures, sf::IntRect(220,295,72,96) );
  cards["5diamond"].face.loadFromImage( textures, sf::IntRect(293,295,72,96) );
  cards["6diamond"].face.loadFromImage( textures, sf::IntRect(366,295,72,96) );
  cards["7diamond"].face.loadFromImage( textures, sf::IntRect(439,295,72,96) );
  cards["8diamond"].face.loadFromImage( textures, sf::IntRect(512,295,72,96) );
  cards["9diamond"].face.loadFromImage( textures, sf::IntRect(585,295,72,96) );
  cards["10diamond"].face.loadFromImage( textures, sf::IntRect(658,295,72,96) );
  cards["jackdiamond"].face.loadFromImage( textures, sf::IntRect(731,295,72,96) );
  cards["queendiamond"].face.loadFromImage( textures, sf::IntRect(804,295,72,96) );
  cards["kingdiamond"].face.loadFromImage( textures, sf::IntRect(877,295,72,96) );
}

Card* randomCard()
{

}