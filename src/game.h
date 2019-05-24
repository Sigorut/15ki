#ifndef GAME_H
#define GAME_H
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Direction { up, down, right, left } Direction;
void CreateField();
void Move(Direction dir);
bool FieldIsCorrect();
void RandomField();
void CoutField();

#endif
