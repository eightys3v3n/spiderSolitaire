#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

extern sf::Image textures;
extern std::map< std::string, sf::Texture > unusedCards;

void initializeCards()
{
  unusedCards["1club"].loadFromImage( textures, sf::IntRect(1,1,72,96) );
  unusedCards["2club"].loadFromImage( textures, sf::IntRect(74,1,72,96) );
  unusedCards["3club"].loadFromImage( textures, sf::IntRect(147,1,72,96) );
  unusedCards["4club"].loadFromImage( textures, sf::IntRect(220,1,72,96) );
  unusedCards["5club"].loadFromImage( textures, sf::IntRect(293,1,72,96) );
  unusedCards["6club"].loadFromImage( textures, sf::IntRect(366,1,72,96) );
  unusedCards["7club"].loadFromImage( textures, sf::IntRect(439,1,72,96) );
  unusedCards["8club"].loadFromImage( textures, sf::IntRect(512,1,72,96) );
  unusedCards["9club"].loadFromImage( textures, sf::IntRect(585,1,72,96) );
  unusedCards["10club"].loadFromImage( textures, sf::IntRect(658,1,72,96) );
  unusedCards["jackclub"].loadFromImage( textures, sf::IntRect(731,1,72,96) );
  unusedCards["queenclub"].loadFromImage( textures, sf::IntRect(804,1,72,96) );
  unusedCards["kingclub"].loadFromImage( textures, sf::IntRect(877,1,72,96) );
  unusedCards["1spade"].loadFromImage( textures, sf::IntRect(1,99,72,96) );
  unusedCards["2spade"].loadFromImage( textures, sf::IntRect(74,99,72,96) );
  unusedCards["3spade"].loadFromImage( textures, sf::IntRect(147,99,72,96) );
  unusedCards["4spade"].loadFromImage( textures, sf::IntRect(220,99,72,96) );
  unusedCards["5spade"].loadFromImage( textures, sf::IntRect(293,99,72,96) );
  unusedCards["6spade"].loadFromImage( textures, sf::IntRect(366,99,72,96) );
  unusedCards["7spade"].loadFromImage( textures, sf::IntRect(439,99,72,96) );
  unusedCards["8spade"].loadFromImage( textures, sf::IntRect(512,99,72,96) );
  unusedCards["9spade"].loadFromImage( textures, sf::IntRect(585,99,72,96) );
  unusedCards["10spade"].loadFromImage( textures, sf::IntRect(658,99,72,96) );
  unusedCards["jackspade"].loadFromImage( textures, sf::IntRect(731,99,72,96) );
  unusedCards["queenspade"].loadFromImage( textures, sf::IntRect(804,99,72,96) );
  unusedCards["kingspade"].loadFromImage( textures, sf::IntRect(877,99,72,96) );
  unusedCards["1heart"].loadFromImage( textures, sf::IntRect(1,197,72,96) );
  unusedCards["2heart"].loadFromImage( textures, sf::IntRect(74,197,72,96) );
  unusedCards["3heart"].loadFromImage( textures, sf::IntRect(147,197,72,96) );
  unusedCards["4heart"].loadFromImage( textures, sf::IntRect(220,197,72,96) );
  unusedCards["5heart"].loadFromImage( textures, sf::IntRect(293,197,72,96) );
  unusedCards["6heart"].loadFromImage( textures, sf::IntRect(366,197,72,96) );
  unusedCards["7heart"].loadFromImage( textures, sf::IntRect(439,197,72,96) );
  unusedCards["8heart"].loadFromImage( textures, sf::IntRect(512,197,72,96) );
  unusedCards["9heart"].loadFromImage( textures, sf::IntRect(585,197,72,96) );
  unusedCards["10heart"].loadFromImage( textures, sf::IntRect(658,197,72,96) );
  unusedCards["jackheart"].loadFromImage( textures, sf::IntRect(731,197,72,96) );
  unusedCards["queenheart"].loadFromImage( textures, sf::IntRect(804,197,72,96) );
  unusedCards["kingheart"].loadFromImage( textures, sf::IntRect(877,197,72,96) );
  unusedCards["1diamond"].loadFromImage( textures, sf::IntRect(1,295,72,96) );
  unusedCards["2diamond"].loadFromImage( textures, sf::IntRect(74,295,72,96) );
  unusedCards["3diamond"].loadFromImage( textures, sf::IntRect(147,295,72,96) );
  unusedCards["4diamond"].loadFromImage( textures, sf::IntRect(220,295,72,96) );
  unusedCards["5diamond"].loadFromImage( textures, sf::IntRect(293,295,72,96) );
  unusedCards["6diamond"].loadFromImage( textures, sf::IntRect(366,295,72,96) );
  unusedCards["7diamond"].loadFromImage( textures, sf::IntRect(439,295,72,96) );
  unusedCards["8diamond"].loadFromImage( textures, sf::IntRect(512,295,72,96) );
  unusedCards["9diamond"].loadFromImage( textures, sf::IntRect(585,295,72,96) );
  unusedCards["10diamond"].loadFromImage( textures, sf::IntRect(658,295,72,96) );
  unusedCards["jackdiamond"].loadFromImage( textures, sf::IntRect(731,295,72,96) );
  unusedCards["queendiamond"].loadFromImage( textures, sf::IntRect(804,295,72,96) );
  unusedCards["kingdiamond"].loadFromImage( textures, sf::IntRect(877,295,72,96) );
}