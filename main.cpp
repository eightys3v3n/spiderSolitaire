#ifdef TESTS
#include "tests.hpp"
#endif // TESTS

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
using namespace std;
using namespace sf;
using namespace std::chrono;

RenderWindow window;
RectangleShape newGameButton, topBar;
Image textureFile;
vector< RectangleShape > layers(5);
vector< RectangleShape > completedStacks(8);
vector< Card > cards;
vector< Card* > unusedCards;
vector< Texture > textures;
vector< vector< Card* > > board;
vector< FloatRect > columbs;
Vector2i clickedCard, moveTo;
Vector2f clickOffset;
high_resolution_clock::time_point timeClicked;
int suit = 1; // 0-clubs, 1-spades
bool playing = false;
bool running = true;
bool holding = false;
unsigned int layersToDraw = 5;
unsigned int completedStacksToDraw = 0;
Vector2i texturesStart( 1, 1 );
Vector2i cardSize( 72, 96 );
Vector2i cardSpacing( 1, 1 );

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

  textureFile.loadFromFile( "textures.png" );

  #ifdef TESTS
  texturesTest();
  #endif // TESTS

  initialize();

  while( running )
  {
    draw();
    input();
  }
}


// cards resource from http://www.milefoot.com/math/discrete/counting/images/cards.png