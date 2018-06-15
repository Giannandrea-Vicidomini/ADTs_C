/*
ADT LISTA TIPI:

    specifica sintattica:

        -tipo di riferimento: List
        -tipi utilizzati: boolean, int, item

    specifica semantica:

        -list è l insieme l=a1,a2,a3...,an di tipo item

ADT LISTA OPERATORI:
    
    specifica sintattica:

        -newList()->list
        -emptyList(list)->boolean
        -sizeList(list)->integer
        -getItem(list,integer)->item
        -insertList(list,integer,item)->list
        -removeList(list,integer)->list
        -posItem(list,item)->integer
        -reverseList(list)->list
        -cloneList(list)->list
        -deleteList(list)->list
        -destroyList(list)->list
        -inputList(integer)->list

    specifica semantica:
        -newList() -> l
            post: l=nil
        -emptyList(l)-> b
            post: if l=nil then b=true else b=false
        -sizeList(l)-> n
            post: l=<a1,a2,a3..,an> AND n>=0
        -getItem(l,pos)->e
            pre: pos>=0 AND pos<=sizeList(l)
            post: e è l'elemento che occupa la posizione pos in l
        -insertList(l,pos,e)->l'
            pre: pos>=0 AND pos<sizelist(l)
            post: l'= si ottiene inserendo l in posizione pos
        -removeList(l,pos)->l'
            pre: pos>=0 AND pos<sizeList(l)
            post: l' si ottiene togliendo da l l'elemenrto in posizione pos
        -posItem(l,e)->pos
            post:
                se e è in l allora p è la posizione della prima occorrenza di e
                altrimenti p=-1
        -reverseList(l)=l'
            post: l=<a1,a2...,an> AND l'=<an...a2,a1>
        -cloneList(l)->l'
            post: l=<a1,a2...,an> AND l'=<a1,a2...,an>
        -deleteList(l)->l
            pre: sizeList(l) > 0
            post: l=<a1,a2...,an> AND l'=nil
        -destroyList(list*)->b
            pre: list != nil
            post: se dealloca la lista ed il nodo contenitore con successo allora b=1 altrimenti b=0
        -inputList(n)-> l
            post: l=<a1,a2...,an>

*/

typedef struct _list* List;

List newList(void);
int emptyList(const List l);
int sizeList(const List l);
item getItem(const List l, const int pos);
int posItem(const List l,const item val);
int insertList(const List l,const int pos,const item val);
int removeList(const List l,const int pos);
int reverseList(const List l);
int deleteList(const List l);
List cloneList(const List l);
int outputList(const List l);
List inputList(const int n);
int destroyList(List* const list);



