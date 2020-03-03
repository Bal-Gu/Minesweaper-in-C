#include <stdio.h>
#include <stdlib.h>

#include "calculateMines.h"
#include "creation.h"
#include "randomfill.h"
#include "emptybuff.h"


char** createPlayerView(long x, long y){
    
    char** PlayerView = malloc(x * sizeof(char*));
    for(int i = 0; i < x; i++){ 
    PlayerView[i] = malloc(y * sizeof(char));
    for(int j = 0; j < y; j++){
      PlayerView[i][j] = 254;  
    }
    return PlayerView;
    
}
    
}

int** createMineField(long x, long y){
    
    int** MineField = malloc(x * sizeof(int*));
    for(int i= 0; i < x; i++){ 
    MineField[i] = malloc(y * sizeof(int));
    for(int j=0; j < y ; j++){
      MineField[i][j] = 0;  
    }
    return MineField;
    
}
}
void rules(){
    //TODO
    return;
}




int main(int argc ,char* argv[]) {
if(argc != 4){
    puts("please start the programm ass follow ./minesweaper {Number of rows} {Number of columns} {Number of mines}");
    exit(1);
}
long x = strtol(argv[1],NULL,10);
long y = strtol(argv[2],NULL,10);
long minesNum = strtol(argv[3],NULL,10);

printf("You have entered %lu rows, %lu columns and %lu mines\n Have fun playing ",x,y,minesNum);

if(x <= 0 || y <= 0){
    puts("select a bigger playground so we can have fun");
    exit(1);
}

if(minesNum <= 0){
    puts("select at least 1 or more mines");
    exit(1);
}

if(x*y <= minesNum){
    puts("We can't put more mines than fields. There has to be at least on field that is free");
    exit(1);
}

rules();//TODO should print out the rules and how to play
char** PlayerView = createPlayerView(x,y);//mallocs spaces for the PlayerView
int** MineField = createMineField(x,y);//mallocs space for the MineField
randomFill(minesNum,x,y,MineField);//TODO in randomfill
int UserX;
int UserY;
int emptyspaces = x * y - minesNum;
char marking;
int GameOver = 0;
while(!GameOver){
    marking = '0';
    creation(x,y,PlayerView);//TODO in creation
    printf("Gives me your coordinates x y and X if you want to mark it");
    emptybuff();
    scanf("%d %d %c",&UserX,&UserY,&marking);
    
    
    if(UserX < 0 || UserX > x || UserY < 0 || UserY > y){
        puts("please give valid coordinates");
    }
    else if(marking = 'X'){
        PlayerView[UserX][UserY] = 'X';
    }
    
    else if(MineField[UserX][UserY] == 1){
        puts("You have steped on a mine");
        return 1;
    }
    else{
        int ret = calculateMines(UserX,UserY,MineField,PlayerView);//TODO in CalculatesMines
        emptyspaces -= ret;
        if(emptyspaces == 0){
            GameOver = 1;
        }
        
    }
}

results(MineField); //\uD83D\uDCA3 can be helpfull for bombs
puts("Congratulation You have won");


return 0;
}
