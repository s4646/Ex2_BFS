.PHONY: all clean
CC=gcc
FLAGS= -Wall -Werror -g
OBJ = main.o my_mat.o
PROGS = main.o my_mat.o connections

all: $(PROGS)

connections: main.o my_mat.o
	$(CC) $(FLAGS) -o connections $(OBJ)

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

my_mat.o: my_mat.c
	$(CC) $(FLAGS) -c my_mat.c

clean: 
	rm -f *.a *.o *.so connections