FILES = program3.o City.o Map.o
NAME = program3
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

# LinkedList.o: LinkedList.cpp LinkedList.h
# 	$(CC) $(OPTION) LinkedList.cpp -o LinkedList.o
program3.o: program3.cpp
	$(CC) $(OPTION) program3.cpp -o program3.o

City.o: City.cpp	City.h
	 $(CC) $(OPTION) City.cpp -o City.o

Map.o: Map.cpp Map.h
	$(CC) $(OPTION) Map.cpp -o Map.o



clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
