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
vector< Card > cards;
vector< Card* > unusedCards;
vector< Texture > textures;
vector< vector< Card* > > board;
Vector2i clickedCard;
Vector2i moveTo;
high_resolution_clock::time_point timeClicked;
string suit = "spades";
bool playing = false;
bool running = true;
unsigned int layersToDraw = 5;

void initialize()
{
  initializeTextures();
  initializeCards();
  initializeGraphics();
  newGame();
}

int main()
{
  srand( time(NULL) );

  window.create( VideoMode(800,500), "spider solitaire", Style::Resize );
  window.setFramerateLimit( 31 );

  textureFile.loadFromFile( "textures.png" );

  newGameButton.setFillColor( Color::Blue );
  topBar.setFillColor( Color(0,0,0) );

  initialize();

  for ( unsigned int l = 0; l < layers.size(); l++ )
    layers[l].setTexture( &textures[52] );

  while( running )
  {
    draw();
    input();
  }
}


// cards resource from http://www.milefoot.com/math/discrete/counting/images/cards.png