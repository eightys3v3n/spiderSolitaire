#include <string>
#include <SFML/System.hpp>

void initializeTextures();
void initializeCards();
Card* randomCard();
sf::Vector2f cardPosition(unsigned int x, unsigned int y);
bool validMove( unsigned int x, unsigned int y, unsigned int newX );
bool movableStack( unsigned int x, unsigned int y );
void moveCards( unsigned int x, unsigned int y, unsigned int newX );
void completeStack( unsigned int x );