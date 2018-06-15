typedef struct _team* item; 

#define NULLITEM NULL

item newItem(const char* name,const int games,const int points,const int goals_scored,const int goals_received);
int comp_item(item a,item b);
//void input_item(item* i);
void output_item(item i);
void outputItem(item i);
item cloneItem(item i);
void destroyItem(item* i);
char* getTeamName(item a);
int getTeamPoints(item a);
int updateGames(item a);
int updatePoints(item a,int p);
int updateGoalsScored(item a,int gls);
int updateGoalsReceived(item a,int gls);