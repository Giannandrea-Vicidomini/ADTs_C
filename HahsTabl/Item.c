#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

struct travel
{
    char code[30];
    char destination[30];
    char duration[15];
    int price;
    int seats;
};

/*
int comp_item(item a,item b)
{
    if(a>b)
    {
        return 1;
    }
    else if(a<b)
    {
        return -1;
    }
    else    {

        return 0;
    }
}
*/

item newItem(const char* code,const char* destination,const char* duration,const int price,const int seats)
{
    item new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        strcpy(new->code,code);
        strcpy(new->destination,destination);
        strcpy(new->duration,duration);
        new->price=price;
        new->seats=seats;
    }
    return new;
}

item inputItem()
{
    char code[30];
    char destination[30];
    char duration[8];
    int price;
    int seats;
    printf("Enter code: ");
    scanf("%s",code);
    printf("Enter destinatio: ");
    scanf("%s",destination);
    printf("Enter duration: ");
    scanf("%s",duration);
    printf("Enter price: ");
    scanf("%i",&price);
    printf("Enter seats: ");
    scanf("%i",&seats);
    return newItem(code,destination,duration,price,seats);
}

void prettyPrintItem(item i)
{
    printf("Travel Info:\n");
    printf("Code: %s\n",i->code);
    printf("Destination: %s\n",i->destination);
    printf("Duration: %s\n",i->duration);
    printf("Price: %i$\n",i->price);
    printf("seats: %i\n",i->seats);
}

void outputItem(item i)
{
    printf("(\x1B[31mCd\x1B[0m:%s,\x1B[31mDst\x1B[0m:%s,\x1B[31mDur\x1B[0m:%s,\x1B[31mPr\x1B[0m:%i$,\x1B[31mSts\x1B[0m:%i)",i->code,i->destination,i->duration,i->price,i->seats);
}

item cloneItem(item i)
{
    item clone=malloc(sizeof(*clone));
    *clone=*i;
    return clone;
}

void destroyItem(item* i)
{
    free(*i);
    *i=NULL;
}

char* getCode(item i)
{
    char* key=malloc((strlen(i->code)+1)*sizeof(char));
    strcpy(key,i->code);
    return key;
}

int updateSeats(item i,const int amount)
{
    if(i==NULL)
    {
        return 0;
    }
    i->seats=amount;
    return 1;
}

int updatePrice(item i,const int amount)
{
    if(i==NULL)
    {
        return 0;
    }
    i->price=amount;
    return 1;
}