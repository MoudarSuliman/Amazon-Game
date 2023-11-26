#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "placement.h"
#include "movement.h"
#define _CRT_SECURE_NO_WARNINGS
#define LIST_NUMBER ((sizeof myAmazons)/(sizeof(struct Amazon)))
int HEIGHT;
int WIDTH;
char GROUPNAME[16] = "Kratos_GroupC";
int myID;

int main(int argc, char* argv[]) {
    PLAYER player[10];
    if(strcmp(argv[1],"phase=placement")==0){
        if (placement(argc, argv, player) == 1) {
            return 1;
        }
        return 0;
    }
    else if(strcmp(argv[1],"phase=movement")==0){
        if (movement(argc, argv, player) == 1) {
            return 1;
        }
        return 0;
    }
    printf("There is something wrong with command line");
    return 0;
}
