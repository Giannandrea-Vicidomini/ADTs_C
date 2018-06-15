#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "library.h"

typedef struct structure* link; 

struct lib
{
    link root;
    size_t size;
};

struct structure
{
    item val;
    struct structure* left;
    struct structure* right;
};
//----------------STRUCTURE FUNCTIONS---------------------//


static link makeNode(const item i,link l,link r)
{
    link new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->val=cloneItem(i);
        //new->val=i;
        new->left=l;
        new->right=r;
    }
    return new;
}

static link insert(link t,const item i,int* done)
{
    if(t==NULL)
    {
        *done=1;
        return makeNode(i,NULL,NULL);
    }
    else if(compItem(i,t->val)==0)
    {
        return t;
    }
    else if(compItem(i,t->val)>0)
    {
        t->right=insert(t->right,i,done);
        return t;
    }
    else
    {
        t->left=insert(t->left,i,done);
        return t;
    }
}

static item t_search(const link t,const char* name)
{
    char* temp;
    if(t!=NULL)
    {
        temp=getISBN(t->val);
    }
    if(t==NULL)
    {
        return 0;
    }
    else if(strcmp(name,temp)==0)
    {
        free(temp);
        return t->val;
    }
    else if(strcmp(name,temp)>0)
    {
        free(temp);
        return t_search(t->right,name);
    }
    else
    {
        return t_search(t->left,name);
    }
}

static void print(const link t)
{
    if(t==NULL)
    {
        return;
    }
    else
    {
        print(t->left);
        outputItem(t->val);
        print(t->right);
    }
}

/*
static void freeTree(link t)
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
*/

//--------------------------------------------------------//

Library newLibrary(void)
{
	Library new=malloc(sizeof(*new));
    if(new!=NULL)
    {
        new->size=0;
        new->root=NULL;
    }
    return new;
}

int addBook(const Library l,const item b)
{
	if(l==NULL)
    {
        return -1;
    }
    int res=0;
    l->root=insert(l->root,b,&res);
    if(res==1)
	{
		l->size++;
    }
    return res;
}

item searchBook(const Library l,char* const ISBN)
{
	if(l==NULL)
    {
    	return NULL;
    }
    return cloneItem(t_search(l->root,ISBN));
}

int loanBook(const Library l,char* const ISBN)
{
	if(l==NULL)
    {
     	return -1;
    }
    item temp=t_search(l->root,ISBN);
    if (temp==NULL) return 0;
    	
    setLoan(temp);
    return 1;
}
int returnBook(const Library l,char* const ISBN)
{
	if(l==NULL)
    {
       	return -1;
    }
    item temp=t_search(l->root,ISBN);
    if (temp==NULL) return 0;
    	
    removeLoan(temp);
    return 1;
}

int showLibrary(const Library l)
{
	if(l==NULL)
    {
       	return -1;
    }
    puts("The library is:\n");
    print(l->root);
    return 1;
}

static int cmpTitle(const void* a,const void* b);
static int treeToVec(link t,item* vec,size_t size);
static void printVec(const item* vec,const size_t size);
static int filterAuthor(const item* vec,const size_t size,const char* author,item* outvec);

int showAuthorBooks(const Library l,const char* author)
{
	if(l==NULL)
    {
    	return -1;
    }
    int arrSize;
    item vec[l->size],authorVec[l->size];
    	
    treeToVec(l->root,vec,0);
    arrSize=filterAuthor(vec,l->size,author,authorVec);
    qsort(authorVec,arrSize,sizeof(item),cmpTitle);
    puts("We have these books from the author you sought:");
    printVec(authorVec,arrSize);
    return 1;
}

static void printVec(const item* vec,const size_t size)
{
    if(size==0)
    {
        return;
    }
    else if(size==1)
    {
        outputItem(vec[size-1]);
    }
    else
    {
        printVec(vec,size-1);
        outputItem(vec[size-1]);
    }
}

static int treeToVec(link t,item* vec,size_t size)
{
    if(t==NULL)
    {
        return size;
    }
    vec[size]=t->val;
    size++;
    if(t->left!=NULL) size=treeToVec(t->left,vec,size);

    if(t->right!=NULL) size=treeToVec(t->right,vec,size);

    return size;
}

static int cmpTitle(const void* a,const void* b)
{
    item* n=(item*)a,* m=(item*)b;
    char* str1=getAuthor(*n);
    char* str2=getAuthor(*m);
	int res=strcmp(str1,str2);
    free(str1);
	free(str2);
	if(res>0) return 1;
	else if(res<0) return -1;
    else return 0;
}

static int filterAuthor(const item* vec,const size_t size,const char* author, item* outvec)
{
	int sizeout=0,cnt=0;
	char* temp;
	for(int i=0;i<size;i++)
	{
		temp=getAuthor(vec[i]);
		if(strcmp(temp,author)==0)
		{
			sizeout++;
			outvec[cnt]=vec[i];
			cnt++;
		}
		free(temp);
	}
	return sizeout;
}



