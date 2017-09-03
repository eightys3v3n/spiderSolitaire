#ifndef TEXTURES_
#define TEXTURES_


#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


struct TextureLoader
{
  sf::Vector2i texturesStart;
  sf::Vector2i cardSize;
  sf::Vector2i cardSpacing;
  int suit;
  std::vector<sf::Texture> textures;
  sf::Texture newGameTexture;
  sf::Image textureFile;

  TextureLoader();
  void initialize();
};


#endif