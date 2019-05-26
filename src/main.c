#include "game.h"
#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned short u_short;
typedef unsigned int u_int;
int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    int exit = 0;
    exit += 1;
    int c;
    int rg = 100;
    int key;
    while (1) {
        clear();
        Menu();
        c = getch();
        if (c == 49) {
            clear();
            Lvl();
            LvlGame(rg);
            CreateField();
            RandomField();
            CoutField();
            while (1) {
                if (FieldIsCorrect()) {
                    clear();
                    attron(COLOR_PAIR(3));
                    move(15, 50);
                    printw("You win");
                    attroff(COLOR_PAIR(3));
                    getch();
                    break;
                }
                key = getch();
                if (key == 27)
                    break;
                switch (key) {
                case 119:
                    Move(up);
                    break;
                case 115:
                    Move(down);
                    break;
                case 100:
                    Move(right);
                    break;
                case 97:
                    Move(left);
                    break;
                case 122:
                    CreateField();
                    RandomField();
                    break;
                case 120:
                    endwin();
                    return 0;
                }
                CoutField();
            }
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
