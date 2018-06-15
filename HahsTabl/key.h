/*
    ADT Key
    Specifica Sintattica:
        Tipo di riferimento: Key
        Tipi utilizzati: item,integer
    
    Specifica Semantica:
        la Key è il campo dell' item k per cui verra effettuata la mappatura
*/
typedef char* Key;

//Specifica Operatori

//Sintattica: getKey(item)->key
//Semantica: getKey(It)->code
Key getKey(const item i);
//post: it=(code,dest,lenght,price,seats)

//Sintattica: hash(Key,integer)->integer
//Semantica: hash(k,n)->hs
int hash(Key k,const int size);
//post: hs=h(k) 

//Sintattica: compKey(Key,Key)->boolean
//Semantica: comp(k1,k2)->b
int compKey(Key a,Key b);
//post: b=1 IF k1=k2 ELSE b=0 

//Sintattica: cloneKey(Key)->Key
//Semantica: cloneKey(k1)->k2
Key cloneKey(const Key k);
//post: k2=k1

int outputKey(Key k);

int destroyKey(Key k);