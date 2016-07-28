#ifndef DRAW_
#define DRAW_

// sets position & texture of menu elements.
void initializeGraphics();

// draw how many more layers the player has left.
void drawLayers();

// draws how many stacks the player has completed.
void drawCompletedStacks();

// draws all the cards on the board.
void drawCards();

// draws the cards that are being dragged.
void drawFloatingCards();

// re-draws all elements.
void draw();

#endif // DRAW_