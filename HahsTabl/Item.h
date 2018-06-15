/*
    SPECIFICA ITEM
    sintattica:
        -tipo di riferimento: item
        -tipi utilizzati: string, integer, boolean

    semantica:
        item è la quintupla it=(code,dest,lenght,price,seats) dove:
            -code è la stringa rappresentante il codice di riconoscimento del viaggio
            -dest è la stringa rappresentante la destinazione del viaggio
            -lenght è la stringa rappresentante la durata del viaggio
            -price è un intero rappresentante il costo del viaggio
            -seats é un intero rappresentate il numero di posti liberi
*/

typedef struct travel* item; 


#define NULLITEM NULL;

//SPECIFICA OPERATORI

//sintattica: newItem(string,string,string,integer,integer)->item
//sintattica: newItem(code,dest,length,price,seats)->it
item newItem(const char* code,const char* destination,const char* duration,const int price,const int seats);
//post: it=(code,dest,length,price,seats)

//sintattica: inputItem()->item
//semantica: inputItem()->it
item inputItem(void);
//post: it=(code,dest,length,price,seats)

//sintattica: outputItem(item)->nil
//semantica: outputItem(it)->nil
void outputItem(item i);
//post: scrive a schermo le informazione dell item

//sintattica: prettyPrintItem(item)->nil
//semantica: prettyPrintItem(it)->nil
void prettyPrintItem(item i);
//post: scrive a schermo le informazione dell item in maniera apiu ordinata

//sintattica cloneItem(item)->item
//semantica:cloneItem(it1)->it2
item cloneItem(item i);
//pre: it != nil
//post: it2=it1

void destroyItem(item* i);

//sintattica: getCode(item)->string
//semantica: getCode(it)->code
char* getCode(item i);
//post: it=(code,dest,length,price,seats)

//sintattica: getCode(item,integer)->boolean
//semantica: getCode(it,n)->it'
int updateSeats(item i,const int amount);
//post: it=(code,dest,length,price,seats) AND it'=(code,dest,length,price,n)

//sintattica: getCode(item,integer)->boolean
//semantica: getCode(it,n)->it'
int updatePrice(item i,const int amount);
//post: it=(code,dest,length,price,seats) AND it'=(code,dest,length,n,seats)