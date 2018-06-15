#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "list.h"

int main(void)
{
    List try=inputList(0);
    item temp;
    puts("");
    printf("The list is: ");
    outputList(try);
    int pos,val,index;
    puts("List insertion test:");
    while(1)
    {
        printf("enter value: ");
        scanf("%i",&val);
        printf("enter position: ");
        scanf("%i",&pos);
        if(val<0)
        {
            break;
        }
        insertList(try,pos,val);
        outputList(try);
        printf("size is: %i\ni",sizeList(try));
    }
    puts("List deletion test:");
    while(1)
    {
        printf("enter pos: ");
        scanf("%i",&pos);
        if(pos<0)
        {
            break;
        }
        removeList(try,pos);
        outputList(try);
        printf("size is: %i\n",sizeList(try));
    }
    puts("List searching test:");
    while(1)
    {
        printf("enter value: ");
        scanf("%i",&pos);
        if(pos<0)
        {
            break;
        }
        temp=getItem(try,pos);
        output_item(temp);
        puts("");
        index=posItem(try,temp);
        printf("%i\n",index);
    }
    reverseList(try);
    puts("");
    printf("reversed list is: ");
    outputList(try);
    List clone=cloneList(try);
    puts("");
    printf("The clone is: ");
    outputList(clone);
    destroyList(&try);
    destroyList(&clone);
    return 0;
}