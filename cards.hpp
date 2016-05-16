#include <string>
#include <SFML/System.hpp>

void initializeTextures();
void initializeCards();
Card* randomCard();
sf::Vector2f cardPosition(unsigned int x, unsigned int y);
