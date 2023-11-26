#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "checkobstacle.h"
#include "artifact.h"
#include "outputboard.h"
#include "botalgorithm.h"

extern int HEIGHT;
extern int WIDTH;
extern char GROUPNAME[16];
extern int myID;


void checkOurNameIdPoint(PLAYER *player, int *num_player, int *myID);
void searchNum_amazonOnBoardByID(Amazon *myAmazons, PLAYER *player, int board[][WIDTH], int myID, int *num_amazon);
int selectAmazonAndMove(Amazon *myAmazons, PLAYER player[], int board[][WIDTH], int num_amazon, int myID, int num_player);


int movement(char argc, char* argv[], PLAYER *player){
    Amazon myAmazons[10];
    FILE *file=NULL;
    char *inputpath = argv[2];
    file = fopen(inputpath,"r+");
    fscanf(file, "%d %d", &HEIGHT, &WIDTH);// scan a board array
    int board[HEIGHT][WIDTH];//make a board array
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            fscanf(file, "%d ", &board[y][x]);
        }
    }
    //scan player's name, ID, point
    int num_player=0;
    while (fscanf(file, "%s %d %d", player[num_player+1].name, &player[num_player+1].ID, &player[num_player+1].point) != EOF)
    {
        num_player++;
        printf("%s %d %d\n", player[num_player].name, player[num_player].ID, player[num_player].point);
    }
    printf("num_player is %d\n", num_player);
    fclose(file);
    displayBoard(HEIGHT, WIDTH, board, num_player, player);
    checkOurNameIdPoint(player, &num_player, &myID);
    int num_amazon;
    searchNum_amazonOnBoardByID(myAmazons, player, board, myID, &num_amazon);
    if (canAmazonsMove(myAmazons, board, num_amazon) == 1){
        return 1;
    }
    selectAmazonAndMove(myAmazons, player, board, num_amazon, myID, num_player);
    displayBoard(HEIGHT, WIDTH, board, num_player, player);
    char *outputpath = argv[3];
    outputBoard(HEIGHT, WIDTH, board, num_player, player, outputpath);
    return 0;
}

//  outline ：You can check your name, ID, point and GET YOUR ID.
//  return ： void

void checkOurNameIdPoint(PLAYER *player, int *num_player, int *myID){
    for (int i=1; i<=*num_player; i++) {
        if(strcmp(player[i].name,GROUPNAME)==0){
            *myID = i;
            printf("myID is %d\n", *myID);
        }
    }
    return;
}

void searchNum_amazonOnBoardByID(Amazon *myAmazons, PLAYER *player, int board[][WIDTH], int myID, int *num_amazon){
    *num_amazon =0;
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            int value = board[y][x];
            if (value % 10==player[myID].ID) {
                (*num_amazon)++;
                printf("row:%d ",y);
                printf("column:%d\n",x);
                myAmazons[*num_amazon].AmazonID = *num_amazon;
                myAmazons[*num_amazon].column = x;
                myAmazons[*num_amazon].row = y;
            }
        }
    }
    return;
}


int selectAmazonAndMove(Amazon *myAmazons, PLAYER player[], int board[][WIDTH], int num_amazon, int myID, int num_player){
    for (int i =1; i<=num_amazon; i++) {
        int col1 = myAmazons[i].column;
        int row1 = myAmazons[i].row ;
        int check = AreThereObstaclesArroundAmazon(myAmazons[i].row, myAmazons[i].column, board);
        if(check==1){
            continue;
        }
        int maxvaluerow;
        int maxvaluecolumn;
        botAlgorithm(col1, row1, &maxvaluerow, &maxvaluecolumn, board);
        board[row1][col1] = 0;
        board[maxvaluerow][maxvaluecolumn] += myID;
        int value = board[maxvaluerow][maxvaluecolumn];
        int treasure = (value /100);
        player[myID].point += treasure;
        board[maxvaluerow][maxvaluecolumn] -= treasure*100;
        int artifact = value/10%10;
        board[maxvaluerow][maxvaluecolumn] -= artifact*10;
        //displayBoard(HEIGHT, WIDTH, board, num_player, player);
        switch (artifact) {
            case 0:
                arrow(maxvaluerow, maxvaluecolumn, board);
                break;
            case 1:
                printf("You got a horse!\n");
                arrow(maxvaluerow, maxvaluecolumn, board);
                int check = AreThereObstaclesArroundAmazon(row1,col1,board);
                if(check ==1){
                    printf("This amazon cannot move anymore.\n");
                    break;
                }
                horse(player, maxvaluerow, maxvaluecolumn, board, myID);
                break;
                
            case 2:
                printf("You got a borken arrow.\n");
                break;
            case 3:
                printf("You got a spear!\n");
                spear(maxvaluerow, maxvaluecolumn, board);
                break;
        }
        break;
    }
    return 0;
}

#endif
