#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "tree.h"


struct t_node
{
    item val;
    struct t_node* left;
    struct t_node* right;
};

struct tree
{
    struct t_node* root;
    size_t size;
};

Tree newTree(void)
{
    Tree new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->root=NULL;
        new->size=0;
    }
    return new;
}

int emptyTree(const Tree t)
{
    if(t==NULL)
    {
        return -1;
    }
    return t->size==0;
}

static int leaf(const struct t_node* t)
{
    return t->left==NULL && t->right==NULL;
}

static int contains(const struct t_node* t,const item i);

int searchTree(const Tree t,const item i)
{
    if(t==NULL)
    {
        return -1;
    }
    return contains(t->root,i);
}

static int contains(const struct t_node* t,const item i)
{
    if(t==NULL)
    {
        return 0;
    }
    else if(comp_item(i,t->val)==0)
    {
        return 1;
    }
    else if(comp_item(i,t->val)==1)
    {
        return contains(t->right,i);
    }
    else
    {
        return contains(t->left,i);
    }
}

static struct t_node* makeNode(const item i,struct t_node* l,struct t_node* r);
static struct t_node* inject(struct t_node* t,const item i,int* done); 

int insertTree(const Tree t,const item i)
{
    if(t==NULL)
    {
        return -1;
    }
    int res=0;
    t->root=inject(t->root,i,&res);
    if(res==1)
    {
        t->size++;
    }
    return res;
}

static struct t_node* makeNode(const item i,struct t_node* l,struct t_node* r)
{
    struct t_node* new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->val=cloneItem(i);
        new->left=l;
        new->right=r;
    }
    return new;
}

static struct t_node* inject(struct t_node* t,const item i,int* done)
{
    if(t==NULL)
    {
        *done=1;
        return makeNode(i,NULL,NULL);
    }
    else if(comp_item(i,t->val)==0)
    {
        return t;
    }
    else if(comp_item(i,t->val)==1)
    {
        t->right=inject(t->right,i,done);
        return t;
    }
    else
    {
        t->left=inject(t->left,i,done);
        return t;
    }
}

static struct t_node* t_remove(struct t_node* t,const item i,int* done);
static struct t_node* removeMax(struct t_node* t,item* el);

int deleteTree(const Tree t,const item i)
{
    if(t==NULL)
    {
        return -1;
    }
    int res=0;
    t->root=t_remove(t->root,i,&res);
    if(res==1)
    {
        t->size--;
    }
    return res;
}

static struct t_node* t_remove(struct t_node* t,const item i,int* done)
{
    if(t==NULL)
    {
        return NULL;
    }
    else if(comp_item(i,t->val)==1)
    {
        t->right=t_remove(t->right,i,done);
        return t;
    }
    else if(comp_item(i,t->val)==-1)
    {
        t->left=t_remove(t->left,i,done);
        return t;
    }
    else
    {
        if(leaf(t))
        {
            destroyItem(&t->val);
            free(t);
            *done=1;
            return NULL;
        }
        else if(t->left==NULL)
        {
            struct t_node* temp=t->right;
            destroyItem(&t->val);
            free(t);
            *done=1;
            return temp;
        }
        
        else
        {
            item j=NULLITEM;
            t->left=removeMax(t->left,&j);
            destroyItem(&t->val);
            t->val=j;
            *done=1;
            return t;
        }
    }

}

static struct t_node* removeMax(struct t_node* t,item* el)
{
    if(t->right==NULL)
    {
        *el=cloneItem(t->val);
        if(t->left==NULL)
        {
            destroyItem(&t->val);
            free(t);
            return NULL;
        }
        else
        {
            struct t_node* temp=t->left;
            destroyItem(&t->val);
            free(t);
            return temp;
        }
    }
    else
    {
        t->right=removeMax(t->right,el);
        return t;
    }
}

static void freeTree(struct t_node* t);

int destroyTree(Tree* const tptr)
{
    if(*tptr==NULL)
    {
        return -1;
    }
    freeTree((*tptr)->root);
    free(*tptr);
    *tptr=NULL;
    return 1;
}

static void freeTree(struct t_node* t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        freeTree(t->left);
        freeTree(t->right);
        destroyItem(&t->val);
        free(t);
    }
}

/*
static int tSize(struct t_node* t)
{
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        return 1 + tSize(t->left) + tSize(t->right);
    }
}

int sizeTree(const Tree t)
{
    if(t==NULL)
    {
        return -1;
    }
    return tSize(t->root);
}
*/
int sizeTree(const Tree t)
{
    if(t==NULL)
    {
        return -1;
    }
    return t->size;
}

static int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

static void printIn(const struct t_node* t);

int showTree(const Tree t)
{
    if(t==NULL)
    {
        return 0; 
    }
    if(t->size==0)
    {
        printf("[]\n");
        return 1;
    }
    else
    {
        printf("Tree( ");
        printIn(t->root);
        puts(")");
        return 1;
    }
}

static void printIn(const struct t_node* t)
{
    if(t==NULL)
    {
        return;
    }
    /*
    else if(leaf(t))
    {
        output_item(t->val);
        printf(" ");
    }
    */
    else
    {
        printIn(t->left);
        output_item(t->val);
        printf(" ");
        printIn(t->right);
    }
}

void printv(item* vec,int size)
{
    if(size==1)
    {
        output_item(vec[size-1]);
        printf(" ");
    }
    else
    {
        printv(vec,size-1);
        output_item(vec[size-1]);
        printf(" ");
    }
}

static void toVector(struct t_node* t,item* vec,int* index);

void tvec(Tree t)
{
    int arrayIndex=0;
    item* v=malloc(t->size*sizeof(item));
    toVector(t->root,v,&arrayIndex);
    printv(v,t->size);
    puts("");
    free(v);
}

static void toVector(struct t_node* t,item* vec,int* index)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        toVector(t->left,vec,index);
        vec[*index]=t->val;
        (*index)++;
        toVector(t->right,vec,index);
    }
}