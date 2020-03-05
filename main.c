#include <stdio.h>
#include <stdlib.h>

#include "calculateMines.h"
#include "creation.h"
#include "randomfill.h"
#include "emptybuff.h"


char** createPlayerView(long x, long y){
    
    char** PlayerView = (char**) malloc(x * sizeof(char*));
    for(int i = 0; i < x; i++){ 
    PlayerView[i] = (char*) malloc(y * sizeof(char));
    for(int j = 0; j < y; j++){
      PlayerView[i][j] = '#';  
    }}
    return PlayerView;
    

    
}

int** createMineField(long x, long y){
    
    int** MineField =(int**) malloc(x * sizeof(int*));
    for(int i= 0; i < x; i++){ 
    MineField[i] =(int*) malloc(y * sizeof(int));
    for(int j=0; j < y ; j++){
      MineField[i][j] = 0;  
    }}
    return MineField;
    

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

printf("You have entered %lu rows, %lu columns and %lu mines\n Have fun playing\n ",x,y,minesNum);

if(x <= 1 || y <= 1){
    puts("select a bigger playground so we can have fun");
    exit(1);
}

if(minesNum <= 1){
    puts("select at least 2 or more mines");
    exit(1);
}

if(x*y <= minesNum){
    puts("We can't put more mines than fields. There has to be at least on field that is free");
    exit(1);
}

rules();//TODO should print out the rules and how to play
char** PlayerView = createPlayerView(x,y);//mallocs spaces for the PlayerView
int** MineField = createMineField(x,y);//mallocs space for the MineField
randomFill(minesNum,x,y,MineField);
int UserX;
int UserY;
int emptyspaces = x * y - minesNum;
char marking;
int GameOver = 0;
int* ret = malloc(sizeof(int));
while(!GameOver){
    marking = '0';
    creation(x,y,PlayerView);//TODO in creation
    
    printf("Gives me your coordinates x y .\n");
    scanf("%d %d",&UserY,&UserX);
    emptybuff();
    puts("Press X if you want to mark it and C for not marking it");
    scanf("%c",&marking);
    emptybuff();
    
    
    if(UserX < 0 || UserX > x || UserY < 0 || UserY > y){
        puts("please give valid coordinates");
    }
    else if(marking == 'X'){
        PlayerView[UserX][UserY] = 'X';
    }
    
    else if(MineField[UserX][UserY] == 1){
        puts("You have steped on a mine\n");
        results(MineField,x,y);
	for(int i = 0; i< x; i++){
	int* freeMe = MineField[i];
   	 free(freeMe);
	}
	free(MineField);
	for(int i = 0; i< x; i++){
	char* freeMe = PlayerView[i];
    	free(freeMe);
	}
	free(PlayerView);
	free(ret);
	PlayerView = NULL;
	MineField = NULL;
	ret = NULL;
        
        return 1;
    }
    else{
        ret[0]  = 0; 
        calculateMines(UserX,UserY,(int)x-1,(int)y-1,MineField,PlayerView,ret);//TODO in CalculatesMines
        emptyspaces -= ret[0];
        if(emptyspaces == 0){
            GameOver = 1;
        }
        
    }
}


puts("Congratulation You have won\n");
results(MineField,x,y);
 
for(int i = 0; i< x; i++){
int* freeMe = MineField[i];
    free(freeMe);
}
free(MineField);
for(int i = 0; i< x; i++){
char* freeMe = PlayerView[i];
    free(freeMe);
}
free(PlayerView);
free(ret);
PlayerView = NULL;
MineField = NULL;
ret = NULL;
return 0;
}
