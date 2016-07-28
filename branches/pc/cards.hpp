#ifndef CARDS_
#define CARDS_

#include <string>
#include <SFML/System.hpp>

// create textures from the texture file.
void initializeTextures();

// create 8 stacks of ace-king in cards and set their face & back texture.
void initializeCards();

// if the board has no cards, return true.
void finishedGame();

// returns a pointer to a random card in unusedCards.
Card* randomCard();

// returns the position in pixels of the board position x,y.
sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y);

// returns the position in pixels of card x,y-1, + ( 1/20 of the window height ).
sf::Vector2f relativeCardPosition(unsigned int x, unsigned int y);

// returns true if the card can be moved; all the cards after card x,y are stacked correctly.
bool movableStack( unsigned int x, unsigned int y );

// returns true if the card(s) at and on top of card x,y can be moved to columb newX.
bool validMove( unsigned int x, unsigned int y, unsigned int newX );

// removes completed stacks (ace-king).
void completeStack( unsigned int x );

// returns the number of correctly stacked cards on columb x.
unsigned int getMovableStackSize( unsigned int x );

// (de)compress stacks to fit on the screen.
void resizeStack( unsigned int x );

// set all the cards to the un-compressed position, then re-compress them.
void resetStack( sf::Vector2i card );

// moves the card(s) on top of, and including, card x,y onto the top of stack newX.
void moveCards( unsigned int x, unsigned int y, unsigned int newX );

// moves card(s) at, and on top of, position x,y to the "best" position on the board.
// moves to the left most columb in the case of a tie.
// moves to the columb that will create the largest stack of correctly stacked cards.
void autoMoveCards( unsigned int x, unsigned int y );

#endif // CARDS_