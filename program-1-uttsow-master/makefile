FILES = LinkedList.o Ant.o AntHill.o program1.o
NAME = LinkedList
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CC) $(OPTION) LinkedList.cpp -o LinkedList.o

# main.o: main.cpp
# 	$(CC) $(OPTION) main.cpp -o main.o


Ant.o: Ant.cpp
	$(CC) $(OPTION) Ant.cpp -o Ant.o

AntHill.o: AntHill.cpp
	$(CC) $(OPTION) AntHill.cpp -o AntHill.o

program1.o: program1.cpp
	$(CC) $(OPTION) program1.cpp -o program1.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
