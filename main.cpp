#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "draw.hpp"
#include "input.hpp"
#include "cardStructure.hpp"
using namespace std;
using namespace sf;

RenderWindow window;
RectangleShape newGameButton, topBar, cardBack;
vector< RectangleShape > layers(5);
map< string, Card > cards;
bool playing = false;
bool running = true;

int main()
{
  window.create( VideoMode(800,500), "spider solitair", Style::Close );
  window.setFramerateLimit( 31 );

  newGameButton.setFillColor( Color::Blue );
  topBar.setFillColor( Color( 0, 0, 0 ) );
  cardBack.setFillColor( Color( 200, 200, 200 ) );

  layers[0].setFillColor( Color::Red );
  layers[1].setFillColor( Color::White );
  layers[2].setFillColor( Color::Red );
  layers[3].setFillColor( Color::White );
  layers[4].setFillColor( Color::Red );

  // sets the size and position of graphical elements
  reinitializeGraphics();

  while( running )
  {
    draw();
    input();
  }
}