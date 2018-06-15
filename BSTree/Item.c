#include <stdio.h>
#include "Item.h"

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
void input_item(item* i)
{
    scanf("%i",i);
}
void output_item(item i)
{
    printf("%i",i);
}


item cloneItem(item i)
{
    return i;
}

void destroyItem(item* i)
{
    return;
}