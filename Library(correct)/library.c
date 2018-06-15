#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "library.h"

typedef struct elem* link;

struct elem
{
    char* key;
    Book item;
    link next;
};

struct lib
{
    size_t size;
    link* table;
};
//----------------STRUCTURE FUNCTIONS---------------------//

static int hash(const char* k,const int size) 
{
    int h,a = 31415,b = 27183;
    for (h =0; *k != '\0'; k++, a = a*b %(size-1)) 
    {
        h = (a*h + *k) %size;
    }
    return h;
}

static char* cloneString(char* const str)
{
    char* clone=malloc(strlen(str)+1);
    strcpy(clone,str);
    return clone;
}

static link newElem(const Book b,char* const key)
{
    link new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->key=cloneString(key);
        new->item=cloneBook(b);
        new->next=NULL;
    }
    return new;
}

static int hasDuplicate(link const l,char* const k)
{
    if(l==NULL)
    {
        return 0;
    }
    else if(strcmp(k,l->key)==0)
    {
        return 1;
    }
    else
    {
        return hasDuplicate(l->next,k);
    }
}

static Book findItem(link const l,char* const k)
{
    if(l==NULL)
    {
        return NULL;
    }
    else if(strcmp(k,l->key)==0)
    {
        return l->item;
    }
    else
    {
        return findItem(l->next,k);
    }
}

inline static void linkDisposal(link const l)
{
    destroyBook(l->item);
    free(l->key);
    free(l);
}

static void destroyList(link const l)
{
    if(l==NULL)
    {
        return;
    }
    else
    {
        destroyList(l->next);
        linkDisposal(l);
    }
}

static void printTable(const link l)
{
    if(l==NULL)
    {
        return;
    }
    else
    {
        outputBook(l->item);
        printf("\n");
        printTable(l->next);
    }
}

static void noCopies(const link l)
{
    if(l==NULL)
    {
        return;
    }
    else if(getCopies(l->item)==0)
    {
        outputBook(l->item);
        printf("\n");
        noCopies(l->next);
    }
    else
    {
        noCopies(l->next);
    }
}

//--------------------------------------------------------//

Library newLibrary(const int size)
{
    Library new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->size=size;
        new->table=calloc(size,sizeof(link));
    }
    return new;
}

int addBook(const Library l,const Book b,char* const  ISBN)
{
    if(l==NULL)
    {
        return -1;
    }

    link new,head;
    int hashCode;
    hashCode=hash(ISBN,l->size);
    head=l->table[hashCode];

    if(hasDuplicate(head,ISBN)) return 0;

    new=newElem(b,ISBN);
    l->table[hashCode]=new;
    l->table[hashCode]->next=head;
    return 1;
}

Book searchBook(const Library l,char* const ISBN)
{
    if(l==NULL)
    {
        return NULL;
    }
    int hashCode=hash(ISBN,l->size);
    link temp=l->table[hashCode];

    return findItem(temp,ISBN);
}

int addBookCopies(const Library l,char* const ISBN,const int amount)
{
    if(l==NULL) return -1;

    Book temp=searchBook(l,ISBN);
    if(temp==NULL) return 0;
    addCopies(temp,amount);
    return 1;
} 

int removeBookCopies(const Library l,char* const ISBN,const int amount)
{
    if(l==NULL) return -1;

    Book temp=searchBook(l,ISBN);
    if(temp==NULL) return 0;
    removeCopies(temp,amount);
    return 1;
}

int showLibrary(const Library l)
{
    if(l==NULL)
    {
        return -1;
    }
    int size=l->size;
    puts("The library contains:");
    for(int i=0;i<size;i++)
    {
        if(l->table[i]!=NULL)
        {
            printTable(l->table[i]);
            printf("\n");
        }
    }
    puts("");
    return 1;
}

int noCopiesList(const Library l)
{
    if(l==NULL)
    {
        return -1;
    }
    int size=l->size;
    puts("The book without copies are:");
    for(int i=0;i<size;i++)
    {
        if(l->table[i]!=NULL)
        {
            noCopies(l->table[i]);
            printf("\n");
        }
    }
    puts("");
    return 1;
}

int destroyLibrary(Library* const lptr)
{
    if(*lptr==NULL) return -1;

    int size=(*lptr)->size;
    for(int i=0;i<size;i++)
    {
        if((*lptr)->table[i]!=NULL)
        {
            destroyList((*lptr)->table[i]);
        }
    }
    free(*lptr);
    *lptr=NULL;
    return 1;
}