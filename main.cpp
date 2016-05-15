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
Image textures;
Texture cardBack;
vector< RectangleShape > layers(5);
map< string, Card > cards;
vector< string > unusedCards, playingCards, discardCards;
vector< vector< string > > board;
bool playing = false;
bool running = true;

int main()
{
  srand( time(NULL) );

  window.create( VideoMode(800,500), "spider solitair", Style::Close );
  window.setFramerateLimit( 31 );

  textures.loadFromFile( "textures.png" );

  newGameButton.setFillColor( Color::Blue );
  topBar.setFillColor( Color(0,0,0) );
  cardBack.loadFromImage( textures, IntRect(1,393,72,96) );

  for ( unsigned int l = 0; l < layers.size(); l++ )
    layers[l].setTexture( &cardBack );

  initializeCards();
  reinitializeGraphics();
  newGame();

  while( running )
  {
    draw();
    input();
  }
}


// cards resource from http://www.milefoot.com/math/discrete/counting/images/cards.png