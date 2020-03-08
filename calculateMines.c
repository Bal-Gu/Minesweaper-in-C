#include "calculateMines.h"
#include <stdio.h>

int calculateTopRigh(int y,int** Minefield){
    
    return Minefield[0][y-1] + Minefield[1][y] + Minefield[1][y-1];
}
int calculateTopLeft(int** Minefield){
    return Minefield[0][0] + Minefield[1][0] + Minefield[0][1];
}
int calculateTop(int y,int** Minefield){
    return Minefield[0][y-1] + Minefield[0][y+1] + Minefield[1][y-1] + Minefield[1][y] + Minefield[1][y+1];
}
int calculateLeft(int x,int** Minefield){
    return Minefield[x+1][0] + Minefield[x-1][0] + Minefield[x-1][1] + Minefield[x][1] + Minefield[x+1][1];
}

int calculateRight(int x,int y,int** Minefield){
    return Minefield[x+1][y] + Minefield[x-1][y] + Minefield[x-1][y-1] + Minefield[x][y-1] + Minefield[x+1][y-1];;
}
int calculateBottom(int x,int y,int** Minefield){
  
    return Minefield[x][y-1] + Minefield[x][y+1] + Minefield[x-1][y-1] + Minefield[x-1][y] + Minefield[x-1][y+1];
}
int calculateBottomRight(int x,int y,int** Minefield){    
    return Minefield[x][y-1] + Minefield[x-1][y] + Minefield[x-1][y-1];
}
int calculateBottomLeft(int x,int** Minefield){
    return Minefield[x-1][0] + Minefield[x-1][1] + Minefield[x][1];
}

int calculateAll(int x,int y,int** Minefield){
    
    return Minefield[x+1][y] + Minefield[x+1][y+1] + Minefield[x+1][y-1] + Minefield[x][y+1] + Minefield[x][y-1] + Minefield[x-1][y] + Minefield[x-1][y-1]+ Minefield[x-1][y+1];
}

void calculateMines(int x,int y,int MaxX,int MaxY,int** Minefield,char** Visited,int* HowManyEmptyField){
    if(Minefield[x][y] == 1){
        return;
    }
    if(x>MaxX || y>MaxY){
        return;
    }
    if(Visited[x][y] == '#'){
    HowManyEmptyField[0] = HowManyEmptyField[0] + 1;
    }
    if((Visited[x][y] >= '0' && Visited[x][y] <= '9') || (Visited[x][y] == ' ')){
        return;
    }
    int returnValue = 0;

    if(x == 0 && y == 0){
        returnValue = calculateTopLeft(Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x+1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
    
    }
    }
    else if(x == 0 && y == MaxY ){
        returnValue = calculateTopRigh(MaxY,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x+1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        
        
    }
    }
    
    else if(y == 0 && x == MaxX ){
        returnValue = calculateBottomLeft(MaxX,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x-1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
       
        
    }
    }
    else if(y == MaxY && x == MaxX ){
        returnValue = calculateBottomRight(MaxX,MaxY,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x-1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        
        
    }
    }
    
    else if(y == MaxY){
        returnValue = calculateRight(x,y,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        
    }
    }
    
    else if(x == MaxX){
        returnValue = calculateBottom(x,y,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x-1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        
            
        
    }
    }
    
    else if(y == 0){
        returnValue = calculateLeft(x,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x+1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
            
        
    }
    }
    
    else if(x == 0){
        returnValue = calculateTop(y,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);    
        
    }
    }
    else{
        returnValue = calculateAll(x,y,Minefield);
        Visited[x][y] = returnValue + '0';
        if(returnValue == 0){
        Visited[x][y] =' ';
        calculateMines(x+1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x  ,y+1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y  ,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y  ,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x+1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x-1,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        calculateMines(x  ,y-1,MaxX,MaxY,Minefield,Visited,HowManyEmptyField);
        
    }
    }
    
    
    return;
}
