#include "mine.h"
#include <stdbool.h>
#ifndef calculate
#define calculate
int calculateTopRigh(int x,int y,bool** Minefield);
int calulateTopLeft(int x,int y,bool** Minefield);
int calulateTop(int x,int y,bool** Minefield);
int calculateLeft(int x,int y,bool** Minefield);
int calculateRight(int x,int y,bool** Minefield);
int calculateBottom(int x,int y,bool** Minefield);
int calculateBottomRight(int x,int y,bool** Minefield);
int cauculateBottomLeft(int x,int y,bool** Minefield);

void calculateMines(int x,int y,bool** Minefield,char** Visited);
#endif
