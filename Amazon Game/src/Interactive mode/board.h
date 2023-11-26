#include "board.c"
#define WIDTH 10

//Function that initializes a board
int InitializeBoard(int board[][10]);
/*

    board - its a matrix that contains the playing field

*/

//This function is for displaying the board
int DisplayBoard(int num_player, int board[][WIDTH], PLAYER player[]);
/*

    num_player - number of players in the game
    board - its a matrix that contains the playing field
    player - array structure for players in the game 

*/