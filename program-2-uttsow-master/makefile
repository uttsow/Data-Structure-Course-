FILES = Card.o Deck.o Heap.o Player.o program2.o Table.o
NAME = program2
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

# LinkedList.o: LinkedList.cpp LinkedList.h
# 	$(CC) $(OPTION) LinkedList.cpp -o LinkedList.o
program2.o: program2.cpp
	$(CC) $(OPTION) program2.cpp -o program2.o

Heap.o: Heap.cpp	Heap.h
	 $(CC) $(OPTION) Heap.cpp -o Heap.o
Card.o: Card.cpp Card.h
	$(CC) $(OPTION) Card.cpp -o Card.o

Deck.o: Deck.cpp Deck.h
	$(CC) $(OPTION) Deck.cpp -o Deck.o

Player.o: Player.cpp Player.h
	$(CC) $(OPTION) Player.cpp -o Player.o

Table.o: Table.cpp	Table.h
	$(CC) $(OPTION) Table.cpp -o Table.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
