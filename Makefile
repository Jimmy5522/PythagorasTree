CC = g++
CFLAGS = -std=c++11 -g -Wall
OBJECTS = PTree.o

All: PTree
PTree: $(OBJECTS)
	$(CC) $(CFLAGS) -o PTree $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system
PTree.o: PTree.cpp
	$(CC) $(CFLAGS) -c PTree.cpp -o PTree.o
clean:
	rm PTree PTree.o
