#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "tree.h"

item times2(item a)
{
    return a*2;
}

item add(item a,item b)
{
    return a+b;
}

item max(item a,item b)
{
    if(comp_item(a,b)==1 || comp_item(a,b)==0) return a;
    else return b;
}

item min(item a,item b)
{
    if(comp_item(a,b)==-1) return a;
    else return b;
}

item siz(item a,item b)
{
    return 1+b;
}

int main(void)
{
    Tree t=newTree();
    insertTree(t,33);
    insertTree(t,37);
    insertTree(t,29);
    insertTree(t,28);
    //deleteTree(t,31);
    //deleteTree(t,35);
    //deleteTree(t,28);
    printf("inorder: ");
    showTree(t);

    printf("----------------------\n");

    printf("T tree size: %i\n",sizeTree(t));
    
    tvec(t);
   
    tvec(t);

    destroyTree(&t);
    return 0;
}