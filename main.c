#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef enum Direction { up, down, right, left } Direction;
u_short Field[4][4];
u_short CurX, CurY;
void Menu()
{
    printw("1.New game \n");
    printw("2. Autors\n");
    printw("3.Exit \n");
}
void Autors()
{
    printw("Its me\n");
}
int main()
{
    initscr();
    int exit = 0;
    exit += 1;
    int c;
    while (1) {
        clear();
        Menu();
        c = getch();
        if (c == 49) {
            clear();
        }
        if (c == 50) {
            clear();
            Autors();
            getch();
        }
        if (c == 51) {
            endwin();
            return 0;
        }
    }
}

