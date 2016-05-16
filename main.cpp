#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "draw.hpp"
#include "input.hpp"
#include "cardStructure.hpp"
#include "cards.hpp"
#include "game.hpp"
using namespace std;
using namespace sf;

RenderWindow window;
RectangleShape newGameButton, topBar;
Image textureFile;
vector< RectangleShape > layers(5);
vector< Card > cards;
vector< Card* > unusedCards;
vector< Texture > textures;
vector< vector< Card* > > board;
string suit = "spades";
bool playing = false;
bool running = true;

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

  window.create( VideoMode(800,500), "spider solitaire", Style::Close );
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