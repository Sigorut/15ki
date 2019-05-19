all: main.c
	g++ -Wall -Werror -o main main.c -lncurses
