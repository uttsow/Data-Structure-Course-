FILES = lab6.o Card.o Deck.o
NAME = lab6
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

# LinkedList.o: LinkedList.cpp LinkedList.h
# 	$(CC) $(OPTION) LinkedList.cpp -o LinkedList.o

lab6.o: lab6.cpp
	 $(CC) $(OPTION) lab6.cpp -o lab6.o
Card.o: Card.cpp Card.h
	$(CC) $(OPTION) Card.cpp -o Card.o

Deck.o: Deck.cpp Deck.h
	$(CC) $(OPTION) Deck.cpp -o Deck.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
