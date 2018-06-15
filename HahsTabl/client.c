#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "key.h" 
#include "htable.h"

int main(void)
{
    HashMap map=newHashMap(50);
    item a,b,c;
    a=newItem("01","honolulu","2:00:00",34,23);
    b=newItem("02","FarFarAway","1:00:00",35,28);
    c=newItem("03","Avalar","3:00:00",36,26);

    insertTable(map,a,getKey(a));
    insertTable(map,b,getKey(b));
    insertTable(map,c,getKey(c));

    showTable(map);

    puts("after deletion:");
    deleteTable(map,"02");
    showTable(map);

    item temp=searchTable(map,"03");
    if(temp!=NULL)
    {
        puts("the item that you sought is:");
        outputItem(temp);
        puts("");
    }

    return 0;
}