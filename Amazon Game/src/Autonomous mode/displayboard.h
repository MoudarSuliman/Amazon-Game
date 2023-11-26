#ifndef DISPLAYBOARD_H
#define DISPLAYBOARD_H

void displayBoard(int HEIGHT, int WIDTH, int board[][WIDTH], int num_player, PLAYER player[]){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            printf("%03d ", board[y][x]);
        }
        printf("\n");
    }
    for(int i = 1; i <= num_player; i++) {
        printf("%s %d %d \n",
               player[i].name, player[i].ID, player[i].point);
    }
    return;
}

#endif
