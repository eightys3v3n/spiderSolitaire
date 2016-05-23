#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "main.hpp"
#include "draw.hpp"
#include "input.hpp"
#include "cardStructure.hpp"
#include "cards.hpp"
#include "game.hpp"
using namespace std;
using namespace sf;
using namespace std::chrono;

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