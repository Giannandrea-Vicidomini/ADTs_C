/*
    Specifica ADT BSTree
    Specifica Sintattica:
        Tipo di riferimento: Tree
        Tipi utilizzati: int,item,boolean

    Specifica Semantica:
        il Tree è l'insieme t={a1,a2,...,an} dove ogni elementi è di tipo item
*/
typedef struct tree* Tree;

//Specifica Operatori

//Sintattica: newTree()->Tree
//Semantica: newTree()->t
Tree newTree(void);
//post: t={empty set}

//Sintattica: insertTree(Tree,item)->boolean
//Semantica: insertTree(t,it)->t'
int insertTree(const Tree t,const item i);
//pre: it non appartiene a t
//post: t={a1,a2,...,an} AND t'={a1,a2,...,an} U {it}

//Sintattica: deleteTree(Tree,item)->boolean
//Semantica: deleteTree(t,it)->t'
int deleteTree(const Tree t,const item i);
//pre: it appartiene a t
//post: t={a1,a2,...,an} AND t'=t \ {it}

//Sintattica emptyTree(Tree)->boolean
//Semantica emptyTree(t)->b
int emptyTree(const Tree t);
//post: b=true se t è vuoto OR b=false se t non è vuoto

//Sintattica: sizeTree(Tree)->int
//Semantica: sizeTree(t)->n
int sizeTree(const Tree t);
//post: n= |t|

//Sintattica searchTree(Tree,item)->b
//Semantica searchTree(t,it)->b
int searchTree(const Tree t,const item i);
//post: b=true se it appartiene a t altrimenti b=false

int showTree(const Tree t);
int destroyTree(Tree* const tptr);

void tvec(Tree t);