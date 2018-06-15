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

void finput_item(FILE* input,item* i)
{
    fscanf(input,"%i",i);
}

void foutput_item(FILE* output,item i)
{
    fprintf(output,"%i ",i);
}

int fcountItem(const char* file_name)
{
    int temp,cnt=0;

    FILE* file=fopen(file_name,"r");
    if(file==NULL)
    {
        puts("\x1B[31mError:\x1B[0min fcountItem,file could not be opened.");
        return EOF;
    }
    while((fscanf(file,"%i",&temp))!=EOF)
    {
        cnt++;
    }
    rewind(file);
    fclose(file);
    return cnt;
}

item cloneItem(item i)
{
    return i;
}

void destroyItem(item* i)
{
    return;
}