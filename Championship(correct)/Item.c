#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

struct _team
{
    char name[25];
    int games;
    int points;
    int goals_scored;
    int goals_received;
};

item newItem(const char* name,const int games,const int points,const int goals_scored,const int goals_received)
{
    item new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        strcpy(new->name,name);
        new->games=games;
        new->points=points;
        new->goals_scored=goals_scored;
        new->goals_received=goals_received;
    }
    return new;
}

int comp_item(item a,item b)
{
    int res=strcmp(a->name,b->name);
    if(res>0) return 1;
    else if(res<0) return -1;
    else return 0;
}
/*
void input_item(item* i)
{
    scanf("%i",i);
}
*/
void output_item(item i)
{
    printf("(\x1B[32mname\x1B[0m:%s,\x1B[32mgames\x1B[0m:%i,\x1B[32mpoints\x1B[0m:%i,\x1B[32mgscor\x1B[0m:%i,\x1B[32mgrec\x1B[0m:%i)\n",i->name,i->games,i->points,i->goals_scored,i->goals_received);
}

void outputItem(item i)
{
    printf("Team name: %s\n",i->name);
    printf("Team games: %i\n",i->games);
    printf("Team points: %i\n",i->points);
    printf("Team goals scored: %i\n",i->goals_scored);
    printf("Team goals received: %i\n",i->goals_received);
    puts("");
}

item cloneItem(item i)
{
    item clone=malloc(sizeof(*clone));
    *clone=*i;
    return clone;
}

void destroyItem(item* i)
{
    free(*i);
}

char* getTeamName(item a)
{
    char* name=NULL;
    if(a!=NULLITEM)
    {
        name=malloc((strlen(a->name)+1)*sizeof(char));
        strcpy(name,a->name);
    }
    return name;
}

int getTeamPoints(item a)
{
    return a->points;
}

int updateGames(item a)
{
    if(a==NULL)
    { 
        return -1;
    }
    a->games++;
    return 1;
}

int updatePoints(item a,int p)
{
    if(a==NULL)
    {
        return -1;
    }
    a->points+=p;
    return 1;
}

int updateGoalsScored(item a,int gls)
{
    if(a==NULL)
    {
        return -1;
    }
    a->goals_scored+=gls;
    return 1;
}

int updateGoalsReceived(item a,int gls)
{
    if(a==NULL)
    {
        return -1;
    }
    a->goals_received+=gls;
    return 1;
}