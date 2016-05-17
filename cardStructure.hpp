#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct Card
{
  Card();

  unsigned int value = -1;
  std::string suit = "";
  sf::Texture* face = nullptr;
  sf::Texture* back = nullptr;
  sf::RectangleShape shape;
};