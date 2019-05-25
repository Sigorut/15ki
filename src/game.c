#include "game.h"
#include "menu.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned short u_short;
typedef unsigned int u_int;
u_short Field[4][4], Field1[5][5];
u_short CurX, CurY;
int ch = 100;
int LvlGame(int rg)
{
    move(100, 100);
    while (1) {
        if (rg == 100) {
            rg = getch();
            clear();
            Lvl();
        }
        if (rg == 49)
            ch = 0;
        if (rg == 50)
            ch = 1;
        if ((ch == 1) || (ch == 0))
            break;
    }
    return ch;
}
int CreateField()
{
    u_short n, i, res;
    int z = 0;
    if (ch == 0) {
        for (n = 0; n < 4; n++) {
            for (i = 0; i < 4; i++) {
                Field[n][i] = z;
                z++;
                res = 0;
            }
        }
    }
    if (ch == 1) {
        for (n = 0; n < 5; n++)
            for (i = 0; i < 5; i++) {
                Field1[n][i] = z;
                z++;
                res = 1;
            }
    }

    CurX = 0;
    CurY = 0;
    return res;
}
void Move(Direction dir)
{
    if (ch == 0) {
        switch (dir) {
        case up:
            if (CurY > 0) {
                Field[CurY][CurX] = Field[CurY - 1][CurX];
                Field[CurY - 1][CurX] = 0;
                CurY--;
            }
            break;
        case down:
            if (CurY < 3) {
                Field[CurY][CurX] = Field[CurY + 1][CurX];
                Field[CurY + 1][CurX] = 0;
                CurY++;
            }

            break;
        case right:
            if (CurX < 3) {
                Field[CurY][CurX] = Field[CurY][CurX + 1];
                Field[CurY][CurX + 1] = 0;
                CurX++;
            }
            break;
        case left:
            if (CurX > 0) {
                Field[CurY][CurX] = Field[CurY][CurX - 1];
                Field[CurY][CurX - 1] = 0;
                CurX--;
            }
            break;
        }
    }
    if (ch == 1) {
        switch (dir) {
        case up:
            if (CurY > 0) {
                Field1[CurY][CurX] = Field1[CurY - 1][CurX];
                Field1[CurY - 1][CurX] = 0;
                CurY--;
            }
            break;
        case down:
            if (CurY < 4) {
                Field1[CurY][CurX] = Field1[CurY + 1][CurX];
                Field1[CurY + 1][CurX] = 0;
                CurY++;
            }

            break;
        case right:
            if (CurX < 4) {
                Field1[CurY][CurX] = Field1[CurY][CurX + 1];
                Field1[CurY][CurX + 1] = 0;
                CurX++;
            }
            break;
        case left:
            if (CurX > 0) {
                Field1[CurY][CurX] = Field1[CurY][CurX - 1];
                Field1[CurY][CurX - 1] = 0;
                CurX--;
            }
            break;
        }
    }
}
bool FieldIsCorrect()
{
    if (ch == 0) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (Field[i][j] < Field[i][j - 1])
                    return false;
            }
        return true;
    }
    if (ch == 1) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++) {
                if (Field1[i][j] < Field1[i][j - 1])
                    return false;
            }
        return true;
    }
    return false;
}
void RandomField()
{
    int dv;
    for (int i = 0; i < 10000; i++) {
        dv = rand() % 4 + 1;
        if (dv == 1)
            Move(up);
        if (dv == 2)
            Move(down);
        if (dv == 3)
            Move(right);
        if (dv == 4)
            Move(left);
    }
}
void CoutField()
{
    int x = 20, y = 4;
    clear();
    if (ch == 0) {
        for (int i = 0; i < 4; i++) {
            x = 40;
            y += 4;
            for (int j = 0; j < 4; j++) {
                move(y, x);
                if (Field[i][j] == 0) {
                    printw("   ");
                    attron(COLOR_PAIR(2));

                    attron(A_STANDOUT);
                    printw("%d", Field[i][j]);
                    attroff(COLOR_PAIR(5));
                    attroff(A_STANDOUT);
                } else {
                    attroff(A_STANDOUT);
                    attron(COLOR_PAIR(3));
                    printw("%4d", Field[i][j]);
                    attroff(COLOR_PAIR(3));
                }
                x += 10;
            }
        }
    }
    if (ch == 1) {
        y = 4;
        for (int i = 0; i < 5; i++) {
            x = 40;
            y += 4;
            for (int j = 0; j < 5; j++) {
                move(y, x);
                if (Field1[i][j] == 0) {
                    printw("   ");
                    attron(COLOR_PAIR(2));

                    attron(A_STANDOUT);
                    printw("%d", Field1[i][j]);
                    attroff(COLOR_PAIR(5));
                    attroff(A_STANDOUT);
                } else {
                    attroff(A_STANDOUT);
                    attron(COLOR_PAIR(3));
                    printw("%4d", Field1[i][j]);
                    attroff(COLOR_PAIR(3));
                }
                x += 10;
            }
        }
    }
    attron(COLOR_PAIR(3));
    attron(A_STANDOUT);
    move(y + 2, 40);
    printw("Press x for a Exit");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    move(y + 3, 40);
    printw("To control use wasd");
    move(y + 4, 40);
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(5));
    printw("Press z for a new game");
    attroff(A_STANDOUT | COLOR_PAIR(5));
}
