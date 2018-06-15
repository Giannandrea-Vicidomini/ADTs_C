#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "list.h"

struct node
{
    item value;
    struct node* next;
};

struct _list
{
    struct node* start;
    size_t size;
};

List newList(void)
{
    List new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->size=0;
        new->start=NULL;
    }
    return new;
}

int emptyList(const List l)
{
    if(l!=NULL)
    {
        return l->size==0;
    }
    return -1;
}

int sizeList(const List l)
{
    if(l==NULL)
    {
        return -1;
    }
    return l->size;
}

item getItem(const List l, const int pos)
{
    if(l==NULL)
    {
        return NULLITEM;
    }

    if(pos<0 || pos>=sizeList(l))
    {
        return NULLITEM;
    }

    struct node* temp=l->start;
    int i=0;
    while(i<pos)
    {
        i++;
        temp=temp->next;
    }

    return temp->value;

}

int posItem(const List l,const item val)
{
    if(l==NULL)
    {
        return -1;
    }
    struct node* temp=l->start;
    int found=0,pos=0;
    while(temp!=NULL && !found)
    {
        if(comp_item(temp->value,val)==0)
        {
            found=1;
        }
        else
        {
            pos++;
            temp=temp->next;
        }
    }
    return (found) ? pos : -1;
}

static struct node* insertNode(struct node* head,const int pos,const item val);
static struct node* makeNode(const item val,struct node* nxt);

int insertList(const List l,const int pos,const item val)
{
    if(l==NULL)
    {
        return 0;
    }
    if(pos<0 || pos>sizeList(l))
    {
        return 0;
    }
    struct node* check=insertNode(l->start,pos,val); 
    if(check==NULL)
    {
        return 0;
    }
    l->start=check;
    l->size++;   
    return 1;
}

static struct node* makeNode(const item val,struct node* nxt)
{
    struct node* new=malloc(sizeof(*new));
    item i=cloneItem(val);
    new->value=i;
    new->next=nxt;
    return new;
}

static struct node* insertNode(struct node* head,const int pos,const item val)
{
    if(pos==0)
    {
        return makeNode(val,head);
    }

    struct node* temp=head,* check;
    int i=0;
    while(i<pos-1)
    {
        i++;
        temp=temp->next;
    }
    check=makeNode(val,temp->next);
    if(check==NULL)
    {
        return NULL;
    }
    temp->next=check;
    return head;
}

static struct node* removeNode(struct node* head,const int pos);

int removeList(const List l,const int pos)
{
    if(l==NULL)
    {
        return 0;
    }
    struct node* check,* temp1;
    if(pos<0 || pos>=l->size)
    {
        return 0;
    }
    check=removeNode(l->start,pos);
    l->start=check;
    l->size--;
    return 1;
}

static struct node* removeNode(struct node* head,const int pos)
{
    struct node* temp,* temp1;
    if(pos==0)
    {
        temp=head;
        head=head->next;
        destroyItem(&(temp->value));
        free(temp);
        return head;
    }
    int i=0;
    temp=head;
    while(i<pos-1)
    {
        i++;
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    destroyItem(&(temp1->value));
    free(temp1);
    return head;
}

int reverseList(const List l)
{
    if(l==NULL)
    {
        return 0;
    }
    if(l->size==0)
    {
        return 0;
    }
    struct node* prev=NULL,* curr=l->start,* succ=curr->next;
    while(curr!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=succ;
        if(curr!=NULL)
        {
            succ=succ->next;
        }
    }
    l->start=prev;
    return 1;
}

int deleteList(const List l)
{
    if(l==NULL)
    {
        return 0;
    }
    struct node* temp=l->start,* temp1;
    while(temp!=NULL)
    {
        temp1=temp->next;
        destroyItem(&(temp->value));
        free(temp);
        temp=temp1;
    }
    l->start=NULL;
    l->size=0;
    return 1;
}

static struct node* recursiveClone(struct node* const head);

List cloneList(const List l)
{
    if(l==NULL)
    {
        return NULL;
    }
    List new=malloc(sizeof(*new));
    new->size=l->size;
    new->start=recursiveClone(l->start);
    return new;
}

static struct node* recursiveClone(struct node* const head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        return makeNode(head->value,recursiveClone(head->next));
    }
}

int outputList(const List l)
{
    if(l==NULL)
    {
        return 0;
    }
    if(l->size==0)
    {
        printf("[]\n");
        return 1;
    }
    struct node* temp=l->start;
    printf("[");
    while(temp!=NULL)
    {
        if(temp->next==NULL)
        {
            output_item(temp->value);
        }
        else
        {
            output_item(temp->value);
            printf(",");
        }
        temp=temp->next;
    }
    printf("]\n");
    return 1;
}

static struct node* recursiveInput(const int n);

List inputList(const int n)
{
    if(n<0)
    {
        return NULL;
    }
    List new=newList();
    new->start=recursiveInput(n);
    new->size=n;
    return new;
}


static struct node* recursiveInput(const int n)
{
    item temp;
    if(n==0)
    {
        return NULL;
    }
    else
    {
        printf("Insert element: ");
        input_item(&temp);
        return makeNode(temp,recursiveInput(n-1));
    }
}

int destroyList(List* const list)
{
    if(*list==NULL)
    {
        return 0;
    }
    deleteList(*list);
    *list=NULL;
    return 1;
}
