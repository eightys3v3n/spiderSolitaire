#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

extern sf::Texture cardBack;

struct Card
{
  std::string id;
  sf::Texture face;
  sf::Texture* back = &cardBack;
  sf::RectangleShape shape;
};