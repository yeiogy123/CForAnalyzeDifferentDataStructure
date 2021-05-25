all:main.o search.o search.h
    gcc -g main.o search.o -o main
    gcc -c main.c -o main.o
    gcc -c search.c -o search.o
clean:
    rm -f main.o search.o