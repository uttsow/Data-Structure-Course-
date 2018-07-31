FILES = lab3.o Ant.o AntHill.o
NAME = lab3
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

lab3.o: lab3.cpp
	$(CC) $(OPTION) lab3.cpp -o lab3.o

Ant.o: Ant.cpp
	$(CC) $(OPTION) Ant.cpp -o Ant.o

AntHill.o: AntHill.cpp
	$(CC) $(OPTION) AntHill.cpp -o AntHill.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
