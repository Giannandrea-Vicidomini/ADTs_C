/*
    SPECIFICA ITEM
    sintattica:
        -tipo di riferimento: item
        -tipi utilizzati: string, integer, boolean

    semantica:
        item è la quintupla bk=(code,author,title,copies,loaned) dove:
            -code è la stringa rappresentante il codice di riconoscimento del libro
            -authors è la stringa rappresentante gli autori del libro
            -title è la stringa rappresentante il titolo del libro
            -copies è un intero rappresentante le copie presenti
            -loaned é un boolean che segnala se il libro é stato prestato
*/

typedef struct book* item;

#define NULLITEM NULL;

//SPECIFICA OPERATORI

//sintattica: newItem(string,string,string,integer,boolean)->item
//sintattica: newItem(code,author,title,copies,loaned)->bk
item newItem(const char* code,const char* author,const char* title,const int copies,const int loaned);
//post: bk=(code,authors,title,copies,loaned)

//sintattica: outputBook(book)->nil
//semantica: outputItem(bk)->nil
int outputItem(item i);
//post: scrive a schermo le informazione del libro


//sintattica cloneItem(item)->item
//semantica:cloneItem(bk1)->bk2
item cloneItem(const item b);
//pre: bk1 != nil
//post: bk2=bk1


//sintattica: getISBN(item)->string
//semantica: getISBN(bk)->code
char* getISBN(const item b);
//post: bk=(code,authors,title,copies,loaned)

//Sintattica: setLoan(item)->b
//Semantica: setLoan(bk)->bk'
int setLoan(const item b);
//pre: bk!=nil
//post: bk=(code,authors,title,copies,loaned) AND bk'=(code,authors,title,copies,(loaned=true))

//Sintattica: setLoan(item)->b
//Semantica: setLoan(bk)->bk'
int removeLoan(const item b);
//pre: bk!=nil
//post: bk=(code,authors,title,copies,loaned) AND bk'=(code,authors,title,copies,(loaned=false))

//Sintattica: compItem(item,item)->b
//Semantica: compItem(bk1,bk2)->b
int compItem(item a,item b);
//post: b=1 IF a->code > b->code OR b=-1 IF a->code < b->code OR b=0 IF a->code = b->code

//Sintattica: getAuthor(item)->string
//Semantica: getAuthor(bk1)->author
char* getAuthor(item a);
//post: bk=(code,authors,title,copies,loaned)

