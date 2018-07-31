FILES = lab4.o
NAME = lab4
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


lab4.o: lab4.cpp
	$(CC) $(OPTION) lab4.cpp -o lab4.o

clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
