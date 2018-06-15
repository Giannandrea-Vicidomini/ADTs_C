#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ranking.h"

Ranking fileToRanking(char* filename,char* r_name);

int main(void)
{
    Ranking championship;
    championship=fileToRanking("teams.txt","_Serie A_");
    showRanking(championship);

    game(championship,"Juventus","Milan",3,2);
    game(championship,"Juventus","Inter",3,3);
    game(championship,"Juventus","Napoli",0,2);
    game(championship,"Lazio","Roma",5,2);
    game(championship,"Napoli","Sampdoria",2,2);

    teamInfo(championship,"Inter");
    
    teamInfo(championship,"Milan");
    
    teamInfo(championship,"Napoli");
    
    teamInfo(championship,"Juventus");
    
    teamInfo(championship,"Lazio");
    
    teamInfo(championship,"Roma");
    
    teamInfo(championship,"Cagliari");
    
    teamInfo(championship,"Sampdoria");
    

    showRankingPoints(championship);
    destroyRanking(&championship);
    return 0;
}

Ranking fileToRanking(char* filename,char* r_name)
{
    FILE* file=fopen(filename,"r");
    if(file==NULL)
    {
        return NULL;
    }
    Ranking new_ranking=newRanking(r_name);
    char name[25];
    int games,points,goalsc,goalrc;
    while((fscanf(file,"%s %i %i %i %i",name,&games,&points,&goalsc,&goalrc))!=EOF)
    {
        item new_item=newItem(name,games,points,goalsc,goalrc);
        insertTeam(new_ranking,new_item);
    }
    return new_ranking;
}