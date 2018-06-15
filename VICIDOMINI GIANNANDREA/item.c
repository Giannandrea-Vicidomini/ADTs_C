#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct book
{
    char code[25];
    char authors[100];
    char title[25];
    int copies;
    int loaned;
};

item newItem(const char* code,const char* authors,const char* title,const int copies,const int loaned)
{
    item new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        strcpy(new->code,code);
        strcpy(new->authors,authors);
        strcpy(new->title,title);
        new->copies=copies;
        new->loaned=0;
    }
    return new;
}

item cloneItem(const item b)
{
    item clone=malloc(sizeof(*clone));
    if(clone!=NULL)
    {
        *clone=*b;
    }
    return clone;
}



int outputItem(const item b)
{
    if(b==NULL) return 0;

    printf("(C:%s,A:%s,T:%s,Cop:%i,Loan:%i)\n",b->code,b->authors,b->title,b->copies,b->loaned);
    return 1;
}

char* getISBN(const item b)
{
    if(b==NULL) return NULL;

    char* clone=malloc(strlen(b->code)+1);
    strcpy(clone,b->code);
    return clone;
}



int setLoan(const item b)
{
	if(b==NULL) return 0;
	b->loaned=1;
    return 1;	
}

int removeLoan(const item b)
{
	if(b==NULL) return 0;
	b->loaned=0;
    return 1;	
}

int compItem(item a,item b)
{	
	return strcmp(a->code,b->code);
}

char* getAuthor(item a)
{	
	char* clone=malloc(sizeof(strlen(a->authors)+1));
	if(clone!=NULL)
	{
		strcpy(clone,a->authors);
	}
	return clone;
}

