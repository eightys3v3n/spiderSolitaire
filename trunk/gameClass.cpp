#include "gameClass.hpp"


Game::Game()
{
  #ifdef ANDROID
  window.create(sf::VideoMode::getDesktopMode(), "");
  #else
  window.create(sf::VideoMode(800,500),"spider solitaire");
  #endif

  window.setFramerateLimit(31);
  completedStacks.resize(8);
  layers.resize(5);

  // texturesStart = {1,1};
  // cardSize = {72,96};
  // cardSpacing = {1,1};
  // suit = 1;

  initialize();
}


Game::~Game()
{
  running = false;
  window.close();
}


void Game::initialize()
{
  // textureFile.loadFromFile("textures.png");
  // initializeTextures();
  texture_loader.initialize();
  initializeCards();
  initializeGraphics();

  newGame();

  columbs.resize( 10 );
  for ( unsigned int i = 0; i < 10; i++ )
    columbs[i] = board[i][0]->shape.getGlobalBounds();

}

void Game::run()
{
  while(running)
  {
    draw();
    input();
  }
}