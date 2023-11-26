int CordInput()
{
    int val,coun=0;
    scanf(" %d", &val);
    while(val < 0 || 9 < val)
	{   
        printf("Please enter a number between 0 and 9: ");
        scanf(" %d", &val);
		coun++;
        if (coun > 100)
        {
            printf("\n\n ERROR INVALID INPUT");
            printf("\n\n Please restart the program");
            break;
        }
                        
	}
    return val;
}

void TakePlayerName(int *num_player, PLAYER *player){
    printf("===(Interactive mode)=== \n");
    printf("Enter number of players: ");
    while(scanf("%d", num_player)!=1){
        printf("Wrong input! \n");
        printf("Please try again\n");
        scanf("%*s");
    }
    int i;
    for(i = 1; i <= *num_player; i++) {
        printf("Enter player %d name: ", i);
        scanf("%s", player[i].name);
        player[i].ID = i;
        player[i].point = 0;
    }
    
}

