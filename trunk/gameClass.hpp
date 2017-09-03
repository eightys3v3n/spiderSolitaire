#ifndef GAMECLASS_
#define GAMECLASS_

#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "textures.hpp"

#define DRAW_ERROR 1
#define INPUT_ERROR 2

class Game
{
public:
  sf::RenderWindow window;
  bool running;
  int error;

  struct Card
  {
    Card(unsigned int x, unsigned int y);

    int value;
    sf::Texture* face;
    sf::Texture* back;
    sf::RectangleShape shape;
  };

  // gameClass.cpp
    Game();
    ~Game();
    void run();

  // input.cpp
    int input();

  // draw.cpp
    int draw();

private:
  sf::View view;
  // sf::Texture newGameTexture;
  // std::vector<sf::Texture> textures;
  sf::RectangleShape newGameButton;
  sf::RectangleShape topBar;
  std::vector<sf::RectangleShape> completedStacks;
  // sf::Vector2i texturesStart;
  // sf::Vector2i cardSize;
  // sf::Vector2i cardSpacing;
  sf::Vector2i clickedCard;
  sf::Vector2i moveTo;
  std::vector<Card> cards;
  std::vector<Card*> unusedCards;
  std::vector< std::vector<Card*> > board;
  std::vector<sf::RectangleShape> layers;
  // sf::Image textureFile;
  std::vector<sf::FloatRect> columbs;
  sf::Vector2f clickOffset;
  std::chrono::high_resolution_clock::time_point timeClicked;
  std::chrono::high_resolution_clock::time_point startTime, endTime;
  // int suit;
  bool playing;
  bool holdingCards;
  unsigned int layersToDraw;
  unsigned int completedStacksToDraw;
  std::string structure;
  std::string prevStructure;
  std::string prefix;

  TextureLoader texture_loader;

  // gameClass.cpp
    void initialize();
    // void open();
    // void send(std::string m);
    // void addP(std::string n);
    // void removeP();

  // draw.cpp
    void resizeNewLayers();
    void resizeCompletedStacks();
    void resizeTopBar(unsigned int n);
    void resizeElements();
    void loadTextures();
    void initializeGraphics();
    void drawLayers();
    void drawCompletedStacks();
    void drawCards();
    void drawFloatingCards();

  // cards.cpp
    void scaleCards();
    void initializeTextures();
    void initializeCards();
    bool finishedGame();
    Card* randomCard();
    sf::Vector2f absoluteCardPosition(unsigned int x, unsigned int y);
    sf::Vector2f relativeCardPosition( unsigned int x, unsigned int y );
    bool movableStack( unsigned int x, unsigned int y );
    bool validMove( unsigned int x, unsigned int y, unsigned int newX );
    void completeStack( unsigned int x );
    unsigned int getMovableStackSize( unsigned int x );
    void resizeStack( unsigned int x );
    void resetStack( sf::Vector2i card );
    void moveCards( unsigned int x, unsigned int y, unsigned int newX );
    void autoMoveCards( unsigned int x, unsigned int y );

  // game.cpp
    void newGame();
    void newLayer();

  // input.cpp
    bool clickedOnNewLayer( int x, int y );
    sf::Vector2i clickedOnCard( int clickX, int clickY );
    void cardDrag( sf::Vector2i card, int d );
    void leftReleased( sf::Vector2f p );
    void moveFloatingCards( sf::Vector2f offset, int x, int y );
    int androidInput(sf::Event& event);
    int pcInput(sf::Event& event);
};

#endif