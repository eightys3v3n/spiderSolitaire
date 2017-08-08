#ifndef DRAW_
#define DRAW_

// resizes the newLayer shapes based on the size of the topBar.
void resizeNewLayers();

// resizes the completedStacks shapes based on the size of the topBar.
void resizeCompletedStacks();

// resize the top bar to 1/n the screen height.
void resizeTopBar(unsigned int n);

// resize all the screen elements.
void resizeElements();

// load textures for screen elements (excluding cards).
void loadTextures();

// sets position & texture of screen elements (excluding cards).
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
int draw();

#endif // DRAW_