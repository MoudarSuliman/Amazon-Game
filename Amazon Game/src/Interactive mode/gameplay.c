#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "random.h"
#include "board.h"
#include "inputs.h"
#define WIDTH 10
#define HEIGHT 10

int NoAmazonCanMove(int num_player, int array[]){
    for(int i=1; i<=num_player; i++){
        if(array[i-1]!=0){
            return 0;
        }
    }
    return 1;
}

int AmazonChooser(int value,int i){
    if (value%10 !=i){
        printf("You don't have a amazon on this cell.\n");
        printf("Select an other place.\n");
        return 1;
    }
    return 0;
}
void InitializeScore(int *num_player, PLAYER *player){
    int i;
    for(i = 1; i <= *num_player; i++) {
        printf("Player%d %s: %d \n",
        player[i].ID, player[i].name, player[i].point);
    }
}

int PlaceAmazon(int *num_player, int board[][WIDTH], PLAYER *player){
    printf("Input numbers of amazons: ");
    int num_amazons;
    scanf("%d", &num_amazons);
    int n;
    for(n = 1; n <= num_amazons; n++) {
        int p;
        for(p = 1; p <= *num_player; p++) {
            printf("%s, place the amazons: \n", player[p].name);
            while(1){
                printf("row : ");
                int row = CordInput();
                printf("column : ");
                int col = CordInput();
                //rows and columns start from 0
                int value = board[row][col];
                if (value%10 >0){
                    printf("This cell is occupied.\n");
                    printf("Select an other place.\n");
                    continue;
                }
                else if(value%10 ==0){
                    board[row][col] = p;
                    break;
                }
            }
            unsigned char x, y;
            for(y = 0; y < HEIGHT; y++){
                for(x = 0; x < WIDTH; x++){
                    printf("%03d ", board[y][x]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

int IsAmazonStuck(int row, int col, int board[][WIDTH]){
    enum WhereIsAmazon where;
    if (row==0 && col==0){
        where = upperleft;
    }
    else if (row==0 && col==9){
        where = upperright;
    }
    else if (row==9 && col==0){
        where = lowerleft;
    }
    else if (row==9 && col==9){
        where = lowerright;
    }
    else if (row>0 && row<9 && col==0){
        where = middleleft;
    }
    else if (row>0 && row<9 && col==9){
        where = middleright;
    }
    else if (row==0 && col>0 && col<9){
        where = uppermiddle;
    }
    else if (row==9 && col>0 && col<9){
        where = lowermiddle;
    }
    else if (row>0 && row<9 && col>0 && col<9){
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

int AreThereObstaclesBetween2Place(int row1, int row2, int col1, int col2, int board[][WIDTH]){
    if(row2>9 || col2>9){
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

int arrow(int row2, int col2, int board[][10]){
    while (1) {
        int check1 = IsAmazonStuck(row2, col2, board);
        if(check1 == 1){
            printf("You cannot shoot an arrow anymore.\n");
            break;
        }
        printf("You can shoot an arrow!\n");
        printf("Where do you want to shoot?\n");
        printf("row : ");
        int row3;
        scanf("%d", &row3);
        printf("column : ");
        int col3;
        scanf("%d", &col3);
        int check2 = AreThereObstaclesBetween2Place(row2, row3, col2, col3, board);
        if(check2 == 1){
            printf("You cannot shoot to this place.\n");
            continue;
        }
        if(check2 == 2){
            printf("You can shoot an arrow only horizontally, vertically or diagonally.\n");
            continue;
        }
        board[row3][col3] = 9;
        break;
    }
    return 0;
}

int spear(int row2, int col2, int board[][10]){
    while(1){
        int check1 = IsAmazonStuck(row2, col2, board);
        if(check1 == 1){
            printf("You cannot throw a spear anymore.\n");
            return 0;
        }
        printf("You can throw a spear!\n");
        printf("Where do you want to throw?\n");
        printf("row : ");
        int row3;
        scanf("%d", &row3);
        printf("column : ");
        int col3;
        scanf("%d", &col3);
        int value=board[row3][col3];
        if(value%10!=0){
            printf("You cannot throw spear there.\n");
            continue;
        }
        int check2 = AreThereObstaclesBetween2Place(row2, row3, col2, col3, board);
        if(check2 == 2){
            printf("You can throw spear only horizontally, vertically or diagonally.\n");
            continue;
        }
        board[row3][col3] = 9;
        break;
    }
    return 0;
}

int movement(int i,int row1,int col1,int board[][10],PLAYER *player,int num_player){
    printf("Where do you want to place it?\n");
    printf("row : ");
    int row2;
    scanf("%d", &row2);
    printf("column : ");
    int col2;
    scanf("%d", &col2);
    //check there is any obstacles
    int check = AreThereObstaclesBetween2Place(row1, row2, col1, col2, board);
    if(check == 1){
        printf("You cannot move an amazon to this place because of an obstacle\n");
        return 1;
    }
    if(check == 2){
        printf("Your amazon can move only horizontally, vertically or diagonally.\n");
        return 1;
    }
    board[row1][col1] -= i;
    board[row2][col2] += i;
    int value2 = board[row2][col2];
    int treasure = (value2 /100);
    player[i].point += treasure;
    board[row2][col2] -= treasure*100;
    int artifact = value2/10%10;
    board[row2][col2] -= artifact*10;
    DisplayBoard(num_player, board, player);
    switch (artifact) {
        case 0:
            arrow(row2, col2, board);
            break;
        case 1:
            printf("You got a horse!\n");
            arrow(row2, col2, board);
            while(1){
                int check = IsAmazonStuck(row1,col1,board);
                if(check ==1){
                    printf("This amazon cannot move anymore.\n");
                    break;
                }
                int move = movement(i, row2, col2, board, player, num_player);
                if(move ==1){
                    continue;
                }
                if(move ==0){
                    break;
                }
            }
            break;
            
        case 2:
            printf("You got a broken arrow.\n");
            break;
        case 3:
            printf("You got a spear!\n");
            spear(row2, col2, board);
            break;
    }
    DisplayBoard(num_player, board, player);
    return 0;
}

int CountPlayerMovableAmazon(int i, int board[][10], int array[]){
    printf("(Player%d)You have amazons on the following place.\n", i);
    unsigned char x, y;
    int amazon_counter = 0;
    for(y = 0; y < HEIGHT; y++){
        for(x = 0; x < WIDTH; x++){
            int value = board[x][y];
            if (value % 10==i) {
                printf("row:%d ",x);
                printf("column:%d\n",y);
                int check = IsAmazonStuck(x,y,board);
                if(check==0){
                    amazon_counter += 1;
                }
                
            }
        }
    }
    if(amazon_counter==0)
    {
        array[i-1]=0;
        return 1;
    }
    if(amazon_counter!=0)
    {
        array[i-1]=i;
    }
    return 0;
}

