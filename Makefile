part=g++ -c -static --std=c++17 -Wall -Wextra -g

all: main

main: draw.o input.o cards.o game.o cardStructure.o main.o
	g++ -g --std=c++17 -Wall -Wextra draw.o input.o cards.o game.o cardStructure.o main.o -o main -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

draw.o: draw.cpp
	$(part) draw.cpp -o draw.o

input.o: input.cpp
	$(part) input.cpp -o input.o

cards.o: cards.cpp
	$(part) cards.cpp -o cards.o

game.o: game.cpp
	$(part) game.cpp -o game.o

cardStructure.o: cardStructure.cpp
	$(part) cardStructure.cpp -o cardStructure.o

main.o: main.cpp
	$(part) main.cpp -o main.o

clean:
	if [[ -n *.o ]]; then rm -rf *.o; fi
	if [ -f main ]; then rm main; fi