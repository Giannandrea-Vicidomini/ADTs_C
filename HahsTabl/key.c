#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "key.h"

Key getKey(item i)
{
    return getCode(i);
}

int compKey(Key a,Key b)
{
    return strcmp(a,b);
}

Key cloneKey(const Key k)
{
    char* clone=malloc((strlen(k)+1)*sizeof(char));
    strcpy(clone,k);
    return clone;
}

int destroyKey(Key k)
{
    if(k==NULL) return 0;
    free(k);
    return 1;
}

int outputKey(Key k)
{
    if(k==NULL)
    {
        return 0;
    }
    printf("%s",k);
    return 1;
}

//STRINGHE
int hash(Key k,const int size) 
{
    int h,a = 31415,b = 27183;
    for (h =0; *k != '\0'; k++, a = a*b %(size-1))
    {
        h = (a*h + *k) %size;
    }
    return h;
}

//INTERI
/*
int hash(Key k,const int size) 
{
    int a = 31415,b = 27183;

    return (a*k+b)%size;
}
*/