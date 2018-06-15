typedef struct _ranking* Ranking;

Ranking newRanking(const char* name);
int insertTeam(const Ranking r,const item team);
int teamInfo(const Ranking r,const char* name);
int game(const Ranking r,const char* team1,const char* team2,const int goals1,const int goals2);
int showRanking(const Ranking r);
int showRankingPoints(const Ranking r);
int destroyRanking(Ranking* const rptr);