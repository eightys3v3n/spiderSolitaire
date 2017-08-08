#include <stdio.h>
#include <chrono>
#include <dirent.h>
#include "gameClass.hpp"

int main()
{
  srand( time(NULL) );

  Game game;
  game.run();

  return 0;
}