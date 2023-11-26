#ifndef CHECKOBSTACLE_H
#define CHECKOBSTACLE_H

enum whereIsAmazon{
    upperleft,
    upperright,
    lowerleft,
    lowerright,
    uppermiddle,
    lowermiddle,
    middleright,
    middleleft,
    middle,
};
/*

    *OUTDATED* Obs Check from the interactive need to be merged with the auto code


*/ 

/*
    int HEIGHT;
    int WIDTH;
*/

// done sccusefully 
int AreThereObstaclesArroundAmazon(int row, int col, int board[][WIDTH]){
    enum whereIsAmazon where;
    if (row==0 && col==0){
        where = upperleft;
    }
    else if (row==0 && col==15){
        where = upperright;
    }
    else if (row==15 && col==0){
        where = lowerleft;
    }
    else if (row==15 && col==15){
        where = lowerright;
    }
    else if (row>0 && row<15 && col==0){
        where = middleleft;
    }
    else if (row>0 && row<15 && col==15){
        where = middleright;
    }
    else if (row==0 && col>0 && col<15){
        where = uppermiddle;
    }
    else if (row==15 && col>0 && col<15){
        where = lowermiddle;
    }
    else if (row>0 && row<15 && col>0 && col<15){
        where = middle;
    }
    else{
        return 0;
    }
    switch(where){
        case upperleft:
            if (board[0][1]%10>0 && board[1][0]%10>0 && board[1][1]%10>0 ) {
                printf("This amazon is on the upper left place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case upperright:
            if (board[0][8]%10>0 && board[1][9]%10>0 && board[1][8]%10>0 ) {
                printf("This amazon is on the upper right place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case lowerleft:
            if (board[8][0]%10>0 && board[9][1]%10>0 && board[8][1]%10>0 ) {
                printf("This amazon is on the lower left place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case lowerright:
            if (board[8][8]%10>0 && board[8][9]%10>0 && board[9][8]%10>0 ) {
                printf("This amazon is on the lower right place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case uppermiddle:
            if (board[row+1][col]%10>0 && board[row+1][col+1]%10>0 && board[row][col+1]%10>0
                && board[row][col-1]%10>0 && board[row+1][col-1]%10>0) {
                printf("This amazon is on the upper middle place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case lowermiddle:
            if (board[row][col+1]%10>0 && board[row-1][col+1]%10>0 && board[row-1][col]%10>0
                && board[row-1][col-1]%10>0 && board[row][col-1]%10>0 ) {
                printf("This amazon is on the lower middle place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case middleleft:
            if (board[row+1][col]%10>0 && board[row+1][col+1]%10>0 && board[row][col+1]%10>0
                && board[row-1][col+1]%10>0 && board[row-1][col]%10>0) {
                printf("This amazon is on the middle left place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case middleright:
            if (board[row+1][col]%10>0 && board[row+1][col-1]%10>0 && board[row][col-1]%10>0
                && board[row-1][col-1]%10>0 && board[row-1][col]%10>0) {
                printf("This amazon is on the middle right place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
        case middle:
            if (board[row+1][col]%10>0 && board[row+1][col-1]%10>0 && board[row][col-1]%10>0
                && board[row-1][col-1]%10>0 && board[row-1][col]%10>0 && board[row-1][col+1]%10>0
                && board[row][col+1]%10>0 && board[row+1][col+1]%10>0) {
                printf("This amazon is on the middle place and surrounded by obstacles.\n");
                return 1;
            }
            return 0;
    }
}

int canAmazonsMove(Amazon myAmazons[], int board[][WIDTH], int num_amazon){
    int counterOfAmazonsWhichCanMove = 0;
    for (int i=1; i<= num_amazon; i++) {
        int check = AreThereObstaclesArroundAmazon(myAmazons[i].row, myAmazons[i].column, board);
        if(check==0){
            counterOfAmazonsWhichCanMove += 1;
        }
    }
    if(counterOfAmazonsWhichCanMove==0){
        return 1;
    }
    return 0;
}

// *OUTDATED*  fails to detect after some time 
//fixed

int AreThereObstaclesBetween2Place(int row1, int row2, int col1, int col2, int board[HEIGHT][WIDTH]){
    if(row2> 30 || col2> 30){
        return 2;
    }
    if(row1==row2){
        int betweencol = col2 - col1;
        if(betweencol > 0){
            for(int c=col1+1; c<=col2; c++){
                int value = board[row1][c];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweencol < 0){
            for(int c=col1-1; c>=col2; c--){
                int value = board[row1][c];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweencol == 0){
            return 1;
        }
        return 0;
    }
    if(col1==col2){
        int betweenrow = row2 - row1;
        if(betweenrow > 0){
            for(int r=row1+1; r<=row2; r++){
                int value = board[r][col1];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweenrow < 0){
            for(int r=row1-1; r>=row2; r--){
                int value = board[r][col1];
                
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweenrow == 0){
            return 1;
        }
        return 0;
    }
    if(abs(col2-col1)==abs(row2-row1)){
        int betweenrow = row2 - row1;
        int betweencol = col2 - col1;
        if(betweenrow>0 && betweencol>0){
            for(int dai=1; dai<=betweenrow; dai++){
                int value = board[row1+dai][col1+dai];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweenrow<0 && betweencol>0){
            for(int dai=1; dai<=betweencol; dai++){
                int value = board[row1-dai][col1+dai];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweenrow>0 && betweencol<0){
            for(int dai=1; dai<=betweenrow; dai++){
                int value = board[row1+dai][col1-dai];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        if(betweenrow<0 && betweencol<0){
            for(int dai=1; dai<=abs(betweenrow); dai++){
                int value = board[row1-dai][col1-dai];
                if (value%10 >0){
                    return 1;
                }
            }
        }
        return 0;
    }
    return 2;
}

#endif
