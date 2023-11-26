//Structure for player which contains "name", "ID", "point"
typedef struct{
    char name[15]; //name of a player
    int ID; //id of a player
    int point; //points for a player
}PLAYER;

//Location of an amazon
enum WhereIsAmazon{
    upperleft,
    upperright,
    lowerleft,
    lowerright,
    uppermiddle,
    lowermiddle,
    middleright,
    middleleft,
    middle,
};