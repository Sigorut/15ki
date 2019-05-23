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
    attron(A_STANDOUT | A_BOLD | A_BLINK);
    attron(COLOR_PAIR(1));
    move(10, 50);
    printw(" 1.New game ");
    move(15, 50);
    printw(" 2.Autors");
    move(20, 50);
    printw(" 3.Exit   ");
}
void Autors()
{
    printw("Its me\n");
}
void CreateField()
{
    u_short n, i;
    int z = 0;
    for (n = 0; n < 4; n++) {
        for (i = 0; i < 4; i++) {
            Field[n][i] = z;
            z++;
        }
    }

    for (int n = 0; n < 4; n++) {
        for (int i = 0; i < 4; i++) {
            if (Field[n][i] == 0) {
                CurX = i;
                CurY = n;
            }
        }
    }
}
void Move(Direction dir)
{
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
bool FieldIsCorrect()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (Field[i][j] < Field[i][j - 1])
                return false;
        }
    return true;
}
void coutArr()
{
    int x = 20, y = 5;
    clear();
    for (int i = 0; i < 4; i++) {
        x = 40;
        y += 4;
        for (int j = 0; j < 4; j++) {
            move(y, x);
            if (Field[i][j] == 0) {
                attron(COLOR_PAIR(2));

                attron(A_STANDOUT);
                printw("%4d", Field[i][j]);
                attroff(COLOR_PAIR(2));
                attroff(A_STANDOUT);
            } else {
                attroff(A_STANDOUT);
                attron(COLOR_PAIR(1));
                printw("%4d", Field[i][j]);
            }
            x += 10;
        }
    }
    move(y + 1, 40);
    printw("To exit, press x");
    move(y + 2, 40);
    printw("To control use wasd");
    move(y + 3, 40);
    printw("Press z for a new game");
}
int main()
{
    initscr();
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    int exit = 0;
    exit += 1;
    int c;
    int key;
    while (1) {
        clear();
        Menu();
        c = getch();
        if (c == 49) {
            clear();
            int dv;
            CreateField();
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
            coutArr();
            while (1) {
                if (FieldIsCorrect()) {
                    clear();
                    printw("You win");
                    getch();
                    endwin();
                    return 0;
                }
                key = getch();
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
                    break;
                case 120:
                    endwin();
                    return 0;
                }
                coutArr();
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

