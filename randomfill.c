#include <stdio.h>
#include "randomfill.h"
#include <stdlib.h>
#include <time.h>

void randomFill(int amount,int MaxX,int MaxY,int** mineField){
    srand((unsigned) time(NULL));
    for(int i = 0; i < amount;i++){
        int x = rand() % MaxX;
        int y = rand() % MaxY;
        if(mineField[x][y] == 1){
            i--;
        }
        else{
            mineField[x][y] = 1;
        }
    }
    return;   
}
