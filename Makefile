part=g++ -c -static --std=c++17 -Wall -Wextra -g
sfml=-lsfml-graphics-d -lsfml-window-d -lsfml-system-d

all: tmp main #tests

tmp:
	mkdir tmp

main: tmp/draw.o tmp/input.o tmp/cards.o tmp/game.o tmp/cardStructure.o tmp/main.o
	g++ -g --std=c++17 -Wall -Wextra $(sfml) tmp/*.o -o main

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

tmp/main.o: main.cpp
	$(part) main.cpp -o tmp/main.o

clean:
	if [ -d tmp ]; then rm -rf tmp; fi