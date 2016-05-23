#include <string>
#include <SFML/System.hpp>

void initializeTextures();
void initializeCards();
Card* randomCard();
sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y);
sf::Vector2f relativeCardPosition(unsigned int x, unsigned int y);
bool validMove( unsigned int x, unsigned int y, unsigned int newX );
bool movableStack( unsigned int x, unsigned int y );
void completeStack( unsigned int x );
unsigned int getMovableStackSize( unsigned int x );
void resizeStack( unsigned int x );
void moveCards( unsigned int x, unsigned int y, unsigned int newX );
void autoMoveCards( unsigned int x, unsigned int y, unsigned int newX );