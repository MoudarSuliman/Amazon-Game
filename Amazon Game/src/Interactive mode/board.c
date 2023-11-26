#define WIDTH 10
#define HEIGHT 10

int InitializeBoard(int board[][10]){
    unsigned char x, y;
    int empty = 0;
    for(y = 0; y < HEIGHT; y++){
        for(x = 0; x < WIDTH; x++){
            board[y][x] = empty+GetRandom(0,5)*100+GetRandom(0,3)*10;
        }
    }
    printf("Let The Games Begin!!!\n");
    return 0;
}

int DisplayBoard(int num_player, int board[][WIDTH], PLAYER player[]){
    printf("\n");
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            printf("%03d ", board[y][x]);
        }
        printf("\n");
    }
    for(int i = 1; i <= num_player; i++) {
        printf("Player%d %s: %d \n",
            player[i].ID, player[i].name, player[i].point);
    }
    return 0;
}