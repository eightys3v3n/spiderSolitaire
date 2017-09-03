#ifndef CARDSTRUCT_
#define CARDSTRUCT_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct Card
{
  Card();

  int value = -1;
  sf::Texture* face = nullptr;
  sf::Texture* back = nullptr;
  sf::RectangleShape shape;
};

#endif // CARDSTRUCT_