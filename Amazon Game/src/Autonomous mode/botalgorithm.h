#ifndef botalgorithm_h
#define botalgorithm_h
/*
   Added the Algorithm and changed it from srand() to an algorithm that seek the best location.

*/
void botAlgorithm(int col1, int row1, int *maxvaluerow, int *maxvaluecolumn, int board[][WIDTH]){
    int maxvalue=0;
    int value;

    /* 
       *OUTDATED*
       still get stuck after board 60 and above 
       need fixing ASAP
    */

   // fixed
    for(int row2 = 0; row2 < HEIGHT; row2++){
        for(int col2 = 0; col2 < WIDTH; col2++){
            int check = AreThereObstaclesBetween2Place(row1, row2, col1, col2, board);
            value = board[row2][col2]/100;
            if(check == 1){
                continue;
            }  
            else if(check == 2){
                continue;
            }
            else if(maxvalue <= value){
                maxvalue = value;
                *maxvaluerow = row2;
                *maxvaluecolumn = col2;
            }
        }
    }
    printf("maxvalue:%d maxvaluerow:%d maxvaluecolumn:%d\n", maxvalue, *maxvaluerow, *maxvaluecolumn);
}
#endif
