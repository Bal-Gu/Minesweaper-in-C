#include "mine.h"
#ifndef calculate
#define calculate
int calculateTopRigh(int x,int y,int** Minefield);
int calulateTopLeft(int x,int y,int** Minefield);
int calulateTop(int x,int y,int** Minefield);
int calculateLeft(int x,int y,int** Minefield);
int calculateRight(int x,int y,int** Minefield);
int calculateBottom(int x,int y,int** Minefield);
int calculateBottomRight(int x,int y,int** Minefield);
int cauculateBottomLeft(int x,int y,int** Minefield);

int calculateMines(int x,int y,int** Minefield,char** Visited);
#endif
