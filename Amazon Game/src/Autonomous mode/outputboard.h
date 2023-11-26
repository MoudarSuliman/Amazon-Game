#ifndef OUTPUTBOARD_H
#define OUTPUTBOARD_H

void outputBoard(int HEIGHT, int WIDTH, int board[][WIDTH], int num_player, PLAYER player[], char *outputpath){
    FILE *outputfile;
    outputfile = fopen(outputpath,"w");
    fprintf(outputfile,"%d %d\n", HEIGHT, WIDTH);
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            fprintf(outputfile,"%03d ", board[y][x]);
        }
        fprintf(outputfile,"\n");
    }
    for(int i = 1; i <= num_player; i++) {
        fprintf(outputfile, "%s %d %d \n",
                player[i].name, player[i].ID, player[i].point);
    }
    fclose(outputfile);
    return;
}

#endif
