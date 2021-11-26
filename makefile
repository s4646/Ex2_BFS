all: app

app: main.o my_mat.o
	gcc -o app main.o my_mat.o

main.o: main.c
	gcc -c main.c -Wall -Werror

my_mat.o: my_mat.c
	gcc -c my_mat.c -Wall -Werror

clear:
	rm app main.o my_mat.o