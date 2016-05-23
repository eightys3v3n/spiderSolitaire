#ifndef MAIN_
#define MAIN_

#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cardStructure.hpp"

sf::RenderWindow window;
sf::RectangleShape newGameButton, topBar;
sf::Image textureFile;
std::vector< sf::RectangleShape > layers(5);
std::vector< sf::RectangleShape > completedStacks(8);
std::vector< Card > cards;
std::vector< Card* > unusedCards;
std::vector< sf::Texture > textures;
std::vector< std::vector< Card* > > board;
std::vector< sf::FloatRect > columbs;
sf::Vector2i clickedCard, moveTo;
sf::Vector2i texturesStart( 1, 1 );
sf::Vector2i cardSize( 72, 96 );
sf::Vector2i cardSpacing( 1, 1 );
sf::Vector2f clickOffset;
std::chrono::high_resolution_clock::time_point timeClicked;
int suit = 1; // 0-clubs, 1-spades
bool playing = false;
bool running = true;
bool holding = false;
unsigned int layersToDraw = 5;
unsigned int completedStacksToDraw = 0;

#endif // MAIN_