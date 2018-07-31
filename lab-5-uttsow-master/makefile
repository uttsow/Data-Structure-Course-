FILES = lab5.o BSTree.o
NAME = lab5
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

# LinkedList.o: LinkedList.cpp LinkedList.h
# 	$(CC) $(OPTION) LinkedList.cpp -o LinkedList.o

# main.o: main.cpp
	 # $(CC) $(OPTION) main.cpp -o main.o
BSTree.o: BSTree.cpp
	$(CC) $(OPTION) BSTree.cpp -o BSTree.o

lab5.o: lab5.cpp
	$(CC) $(OPTION) lab5.cpp -o lab5.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
