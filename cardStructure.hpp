#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

extern sf::Texture cardBack;

struct Card
{
  Card();

  std::string id;
  sf::Texture face;
  sf::Texture* back;
  sf::RectangleShape shape;
};