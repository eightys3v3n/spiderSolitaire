gcc=g++
gccArgs=--std=c++17 -Wall -Wextra -g
sfml=-lsfml-graphics-d -lsfml-window-d -lsfml-system-d
part=$(gcc) $(gccArgs) -c
full=$(gcc) $(gccArgs) $(sfml)


all: main

-include makefiles/*.d

dependancies:
	if [ ! -d makefiles ]; then mkdir makefiles; fi
	gcc -MMD -MF makefiles/main.d main.cpp -c -o tmp/main
	gcc -MMD -MF makefiles/cards.d cards.cpp -c -o tmp/cards.o
	gcc -MMD -MF makefiles/draw.d draw.cpp -c -o tmp/draw.o
	gcc -MMD -MF makefiles/game.d game.cpp -c -o tmp/game.o
	gcc -MMD -MF makefiles/input.d input.cpp -c -o tmp/input.o

main: tmp/draw.o tmp/input.o tmp/cards.o tmp/game.o tmp/cardStructure.o tmp/main
	$(full) tmp/*.o tmp/main -o main

tmp/draw.o: draw.cpp
	$(part) draw.cpp -o tmp/draw.o

tmp/input.o: input.cpp
	$(part) input.cpp -o tmp/input.o

tmp/cards.o: cards.cpp
	$(part) cards.cpp -o tmp/cards.o

tmp/game.o: game.cpp
	$(part) game.cpp -o tmp/game.o

tmp/cardStructure.o: cardStructure.cpp
	$(part) cardStructure.cpp -o tmp/cardStructure.o

tmp/main: main.cpp
	$(part) main.cpp -o tmp/main

clean:
	if [[ -n tmp/* ]]; then rm tmp/*; fi