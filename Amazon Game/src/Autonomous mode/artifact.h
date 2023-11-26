#ifndef ARTIFACT_H
#define ARTIFACT_H

void arrow(int row1, int col1, int board[][10]){
    int check1 = AreThereObstaclesArroundAmazon(row1, col1, board);
    if(check1 == 1){
        printf("You cannot shoot an arrow anymore.\n");
        return;
    }
    int minvalue = 10;
    int value = 0;
    int minvaluerow = 10;
    int minvaluecolumn= 10;
    for(int row2 = 0; row2 < HEIGHT; row2++){
        for(int col2 = 0; col2 < WIDTH; col2++){
            int check = AreThereObstaclesBetween2Place(row1, row2, col1, col2, board);
            if(check == 1){
                continue;
            }
            if(check == 2){
                continue;
            }
            value = board[row2][col2]/100;
            if(minvalue > value){
                minvalue = value;
                minvaluerow = row2;
                minvaluecolumn = col2;
            }
        }
    }
    board[minvaluerow][minvaluecolumn] = 9;
    printf("Shoot an arrow to row:%d column:%d \n", minvaluerow, minvaluecolumn);
    return;
}

void spear(int row1, int col1, int board[][10]){
    int check1 = AreThereObstaclesArroundAmazon(row1, col1, board);
    if(check1 == 1){
        printf("Sorry, you cannot throw a spear anymore.\n");
        return;
    }
    int minvalue = 10;
    int value = 0;
    int minvaluerow = 10;
    int minvaluecolumn= 10;
    for(int row2 = 0; row2 < HEIGHT; row2++){
        for(int col2 = 0; col2 < WIDTH; col2++){
            int check = AreThereObstaclesBetween2Place(row1, row2, col1, col2, board);
            if(check == 1){
                continue;
            }
            if(check == 2){
                continue;
            }
            value = board[row2][col2]/100;
            if(minvalue > value){
                minvalue = value;
                minvaluerow = row2;
                minvaluecolumn = col2;
            }
        }
    }
    board[minvaluerow][minvaluecolumn] = 9;
    printf("throw a spear to row:%d column:%d\n", minvaluerow, minvaluecolumn);
    return;
}

void horse(PLAYER player[], int row1, int col1, int board[][WIDTH], int myID){
    int check = AreThereObstaclesArroundAmazon(row1, col1, board);
    if(check==1){
        return;
    }
    int maxvalue = 0;
    int value = 0;
    int maxvaluerow =0;
    int maxvaluecolumn=0;
    for(int row2 = 0; row2 < HEIGHT; row2++){
        for(int col2 = 0; col2 < WIDTH; col2++){
            int check = AreThereObstaclesBetween2Place(row1, row2, col1, col2, board);
            if(check == 1){
                continue;
            }
            if(check == 2){
                continue;
            }
            value = board[row2][col2]/100;
            if(maxvalue < value){
                maxvalue = value;
                maxvaluerow = row2;
                maxvaluecolumn = col2;
            }
        }
    }
    printf("maxvalue:%d maxvaluerow:%d maxvaluecolumn:%d\n", maxvalue, maxvaluerow, maxvaluecolumn);
    board[row1][col1] = 0;
    board[maxvaluerow][maxvaluecolumn] += myID;
    int value2 = board[maxvaluerow][maxvaluecolumn];
    int treasure = (value2 /100);
    player[myID].point += treasure;
    board[maxvaluerow][maxvaluecolumn] -= treasure*100;
    int artifact = value2/10%10;
    board[maxvaluerow][maxvaluecolumn] -= artifact*10;
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
    return;
}

#endif
