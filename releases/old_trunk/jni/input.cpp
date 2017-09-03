#include <iostream>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "gameClass.hpp"

// checks if x&y are inside the new layer buttons.
bool Game::clickedOnNewLayer( int x, int y )
{

  for ( unsigned int l = 0; l < layersToDraw; l++ )
    if ( layers[l].getGlobalBounds().contains( sf::Vector2f( x, y ) ) )
      return true;

  return false;
}

// returns the board position of the card at clickX,clickY or -1,-1 if no card is at clickX,clickY.
sf::Vector2i Game::clickedOnCard( int clickX, int clickY )
{

  // was a card clicked?
  for ( unsigned int x = 0; x < board.size(); x++ )
    for ( int y = board[x].size() - 1; y > -1; y-- )
      if ( board[x][y]->shape.getGlobalBounds().contains( clickX, clickY ) && sf::Vector2i( x, y ) != clickedCard )
        return sf::Vector2i( x, y );

  // was empty stack clicked?
  for ( unsigned int x = 0; x < 10; x++ )
    if ( columbs[x].contains( clickX, clickY) )
      return sf::Vector2i( x, 0 );

  return sf::Vector2i(-1,-1); // (-1,-1) if no card clicked
}

// move card(x,y) to columb d if possible, else move the stack back to where it was.
void Game::cardDrag( sf::Vector2i card, int d )
{
  // if released over another possible stack of cards
  if ( validMove( card.x, card.y, d ) )
    moveCards( card.x, card.y, d );

  else
    resetStack( card ); // put floating cards back in stack.
}


// events for when the left mouse button released.
void Game::leftReleased(sf::Vector2f p)
{

  if ( holdingCards )
  {
    if( std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now() - timeClicked ).count() > 120 )
    {
      if ( ( moveTo = clickedOnCard( p.x, p.y ) ) != sf::Vector2i( -1, -1 ) )
        cardDrag( clickedCard, moveTo.x ); // person dragged card.
      else
        resetStack( clickedCard ); // put card back on it's stack.
    }

    else
      autoMoveCards( clickedCard.x, clickedCard.y ); // person clicked on card.
  }

  holdingCards = false;
}

// moves the floating cards to under the mouse.
void Game::moveFloatingCards( sf::Vector2f offset, int x, int y )
{

  sf::Vector2f move(0,0);

  move.x = x - offset.x - board[clickedCard.x][clickedCard.y]->shape.getPosition().x;
  move.y = y - offset.y - board[clickedCard.x][clickedCard.y]->shape.getPosition().y;

  for ( unsigned int c = clickedCard.y; c < board[clickedCard.x].size(); c++ )
    board[ clickedCard.x ][ c ]->shape.move( move.x, move.y );
}

// process window events.
void Game::input()
{

  sf::Event event;

  while( window.pollEvent( event ) )
  {
    switch( event.type )
    {
      case sf::Event::Closed:
        running = false;
        window.close();
        break;

      case sf::Event::Resized:
        #ifdef ANDROID
        view.setSize(event.size.width, event.size.height);
        view.setCenter(event.size.width/2, event.size.height/2);
        window.setView(view);
        #endif // ANDROID
        break;

      #ifndef ANDROID
      case sf::Event::MouseButtonPressed:
        if ( event.mouseButton.button == sf::Mouse::Left )
        {
          if ( newGameButton.getGlobalBounds().contains( sf::Vector2f( event.mouseButton.x, event.mouseButton.y ) ) )
            newGame();

          else if ( clickedOnNewLayer( event.mouseButton.x, event.mouseButton.y ) )
            newLayer();

          // clicked on a card
          else if ( ( clickedCard = clickedOnCard( event.mouseButton.x, event.mouseButton.y ) ) != sf::Vector2i( -1, -1 ) )
          {
            if ( movableStack( clickedCard.x, clickedCard.y ) )
            {
              clickOffset.x = event.mouseButton.x - board[clickedCard.x][clickedCard.y]->shape.getPosition().x;
              clickOffset.y = event.mouseButton.y - board[clickedCard.x][clickedCard.y]->shape.getPosition().y;

              holdingCards = true;

              timeClicked = std::chrono::high_resolution_clock::now();
            }
          }
        }
        //else if ( event.mouseButton.button == sf::Mouse::Right )
          //std::cout << clickedOnCard( event.mouseButton.x, event.mouseButton.y ).x << "," << clickedOnCard( event.mouseButton.x, event.mouseButton.y ).y << std::endl;
        break;

      case sf::Event::MouseButtonReleased:
        if ( event.mouseButton.button == sf::Mouse::Left )
        {
          leftReleased( sf::Vector2f(event.mouseButton.x, event.mouseButton.y) );
          clickedCard = sf::Vector2i(-1,-1);
        }
        break;
      #else // ANDROID is defined
      case sf::Event::TouchBegan:
        if ( newGameButton.getGlobalBounds().contains( sf::Vector2f(event.touch.x,event.touch.y) ) )
          newGame();

        else if ( clickedOnNewLayer( event.touch.x, event.touch.y ) )
          newLayer();

        else if (( clickedCard = clickedOnCard(event.touch.x, event.touch.y)) != sf::Vector2i(-1,-1))
        {
          if (movableStack(clickedCard.x, clickedCard.y))
          {
            clickOffset.x = event.mouseButton.x - board[clickedCard.x][clickedCard.y]->shape.getPosition().x;
            clickOffset.y = event.mouseButton.y - board[clickedCard.x][clickedCard.y]->shape.getPosition().y;

            holdingCards = true;

            timeClicked = std::chrono::high_resolution_clock::now();
          }
        }
        break;

      case sf::Event::TouchMoved:
        if (event.touch.finger == 0)
        {
          if (holdingCards)
            moveFloatingCards(clickOffset, event.touch.x, event.touch.y);
        }
        else if (event.touch.finger == 1)
        {
          if (completedStacksToDraw < 8 && ! t)
          {
            t = true;
            completedStacksToDraw++;
          }
        }
        break;

      case sf::Event::TouchEnded:
        leftReleased(sf::Vector2f(event.touch.x, event.touch.y));
        clickedCard = sf::Vector2i(-1,-1);

        if (event.touch.finger == 1)
          t = false;
        break;
      #endif // ANDROID
    }
  }
}