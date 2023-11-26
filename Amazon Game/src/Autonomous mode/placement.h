#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "outputboard.h"
#include "displayboard.h"

extern int HEIGHT;
extern int WIDTH;
extern char GROUPNAME[16];
extern int myID;

int addOneAmazonOnBoard(PLAYER *player, int num_player, int board[][WIDTH]);
int searchNum_amazonOnBoard(PLAYER *player, int board[][WIDTH], int myID, int num_amazon);
int addOrCheckOurNameIdPoint(PLAYER *player, int *num_player, int *myID);

int placement(char argc, char* argv[], PLAYER *player){
    int num_amazon = 0;
    char string[6] = {0};
    sscanf(argv[2], "%[^0-9]%d", string, &num_amazon);
    printf("The number of amazon is %d\n", num_amazon);
    FILE *file=NULL;
    char *inputpath = argv[3];
    file = fopen(inputpath,"r+");
    fscanf(file, "%d %d", &HEIGHT, &WIDTH);
    printf("HEIGHT is %d\n", HEIGHT);
    printf("WIDTH is %d\n", WIDTH);
    int board[HEIGHT][WIDTH];
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            fscanf(file, "%d ", &board[y][x]);
        }
    }
    int num_player=0;
    while (fscanf(file, "%s %d %d", player[num_player+1].name, &player[num_player+1].ID, &player[num_player+1].point) != EOF)
    {
        num_player++;
        printf("%s %d %d\n", player[num_player].name, player[num_player].ID, player[num_player].point);
        
    }
    printf("num_player is %d\n", num_player);
    fclose(file);
    addOrCheckOurNameIdPoint(player, &num_player, &myID);
    //check whether the number of amazon which already placed on board satisfy the required number of amazon
    if(searchNum_amazonOnBoard(player, board, myID, num_amazon)==1){
        return 1;
    }
    addOneAmazonOnBoard(player, num_player, board);
    char *outputpath = argv[4];
    outputBoard(HEIGHT, WIDTH, board, num_player, player, outputpath);
    displayBoard(HEIGHT, WIDTH, board, num_player, player);
    return 0;
}

int getRandom(int min,int max)
{
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

int addOneAmazonOnBoard(PLAYER *player, int num_player, int board[][WIDTH]){
    while (1) {
        int y = getRandom(0, HEIGHT);
        int x = getRandom(0, WIDTH);
        if (board[y][x]%10>0) {
            continue;
        }
        board[y][x]=player[num_player].ID;
        break;
    }
    return 0;
}

int searchNum_amazonOnBoard(PLAYER *player, int board[][WIDTH], int myID, int num_amazon){
    int amazon_counter = 0;
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            int value = board[y][x];
            if (value % 10==player[myID].ID) {
                printf("column:%d\n",x);
                printf("row:%d\n",y);
                //shouldn't enter space after \n
                amazon_counter +=1;
            }
        }
    }
    if(amazon_counter==num_amazon){
        return 1;
    }
    return 0;
}

int addOrCheckOurNameIdPoint(PLAYER *player, int *num_player, int *myID){
    if(*num_player==0){
        strcpy(player[1].name, GROUPNAME);
        player[1].ID = 1;
        player[1].point = 0;
        *num_player =1;
        *myID = 1;
        printf("myID is %d\n", *myID);
        return 0;
    }
    else{
        for (int i=1; i<=*num_player; i++) {
            if(strcmp(player[i].name,GROUPNAME)==0){
                *myID = i;
                printf("myID is %d\n", *myID);
                return 0;
            }
            else{
                continue;
            }
        }
        strcpy(player[*num_player+1].name, GROUPNAME);
        player[*num_player+1].ID = *num_player+1;
        player[*num_player+1].point = 0;
        *num_player+=1;
        *myID = *num_player;
    }
    return 0;
    
}

#endif
