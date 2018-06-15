#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "stack.h"
#include <gvclib.h>

int isBalanced(const string str);

int main(int argc,string argv[])
{
    /*
    item temp;
    Stack st=createStack();
    initStack(st);
    for(int i=0;i<26;i++)
    {
        push(st,i+97);
    }
    for(int i=0;i<26;i++)
    {
        temp=top(st);
        output_item(temp);
        pop(st);
    }
    puts("");
    for(int i=0;i<10;i++)
    {
        if(!pop(st))
        {
            puts("fail");
        }
    }
    for(int i=0;i<26;i++)
    {
        if(push(st,i+97))
        {
            puts("win");
        }
    }
    for(int i=0;i<26;i++)
    {
        temp=top(st);
        output_item(temp);
        pop(st);
    }
    puts("");
    destroyStack(&st);*/
    check_arguments(argc,argv,1);
    int result;
    result=isBalanced(argv[1]);
    puts(argv[1]);
    if(result==1)
    {
        printf(GREEN"Parenthesis are balanced!\n"RESET);
    }
    else
    {
        printf(RED"Parenthesis are not balanced.\n"RESET);
    }
    return 0;
}

int isBalanced(const string str)
{
    Stack st=newStack();
    item temp;
    int result;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='{' || str[i]=='[' || str[i]=='(' || str[i]==')' || str[i]==']' || str[i]=='}')
        {
            if(str[i]=='{' || str[i]=='[' || str[i]=='(')
            {
                push(st,str[i]);
            }

            if(str[i]==')')
            {
                temp=top(st);
                if(temp=='(')
                {
                    pop(st);
                }
                else
                {
                    return 0;
                }
            }

            if(str[i]==']')
            {
                temp=top(st);
                if(temp=='[')
                {
                    pop(st);
                }
                else
                {
                    return 0;
                }
            }
            
            if(str[i]=='}')
            {
                temp=top(st);
                if(temp=='{')
                {
                    pop(st);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    result=emptyStack(st);
    destroyStack(&st);
    return result;
}