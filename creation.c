#include <stdio.h>

#include "creation.h"

//should print the number then the top layer
void top(int MaxY,int check){
    printf(" ");
    for(int i = 0; i < MaxY; i++){
        printf("%d ",i);
    }
    puts("");
    if(check >= 10){
        printf("  ┌─");
        
    }
    else{
        printf(" ┌─");
    }
    for(int i = 0; i < MaxY-1; i++){
        printf("┬─");
        if(i>=10){
        printf("─");
        }
    }
    printf("┐\n");
    return;
    
}

// should print the bottom layer
void bottom(int MaxY,int check){
    if(check >= 10){
    printf("  └─");}
    else{
        printf(" └─");
    }
    for(int i = 0; i < MaxY-1; i++){
        printf("┴─");
        if(i>=10){
        printf("─");
        }
    }
    printf("┘\n");
    
    return;
}

// should print the lines between the the lines with the numbers
void intermediate(int MaxY,int check){
    if(check >= 10){
    printf("  ├─");}
    else{
        printf(" ├─");
    }
    for(int i = 0; i < MaxY-1; i++){
        printf("┼─");
        if(i>=10){
        printf("─");
        }
    }
    printf("┤\n");
    
    return;
    
}

//should print the lines that contains the char
void lines(int MaxX,int MaxY,int x,char** Visited){
    if(x>= 10){
    printf("│");}
    else{
        printf(" │");
    }
    for(int i = 0; i < MaxY; i++){
        printf("%c│",Visited[x][i]);
        if(i>=10){
        printf(" ");
        }
    }
    printf("\n");
    return;
}

//should do the main logic of the creation of the file
void creation(int MaxX,int MaxY,char** Visited){
    top(MaxY,MaxX);
    for(int i = 0; i < MaxX ; i++){
        printf("%d",i);
        lines(MaxX,MaxY,i,Visited);
        if(i < MaxX-1){
        intermediate(MaxY,MaxX);
            
        }
        
    }
    bottom(MaxY,MaxX);
    return;
}

void results(int** resultsArray,int x,int y){
    
    top(y,x);
    
    for(int i = 0; i < x ; i++){
        printf("│");
        for(int j = 0; j < y ; j++){
            if(resultsArray[i][j] == 1){
            printf("\u1F4A3│");    
            }
            else{
                printf(" │");
            }
        
        } 
        printf("\n");
        intermediate(y,x);
        
    }
    bottom(y,x);
    
    return;
}
