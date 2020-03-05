
#ifndef calculate
#define calculate
int calculateTopRigh(int y,int** Minefield);
int calculateTopLeft(int** Minefield);
int calculateTop(int y,int** Minefield);
int calculateLeft(int x,int** Minefield);
int calculateRight(int x,int y,int** Minefield);
int calculateBottom(int x,int y,int** Minefield);
int calculateBottomRight(int x,int y,int** Minefield);
int calculateBottomLeft(int x,int** Minefield);
int calculateAll(int x,int y,int** Minefield);

void calculateMines(int x,int y,int MaxX,int MaxY,int** Minefield,char** Visited,int* HowManyNonMineField);
#endif
