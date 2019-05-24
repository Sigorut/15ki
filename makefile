.PHONY:all clean
CC = gcc
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/Game.exe

all: build/ bin/ $(EXECUTABLE)
build/:
	mkdir build/ -p
$(EXECUTABLE):	$(OD)main.o $(OD)menu.o $(OD)game.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)menu.o $(OD)game.o -lncurses
$(OD)main.o: $(SD)main.c
	$(CC) $(CFLAGS) -c -o $(OD)main.o $(SD)main.c -lncurses
$(OD)game.o: $(SD)game.c
	$(CC) $(CFLAGS) -c -o $(OD)game.o $(SD)game.c -lncurses
$(OD)menu.o: $(SD)menu.c
	$(CC) $(CFLAGS) -c -o $(OD)menu.o $(SD)menu.c -lncurses
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o 
