#include <string>
#include <SFML/System.hpp>

void initializeTextures();
void initializeCards();
void finishedGame();
Card* randomCard();
sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y);
sf::Vector2f relativeCardPosition(unsigned int x, unsigned int y);
void resetCard( sf::Vector2i card );
bool movableStack( unsigned int x, unsigned int y );
bool validMove( unsigned int x, unsigned int y, unsigned int newX );
void completeStack( unsigned int x );
unsigned int getMovableStackSize( unsigned int x );
void resizeStack( unsigned int x );
void moveCards( unsigned int x, unsigned int y, unsigned int newX );
void autoMoveCards( unsigned int x, unsigned int y );