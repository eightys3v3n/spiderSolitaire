#include "textures.hpp"


TextureLoader::TextureLoader()
{
  suit = 1;
  texturesStart = {1,1};
  cardSize = {72,96};
  cardSpacing = {1,1};
  textures.resize(0);
}


void TextureLoader::initialize()
{
  textureFile.loadFromFile("textures.png");

  textures.resize(14);

  for ( unsigned int card = 0; card < 13; card++ )
  {
    sf::Texture texture = sf::Texture();
    sf::IntRect texture_rect = sf::IntRect(
      card * cardSpacing.x + card * cardSize.x + texturesStart.x,
      suit * cardSpacing.y + suit * cardSize.y + texturesStart.y,
      cardSize.x,
      cardSize.y
    );

    texture.loadFromImage( textureFile, texture_rect );
    textures[card] = texture;
  }

  sf::Texture texture = sf::Texture();
  sf::IntRect texture_rect = sf::IntRect(
    texturesStart.x,
    4 * cardSize.y + 4 * cardSpacing.y + texturesStart.y,
    cardSize.x,
    cardSize.y
  );

  texture.loadFromImage( textureFile, texture_rect ); // card back
  textures[13] = texture;

  texture_rect = sf::IntRect(74,389,128,32);
  newGameTexture.loadFromImage( textureFile, texture_rect );
}