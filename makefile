all:main.o search.o
	gcc -g search.o main.o -o main
	gcc -c main.c -o main.o
	gcc -c search.c -o search.o
clean:
	rm -f search.o main.o
