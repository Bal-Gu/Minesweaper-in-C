#include <stdio.h>

#include "creation.h"

//should print the number then the top layer
void top(int MaxX){
    puts(" ");
    for(int i = 0; i < MaxX; i++){
        puts("%d ",i);
    }
    puts("┌─");
    for(int i = 0; i < MaxX; i++){
        puts("┬─");
    }
    puts("┐\n");
    return;
    
}

void bottom(int MaxX){
    // should print the bottom layer
    puts("└─");
    for(int i = 0; i < MaxX; i++){
        puts("┴─");
    }
    puts("┘\n");
    
    return;
}

void intermediate(int MaxX){
    // should print the lines between the the lines with the numbers
    puts("├─");
    for(int i = 0; i < MaxX; i++){
        puts("┼─");
    }
    puts("┤\n");
    
    return;
    
}

void lines(int MaxX,int MaxY,char** Visited){
    //TODO should print the main lines with the numbers inside of it
    return;
}

void creation(int MaxX,int MaxY,char** Visited){
    //TODO should do the main logic of the creation of the file

    return;
}

void results(int** resultsArray,int x,int y){
    
    top(x);
    
    for(int i = 0; i < x ; i++){
        puts("│");
        for(int j = 0; j < y ; j++){
            if(resultsArray[i][j] == 1){
            printf("\uD83D\uDCA3│");    
            }
            else{
                puts(" │");
            }
        
        } 
        puts("\n");
        intermediate(x);
        
    }
    bottom(x);
    
    return;
}
