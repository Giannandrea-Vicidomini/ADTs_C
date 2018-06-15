/* ADT Library

Specifica Sintattica

Tipo di riferimento: library
Tipi usati: item, integer, boolean, string

Specifica Semantica:

Library è l'insieme di elementi l=<a1,a2,...,an> di tipo item
    dove ogni elemento ha una stringa identificativa univoca(ISBN)
    appartiene all'insieme anche nil, rappresentante la libreria vuota

//////OPERATORI/////

Specifica sintattica

newLibreria()->library
addBook(library,item)->library
loanBook(library,string)->boolean
returnBook(library,string)->library
searchBook(library,string)->item
showLibrary(library)->void
showAuthorBooks(library,string)-void

Specifica semantica

newLibrary()->l
POST: l= {empty set}

addBook(l,bk)->l'
POST: l={a1,a2,...,an} AND l'=l U {bk}

loanBook(l,k)->l'
PRE:l = {a1, a2, …,ai,.., an} and ai->ISBN=k and c>0
POST: l'={a1, a2, ...,ai'…, an} and ai->loaned=true

returnBook(l,k,)->l'
PRE:l = {a1, a2, …,ai,.., an} and ai->ISBN=k and 0<c<ai->copie
POST: l'={a1, a2, ...,ai'…, an} and ai->loaned=false

searchBook(l,k)->bk
PRE:l = {a1, a2, …,ai,..., an} n>0, ai->ISBN=k
POST: l = {a1, a2, …,ai,..., an} n>0, bk=ai

showLibrary(l)->nil
post: mostra la libreria in ordine di codice

showAuthorBooks(l,k)->nil
post: mostra i libri di un autore in ordine di titolo
*/

typedef struct lib* Library;

Library newLibrary(void);
int addBook(const Library l,const item b);
item searchBook(const Library l,char* const ISBN);
int loanBook(const Library l,char* const ISBN);
int returnBook(const Library l,char* const ISBN);
int showLibrary(const Library l);
int showAuthorBooks(const Library l,const char* author);

