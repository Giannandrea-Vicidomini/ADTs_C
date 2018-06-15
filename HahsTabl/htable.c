#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "key.h"
#include "htable.h"
typedef struct elem* link;

struct elem
{
    char* key;
    item val;
    link next;
};

struct  h_table
{
    int size;
    link* table;
};

static link newElem(const item i,const Key k)
{
    link new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->key=cloneKey(k);
        new->val=cloneItem(i);
        new->next=NULL;
    }
    return new;
}

HashMap newHashMap(const size_t size)
{
    HashMap new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->size=size;
        new->table=calloc(size,sizeof(struct elem*));
    }
    return new;
}

static int hasDuplicate(link const l,const Key k);

int insertTable(const HashMap h, const item i,const Key k)
{
    if(h==NULL)
    {
        return -1;
    }

    link new,head;
    int hashCode;
    hashCode=hash(k,h->size);
    head=h->table[hashCode];

    if(hasDuplicate(head,k)) return 0;

    new=newElem(i,k);
    h->table[hashCode]=new;
    h->table[hashCode]->next=head;
    return 1;
}

static int hasDuplicate(link const l,Key const k)
{
    if(l==NULL)
    {
        return 0;
    }
    else if(compKey(l->key,k)==0)
    {
        return 1;
    }
    else
    {
        return hasDuplicate(l->next,k);
    }
}

static item findItem(link const l,const Key k);

item searchTable(const HashMap h,const Key k)
{
    if(h==NULL)
    {
        return NULLITEM;
    }
    int hashCode=hash(k,h->size);
    link temp=h->table[hashCode];

    return findItem(temp,k);
}

static item findItem(link const l,const Key k)
{
    if(l==NULL)
    {
        return NULLITEM;
    }
    else if(compKey(l->key,k)==0)
    {
        return l->val;
    }
    else
    {
        return findItem(l->next,k);
    }
}

static link deleteElem(link const l,const Key k,int* const done);
inline static void linkDisposal(link const l);

int deleteTable(const HashMap h,const Key k)
{
    if(h==NULL)
    {
        return -1;
    }

    int hashCode=hash(k,h->size),done=0;
    
    h->table[hashCode]=deleteElem(h->table[hashCode],k,&done);
    return done;
}

static link deleteElem(link const l,const Key k,int* const done)
{
    if(l==NULL)
    {
        return NULL;
    }
    else if(compKey(l->key,k)==0)
    {
        *done=1;
        link temp=l->next;
        linkDisposal(l);
        return temp;
    }
    else
    {
        l->next=deleteElem(l->next,k,done);
        return l;
    }
}

inline static void linkDisposal(link const l)
{
    destroyItem(&l->val);
    destroyKey(l->key);
    free(l);
}

static void destroyList(link const l);

int destroyTable(HashMap* const h)
{
    if(*h==NULL)
    {
        return -1;
    }
    int size=(*h)->size;
    for(int i=0;i<size;i++)
    {
        if((*h)->table[i]!=NULL)
        {
            destroyList((*h)->table[i]);
        }
    }
    free(*h);
    *h=NULL;
    return 1;
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

static void printTable(const link l);

int showTable(const HashMap h)
{
    if(h==NULL)
    {
        return -1;
    }
    int size=h->size;
    printf("(");
    for(int i=0;i<size;i++)
    {
        if(h->table[i]!=NULL)
        {
            printTable(h->table[i]);
            printf(", ");
        }
    }
    puts(")");
    return 1;
}

static void printTable(const link l)
{
    if(l==NULL)
    {
        return;
    }
    else if(l->next==NULL)
    {
        outputKey(l->key);
        printf(" \x1B[32m->\x1B[0m ");
        outputItem(l->val);
    }
    else
    {
        outputKey(l->key);
        printf(" \x1B[32m->\x1B[0m ");
        outputItem(l->val);
        printf(", ");
        printTable(l->next);
    }
}
