#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <thread>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <dirent.h>
#include "socket.hpp"
#include "gameClass.hpp"

using namespace std;
using namespace sf;
using namespace chrono;

Game::Game()
{
  window.create(VideoMode::getDesktopMode(), "");

  view = window.getDefaultView();

  window.setFramerateLimit(31);

  completedStacks.resize(8);
  texturesStart = {1,1};
  cardSize = {72,96};
  cardSpacing = {1,1};
  layers.resize(5);

  initialize();
}

void Game::initialize()
{
  textureFile.loadFromFile("textures.png");

  initializeTextures();
  initializeCards();
  initializeGraphics();
  newGame();

  columbs.resize( 10 );

  for ( unsigned int i = 0; i < 10; i++ )
    columbs[i] = board[i][0]->shape.getGlobalBounds();
}

int vibrate(sf::Time duration);

int main()
{
  srand( time(NULL) );

  Game game;

  while( game.running )
  {
    game.draw();
    game.input();
  }

  return 0;
}

/*
Texture texture;
  if (! texture.loadFromFile("image.png"))
    return 1;

  Sprite image(texture);
  image.setPosition(0, 0);
  image.setOrigin(texture.getSize().x/2, texture.getSize().y/2);


  while (window.isOpen())
  {
    Event event;

    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        case Event::Closed:
          window.close();
          break;
        case Event::Resized:
          view.setSize(event.size.width, event.size.height);
          view.setCenter(event.size.width/2, event.size.height/2);
          window.setView(view);
          break;
        case Event::TouchBegan:
          if (event.touch.finger == 0)
            image.setPosition(event.touch.x, event.touch.y);
          break;
      }
    }

    window.clear(Color::White);
    window.draw(image);
    window.display();
  }
*/


// Since we want to get the native activity from SFML, we'll have to use an
// extra header here:

// NDK/JNI sub example - call Java code from native code
