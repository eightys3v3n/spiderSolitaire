#ifndef INPUT_
#define INPUT_

// checks if x&y are inside the new layer buttons.
bool clickedOnNewLayer( int x, int y );

// returns the board position of the card at clickX,clickY or -1,-1 if no card is at clickX,clickY.
sf::Vector2i clickedOnCard( int clickX, int clickY );

// move card(x,y) to columb d if possible, else move the stack back to where it was.
void cardDrag( sf::Vector2i card, int d );

// events for when the left mouse button released.
void leftReleased( sf::Vector2f p );

// moves the floating cards to under the mouse.
void moveFloatingCards( sf::Vector2f offset, int x, int y );

// process window events.
void input();

#endif // INPUT_