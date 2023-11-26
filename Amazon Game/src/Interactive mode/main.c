#include "gameplay.h"

int main(void) {
    int board[HEIGHT][WIDTH];// make a board array
    int num_player;// initialize the number of player
    PLAYER player[10];// make a structure of array of player
    InitializeBoard(board);//display a board at first
    TakePlayerName(&num_player, player);
    InitializeScore(&num_player, player);
    PlaceAmazon(&num_player, board, player);
    DisplayBoard(num_player, board, player);// before the game start, display the board for the players
    int array[num_player];
    for(int i = 1; i <= num_player ;i++) { //Number the players
        array[i-1] = i;
    }
    while (1) {
        if (NoAmazonCanMove(num_player, array)) {
            printf("Finishing the game and count the score.\n");
            int max = 0;
            // char name[15];
            for(int i = 1; i <= num_player; i++){
                if(max < player[i].point){       //player[i].point;// winner's point                                                  
                    max = i;                    //name[15] = player[i].name;// winner's name
                }
            }
            printf("%s won this game and point is %d\n", player[max].name, player[max].point);
            break;
        }
        for(int i=1; i<= num_player; i++) {
            if(CountPlayerMovableAmazon(i, board, array)){
                continue;// when a player's all of amazons cannot move
            }

            while(1){
                // ask players which amazons they want to move
                printf("(Player%d) Pick an amazon to move\n", i);
                printf("row : ");
                int row1 = CordInput();
                printf("column : ");
                int col1 = CordInput();
                int value = board[row1][col1];
                if (AmazonChooser(value,i)) continue;
                
                
                if(IsAmazonStuck(row1,col1,board)){
                    printf("you cannot move this amazon anymore.\n");
                    continue;
                }
                while(1){
                    
                    if(movement(i, row1, col1, board, player, num_player))
                        continue;// when the player chose wrong place to move to
                    
                    if(0 == movement(i, row1, col1, board, player, num_player)){
                        printf("(%s's turn) end.\n", player[i].name);
                        break;
                    }
                    break;
                }
                break;
                
            }
        }
    }
    return 0;
}
