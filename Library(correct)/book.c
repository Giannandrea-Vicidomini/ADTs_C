#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

struct book
{
    char code[25];
    char author[25];
    char title[25];
    int copies;
};

Book newBook(const char* code,const char* author,const char* title,const int copies)
{
    Book new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        strcpy(new->code,code);
        strcpy(new->author,author);
        strcpy(new->title,title);
        new->copies=copies;
    }
    return new;
}

Book cloneBook(const Book b)
{
    Book clone=malloc(sizeof(*clone));
    if(clone!=NULL)
    {
        *clone=*b;
    }
    return clone;
}

int getCopies(const Book b)
{
    if(b==NULL) return -1;
    return b->copies;
}

int addCopies(const Book b,const int copies)
{
    if(b==NULL) return 0;

    b->copies+=copies;
    return 1;
}

int removeCopies(const Book b,const int copies)
{
    if(b==NULL) return 0;

    if(copies > b->copies)
    {
        b->copies=0;
    }
    else
    {
        b->copies-=copies;
    }
    return 1;
}

int outputBook(const Book b)
{
    if(b==NULL) return 0;

    printf("(C:%s,A:%s,T:%s,Cop:%i)",b->code,b->author,b->title,b->copies);
    return 1;
}

char* getISBN(const Book b)
{
    if(b==NULL) return NULL;

    char* clone=malloc(strlen(b->code)+1);
    strcpy(clone,b->code);
    return clone;
}

int destroyBook(const Book b)
{
    if(b==NULL) return 0;

    free(b);
    return 1;
}