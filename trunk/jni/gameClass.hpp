#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
public:
  // to stop the debug touch being detected multiple times.
  bool t = false;

  bool running = true;

  struct Card
  {
    Card(unsigned int x, unsigned int y);

    int value = -1;
    sf::Texture* face = nullptr;
    sf::Texture* back = nullptr;
    sf::RectangleShape shape;
  };

  // main.cpp
    Game();

  // input.cpp
    void input();

  // draw.cpp
    void draw();

private:
  sf::RenderWindow window;
  sf::View view;
  sf::Texture newGameTexture;
  std::vector<sf::Texture> textures;
  sf::RectangleShape newGameButton;
  sf::RectangleShape topBar;
  std::vector<sf::RectangleShape> completedStacks;
  sf::Vector2i texturesStart;
  sf::Vector2i cardSize;
  sf::Vector2i cardSpacing;
  sf::Vector2i clickedCard;
  sf::Vector2i moveTo;
  std::vector<Card> cards;
  std::vector<Card*> unusedCards;
  std::vector< std::vector<Card*> > board;
  std::vector<sf::RectangleShape> layers;
  sf::Image textureFile;
  std::vector<sf::FloatRect> columbs;
  sf::Vector2f clickOffset;
  std::chrono::high_resolution_clock::time_point timeClicked;
  std::chrono::high_resolution_clock::time_point startTime, endTime;
  int suit = 1;
  bool playing = false;
  bool holdingCards = false;
  unsigned int layersToDraw = 5;
  unsigned int completedStacksToDraw = 0;

  // main.cpp
    void initialize();

  // draw.cpp
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
};