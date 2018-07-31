FILES = lab7.o Hash.o
NAME = lab7
CC = g++
CFLAG = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
OPTION = $(CFLAG) -c

all: $(NAME)


$(NAME): $(FILES)
	$(CC) $(CFLAG) $(FILES) -o $(NAME)



lab7.o: lab7.cpp
	 $(CC) $(OPTION) lab7.cpp -o lab7.o
	 
Hash.o: Hash.cpp Hash.h
	$(CC) $(OPTION) Hash.cpp -o Hash.o


clean:
	rm *.o $(NAME)

run:
	./$(NAME)

checkmem: all
	valgrind ./$(NAME)
