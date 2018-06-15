/*
    ADT: Hash Table
    Specifica Sintattica:
        Tipo di riferimento: HashMap
        Tipi utilizzati: int,item,boolean,Key

    Specifica Semantica:
        HashMap è l'insieme h={a1,a2,a3,...,an} dove ogni elemento è di tipo item
        item contiene un un campo chiave di tipo Key e dei dati associati
*/
typedef struct h_table* HashMap;

//Specifica Operatori

//Sintattica: newHashMap(int)->HashMap
//Semantica: newHashMap()->h
HashMap newHashMap(const size_t size);
//post: h={empty set}

//Sintattica: insertTable(HashMap,item,key)->boolean
//Semantica: insertTable(h,it,k)->h'
int insertTable(const HashMap h, const item i,char* const k);
//post: h={a1,a2,a3,...,an} AND h'= h U {it} con k che è la chiave di it

//Sintattica: searchTable(HashMap,Key)->item
//Semantica: searchTable(h,k)->it
item searchTable(const HashMap h,char* const k);
//pre: h={a1,a2,...,an} AND n>0
//post: it=ai con 1<= i <= n se k è la chiave di ai

//Sintattica: deleteTable(HashMap,Key)->boolean
//Semantica: deleteTable(h,k)->h'
int deleteTable(const HashMap h,char* const k);
//pre: h={a1,a2,...,an} AND n>0 AND k è la chiave di un elemento ai con 1<= i <=n
//post: h'={a1,a2,...,an} \ {ai}

int destroyTable(HashMap* const h);
int showTable(const HashMap h);