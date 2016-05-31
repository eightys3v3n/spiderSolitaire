#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "draw.hpp"
#include "input.hpp"
#include "cardStructure.hpp"
#include "cards.hpp"
#include "game.hpp"
#include "options.hpp"
using namespace std;
using namespace sf;
using namespace std::chrono;

RenderWindow window;


// textures
{
  // texture for newGame button.
  Texture newGameTexture;

  // storage for all textures read from textureFile.
  vector< Texture > textures;
}

// shapes
{
  // the shape for the new game button.
  RectangleShape newGameButton;

  // a shape drawn as a background for the top of the screen, could be a sprite instead b/c it is never used for clicking.
  RectangleShape topBar;

  // rectangle shapes for the cards at the top right, only 8 posible completed stacks so only 8 rectangles.
  vector< RectangleShape > completedStacks(8);
}

// positions in the textures file
{
  // the start of the textures file (the current file has a 1 pixel boarder).
  // this could be set to zero and eliminated if i felt like removing the white space around the textures file.
  Vector2i texturesStart( 1, 1 );

  // the size of each card in pixels in the TEXTURE_FILE
  Vector2i cardSize( 72, 96 );

   // the space between each card (boarder). have a look at textures.png.
  Vector2i cardSpacing( 1, 1 );
}


// positions on the board
{
  // contains the coords for the card that was clicked on or is being held; the coords refer to board[x][y].
  Vector2i clickedCard;

  // contains the position on the board that the mouse button was released over.
  Vector2i moveTo;
}

// cards
{
  // all cards (8 x ( 1-K ) ) in one suit.
  vector< Card > cards;

  // pointers to the cards that have yet to be played; essentially unusedCards[rand() % unusedCards.size()] is a shuffled card.
  vector< Card* > unusedCards;

  // this is how cards are arranged; 0,0 is the top left most spot, 9,0 is the first card in the right most spot.
  // the y size changes depending on how many cards are in that position, n being the last card.
  vector< vector< Card* > > board;
}

// rectangle shapes for the card backs at the top left.
vector< RectangleShape > layers(5);

// all textures are read from this image, which is read from TEXTURE_FILE.
Image textureFile;

// used to figure out which columb to place a card if there is no card in the columb currently.
vector< FloatRect > columbs;

// the position of the mouse relative to the top left of the card that it's holding.
// so the card is at 0,0, if you click on the middle of the card, the offset is (half the width, half the height).
// then the card will be drawn at mousePosition - offset.
Vector2f clickOffset;

// used to figure out if a card was clicked or is being dragged.
high_resolution_clock::time_point timeClicked;

// suit to play with; 0-clubs, 1-spades
int suit = 1;

// not sure what this is for?
bool playing = false;

// whether the game should be running.
bool running = true;

// user is dragging cards around the screen.
bool holdingCards = false;

// how many new layers does the player have left.
unsigned int layersToDraw = 5;

// how many stacks has the user completed.
unsigned int completedStacksToDraw = 0;

// loads textures.
// sets shape's textures.
// starts a new game.
// sets intrects used to keep track of empty columb positions.
void initialize()
{
  initializeTextures();
  initializeCards();
  initializeGraphics();
  newGame();

  columbs.resize( 10 );

  for ( unsigned int i = 0; i < 10; i++ )
    columbs[i] = board[i][0]->shape.getGlobalBounds();
}

int main()
{
  srand( time(NULL) );

  window.create( VideoMode(800,500), "spider solitaire", Style::Resize );
  window.setFramerateLimit( 61 );

  textureFile.loadFromFile( TEXTURE_FILE );

  initialize();

  while( running )
  {
    draw();
    input();
  }

  return false;
}

// cards resource from http://www.milefoot.com/math/discrete/counting/images/cards.png