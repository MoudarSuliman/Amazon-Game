#include "gameplay.c"
#define WIDTH 10

//If no amazon can move the function returns 1
int NoAmazonCanMove(int num_player, int array[]);
/*

    num_player - number of players in the game
    array[] - array that holds number of players

*/

//Check whether chosen amazon is in the coord
int AmazonChooser(int value,int i);
/*

    value - is a place on a board
    i - player id

*/

//Function that initializes score
void InitializeScore(int *num_player, PLAYER *player);
/*

    num_player - number of players in the game
    player - players in the game (structure for their name, id and points)

*/

//Ask the number of players and amazons, then place them at first
int PlaceAmazon(int *num_player, int board[][WIDTH], PLAYER *player);
/*

    num_player - number of players in the game
    player - players in the game (structure for their name, id and points)
    board - its a matrix that contains the playing field       

*/

//This function is to check whether the amazon is completely surrounded by obstacles.
int IsAmazonStuck(int row, int col, int board[][WIDTH]);
/*

    row - number of a row where is an amazon
    col - number of a column where is an amazon
    board - its a matrix that contains the playing field 

*/

// This function is to check whether there is any obstacles between 2 places, for example, an amazon and an arrow.
int AreThereObstaclesBetween2Place(int row1, int row2, int col1, int col2, int board[][WIDTH]);
/*
    row1 - row for the first place
    row2 - row for the second place
    col1 - column for the first place
    col2 - column for the second place
    board - its a matrix that contains the playing field
*/

// This function is for an arrow and for spear.
int arrow(int row2, int col2, int board[][10]);
int spear(int row2, int col2, int board[][10]);
/*

    row2 - row where amazon is standing on the board
    col2 - column where amazon is standing on the board
    board - its a matrix that contains the playing field

*/

// This function is used when amazon move somewhere.
int movement(int i,int row1,int col1,int board[][10],PLAYER *player,int num_player);
/*

    i - player id
    row1 - row where amazon is standing on the board
    col1 - column where amazon is standing on the board
    board - its a matrix that contains the playing field
    player - players in the game (structure for their name, id and points)
    num_player - number of players in the game

*/

// count the number of amazon which survives
int CountPlayerMovableAmazon(int i, int board[][10], int array[]);
/*

    i - player id
    board - its a matrix that contains the playing field
    array[] - array that holds number of players

*/
