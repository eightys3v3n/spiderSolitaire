gcc=g++ --std=c++17 -Wall -Wextra -g -I/home/anonymous/source
CC=""
CXX=""
.EXTENSION:


all: main

main: main.o input.o gameClass.o game.o cards.o draw.o cardStructure.o textures.o
	$(gcc) -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system


# application specific
main.o: main.cpp
	$(gcc) -c -o $@ $^

%.o: %.cpp %.hpp
	$(gcc) -c -o $@ $(filter %.cpp,$^)

%.o: %.cpp
	$(gcc) -c -o $@ $^


clean:
	rm -rf main test *.o