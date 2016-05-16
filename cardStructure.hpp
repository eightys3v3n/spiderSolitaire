#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct Card
{
  Card();

  std::string value;
  sf::Texture* face;
  sf::Texture* back;
  sf::RectangleShape shape;
};