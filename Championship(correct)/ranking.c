#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "ranking.h"

typedef struct structure* node; 

struct _ranking
{
    char name[25];
    node root;
    size_t size;
};

struct structure
{
    item val;
    struct structure* left;
    struct structure* right;
};
//----------------------------STRUCTURE FUNCTIONS---------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

static node makeNode(const item i,node l,node r)
{
    node new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->val=cloneItem(i);
        //new->val=i;
        new->left=l;
        new->right=r;
    }
    return new;
}

static node insert(node t,const item i,int* done)
{
    if(t==NULL)
    {
        *done=1;
        return makeNode(i,NULL,NULL);
    }
    else if(comp_item(i,t->val)==0)
    {
        return t;
    }
    else if(comp_item(i,t->val)==1)
    {
        t->right=insert(t->right,i,done);
        return t;
    }
    else
    {
        t->left=insert(t->left,i,done);
        return t;
    }
}

static item t_search(const node t,const char* name)
{
    char* temp;
    if(t!=NULL)
    {
        temp=getTeamName(t->val);
    }
    if(t==NULL)
    {
        return 0;
    }
    else if(strcmp(name,temp)==0)
    {
        free(temp);
        return t->val;
    }
    else if(strcmp(name,temp)>0)
    {
        free(temp);
        return t_search(t->right,name);
    }
    else
    {
        return t_search(t->left,name);
    }
}

static void print(const node t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        print(t->left);
        output_item(t->val);
        print(t->right);
    }
}

static void freeTree(node t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        freeTree(t->left);
        freeTree(t->right);
        destroyItem(&t->val);
        free(t);
    }
}

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
Ranking newRanking(const char* name)
{
    Ranking new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        strcpy(new->name,name);
        new->size=0;
        new->root=NULL;
    }
    return new;
}

int insertTeam(const Ranking r,const item i)
{
    if(r==NULL)
    {
        return -1;
    }
    int res=0;
    r->root=insert(r->root,i,&res);
    if(res==1)
    {
        r->size++;
    }
    return res;
}

int teamInfo(const Ranking r,const char* name)
{
    if(r==NULL)
    {
        return -1;
    }
    item temp=t_search(r->root,name);
    if(temp==NULL) return 0; 

    outputItem(temp);
    return 1;
}

int game(const Ranking r,const char* team1,const char* team2,const int goals1,const int goals2)
{
    if(r==NULL)
    {
        return -1;
    }
    item team_1,team_2;
    team_1=t_search(r->root,team1);
    team_2=t_search(r->root,team2);
    if(team_1==NULL || team_2==NULL)
    {
        return 0;
    }

    if(goals1 > goals2)
    {
        updateGames(team_1);
        updateGames(team_2);
        updateGoalsReceived(team_1,goals2);
        updateGoalsReceived(team_2,goals1);
        updateGoalsScored(team_1,goals1);
        updateGoalsScored(team_2,goals2);

        updatePoints(team_1,3);
    }
    else if(goals1 < goals2)
    {
        updateGames(team_1);
        updateGames(team_2);
        updateGoalsReceived(team_1,goals2);
        updateGoalsReceived(team_2,goals1);
        updateGoalsScored(team_1,goals1);
        updateGoalsScored(team_2,goals2);

        updatePoints(team_2,3);
    }
    else
    {
        updateGames(team_1);
        updateGames(team_2);
        updateGoalsReceived(team_1,goals2);
        updateGoalsReceived(team_2,goals1);
        updateGoalsScored(team_1,goals1);
        updateGoalsScored(team_2,goals2);

        updatePoints(team_2,1);
        updatePoints(team_1,1);
    }
    return 1;
}

int showRanking(const Ranking r)
{
    if(r==NULL)
    {
        return -1;
    }
    print(r->root);
    return 1;
}

static int cmpPoints(const void* a,const void* b);
static int treeToVec(node t,item* vec,size_t size);
static void printVec(const item* vec,const size_t size);

int showRankingPoints(const Ranking r)
{
    if(r==NULL)
    {
        return -1;
    }
    item vec[r->size];
    treeToVec(r->root,vec,0);
    qsort(vec,r->size,sizeof(item),cmpPoints);
    printVec(vec,r->size);
    return 1;
}

static void printVec(const item* vec,const size_t size)
{
    if(size==0)
    {
        return;
    }
    else if(size==1)
    {
        output_item(vec[size-1]);
    }
    else
    {
        printVec(vec,size-1);
        output_item(vec[size-1]);
    }
}

static int treeToVec(node t,item* vec,size_t size)
{
    if(t==NULL)
    {
        return size;
    }
    vec[size]=t->val;
    size++;
    if(t->left!=NULL) size=treeToVec(t->left,vec,size);

    if(t->right!=NULL) size=treeToVec(t->right,vec,size);

    return size;
}

static int cmpPoints(const void* a,const void* b)
{
    item* n=(item*)a,* m=(item*)b;
    int  n1=getTeamPoints(*n),n2=getTeamPoints(*m);
    
    if(n1>n2) return -1;
    else if(n1<n2) return 1;
    else return 0;
}

int destroyRanking(Ranking* const rptr)
{
    if(*rptr==NULL)
    {
        return -1;
    }
    freeTree((*rptr)->root);
    free(*rptr);
    *rptr=NULL;
    return 1;
}