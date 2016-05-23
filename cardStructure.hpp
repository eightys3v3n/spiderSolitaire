#ifndef CARDSTRUCT_
#define CARDSTRUCT_

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct Card
{
  Card();

  unsigned int value = -1;
  sf::Texture* face = nullptr;
  sf::Texture* back = nullptr;
  sf::RectangleShape shape;
};

#endif // CARDSTRUCT_