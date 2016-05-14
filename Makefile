part=g++ -c --std=c++17 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system
norm=g++ --std=c++17 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

all: main

main: draw.o input.o cards.o game.o main.o
	$(norm) draw.o input.o cards.o game.o main.o -o main

draw.o: draw.cpp
	$(part) draw.cpp -o draw.o

input.o: input.cpp
	$(part) input.cpp -o input.o

card.o: cards.cpp
	$(part) cards.cpp -o cards.o

game.o: game.cpp
	$(part) game.cpp -o game.o

main.o: main.cpp
	$(part) main.cpp -o main.o

clean:
	if [[ -n *.o ]]; then rm -rf *.o; fi
	if [ -f main ]; then rm main; fi