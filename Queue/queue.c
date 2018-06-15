#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "queue.h"

struct q_node
{
    item val;
    struct q_node* next;
};

struct _queue
{
    struct q_node* first;
    struct q_node* last;
    size_t size;
};

static struct q_node* makeNode(const item i,struct q_node* n)
{
    struct q_node* new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->val=i;
        new->next=n;
    }
    return new;
}

Queue newQueue(void)
{
    Queue new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->first=NULL;
        new->last=NULL;
        new->size=0;
    }
    return new;
}

int enqueue(const Queue q,const item i)
{
    if(q==NULL)
    {
        return -1;
    }
    struct q_node* temp=makeNode(i,NULL);

    if(temp==NULL)
    {
        return 0;
    }

    if(q->first==NULL)
    {
        q->first=temp;
    }
    else
    {
        q->last->next=temp;
    }
    q->last=temp;
    (q->size)++;
    return 1;
}

item dequeue(const Queue q)
{
    if(q==NULL)
    {
        return NULLITEM;
    }
    
    if(q->first==NULL)
    {
        return NULLITEM;
    }
    else
    {
        struct q_node* temp=q->first->next;
        item el=cloneItem(q->first->val);
        destroyItem(&q->first->val);
        free(q->first);
        q->first=temp;
        if(q->first==NULL)
        {
            q->last=NULL;
        }
        (q->size)--;
        return el;
    }
}


int emptyQueue(const Queue q)
{
    if(q==NULL)
    {
        return -1;
    }
    return q->size==0;
}

static void freeList(struct q_node* list);

int destroyQueue(Queue* const qptr)
{
    if(*qptr==NULL)
    {
        return -1;
    }
    freeList((*qptr)->first);
    free(*qptr);
    *qptr=NULL;
    return 1;
}

static void freeList(struct q_node* list)
{
    if(list == NULL)
    {
        return;
    }
    else
    {
        freeList(list->next);
        destroyItem(&list->val);
        free(list);
    }
}