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
void CreateField()
{
    u_short arr[16], n, i, buf;
    bool flag = false;
    srand(time(NULL));
    for (n = 0; n < 16;) {
        flag = false;
        buf = rand() % 16 + 1;
        for (i = 0; i < n; i++) {
            if (arr[i] == buf) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            arr[n] = buf;
            n++;
        }
    }
    int z = 0;
    for (n = 0; n < 4; n++) {
        for (i = 0; i < 4; i++) {
            Field[n][i] = z;
            z++;
            // Field[n][i]=arr[k]-1
            // k++
        }
    }
    Field[0][0] = 1;
    Field[0][1] = 0;
    for (n = 0; n < 4; n++) {
        for (i = 0; i < 4; i++) {
            if (Field[n][i] == 0) {
                CurX = i;
                CurY = n;
            }
        }
    }
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

