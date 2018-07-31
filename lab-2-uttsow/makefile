FILES = lab2.o AntHill.o
NAME = lab2
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)

lab2.o: lab2.cpp AntHill.h
	$(CC) $(OPTION) lab2.cpp -o lab2.o

AntHill.o: AntHill.cpp AntHill.h
	$(CC) $(OPTION) AntHill.cpp -o AntHill.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
