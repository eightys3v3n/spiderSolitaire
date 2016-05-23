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
Vector2i clickedCard;
Vector2i moveTo;
high_resolution_clock::time_point timeClicked;
string suit = "spades";
bool playing = false;
bool running = true;
unsigned int layersToDraw = 5;
unsigned int completedStacksToDraw = 0;

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

  newGameButton.setFillColor( Color::Blue );
  topBar.setFillColor( Color(0,0,0) );

  initialize();

  while( running )
  {
    draw();
    input();
  }
}


// cards resource from http://www.milefoot.com/math/discrete/counting/images/cards.png