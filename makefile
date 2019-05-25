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
	rm -rf $(EXECUTABLE) bin/game_test $(OD)*.o build/test/*.o
test: build/test bin/game_test
build/test:
	mkdir build/test -p
bin/game_test: build/test/main.o build/test/game.o build/test/menu.o
	$(CC) $(CFLAGS) build/test/main.o build/test/game.o  build/test/menu.o -o bin/game_test -lm -lncurses
build/test/main.o: test/main.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o build/test/main.o -lm -lncurses
build/test/game.o: src/game.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/game.c -o build/test/game.o -lm -lncurses
build/test/menu.o: src/menu.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/menu.c -o build/test/menu.o -lm -lncurses 
