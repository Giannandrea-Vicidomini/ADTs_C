#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "queue.h"

int main(void)
{
    Queue q=newQueue();
    for(int i=10;i<=20;i++)
    {
        enqueue(q,i);
    }
    
    while(!emptyQueue(q))
    {
        item i;
        i=dequeue(q);
        output_item(i);
        printf(" ");
    }
    
    destroyQueue(&q);
    return 0;
}