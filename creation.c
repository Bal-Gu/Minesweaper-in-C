#include <stdio.h>

#include "creation.h"


void top(int MaxX,int MaxY){
    //TODO should print the number then the top layer
    return;
    
}

void bottom(int MaxX,int MaxY){
    //TODO should print the bottom layer
    return;
}

void intermediate(int MaxX,int MaxY){
        //TODO should print the lines between the the lines with the numbers
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
    //TODO should print the final minefield
    top(x);
    
    for(int i = 0; i < x ; i++){
        puts("│");
        for(int j = 0; j < y ; j++){
        printf("%d│",resultsArray[i][j]);
        } 
        puts("\n");
        intermediate(x);
        
    }
    bottom(x);
    
    return;
}
