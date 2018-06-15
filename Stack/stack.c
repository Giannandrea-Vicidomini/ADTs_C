#include "Item.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT 5
#define RESIZE 5

struct _stack
{
    item* pile;
    int top;
    size_t buf_size;
};

Stack newStack(void)
{
    Stack new=malloc(sizeof(*new));
    new->pile=calloc(STACK_INIT,sizeof(item));
    new->top=0;
    new->buf_size=STACK_INIT;
    return new;
}

int destroyStack(Stack* s)
{
    if(s!=NULL)
    {
        free((*s)->pile);
        free(*s);
        *s=NULL;
        return 1;
    }
    return 0;
}

int pop(const Stack s)
{
    if(s!=NULL && s->top>0)
    {
        s->top--;
        return 1;
    }
    return 0;
}

int push(const Stack s,const item i)
{
    if(s!=NULL)
    {
        if(s->buf_size-1 == s->top )
        {
            item* temp=realloc(s->pile,(s->buf_size+RESIZE)*sizeof(item));
            if(temp==NULL)
            {
                puts("Error: space unavailable.");
                return -1;
            }
            s->pile=temp;
            s->buf_size+=RESIZE;
        }
        s->pile[s->top]=i;
        s->top++;
        //printf("size: %lu\nelements: %i\n",s->buf_size,s->top);
        return 1;
    }
    return 0;
}

item top(const Stack s)
{
    if(s!=NULL && s->top!=0)
    {
        return s->pile[s->top-1];
    }
    return NULLITEM;
}

int emptyStack(const Stack s)
{
    return s->top==0;
}
