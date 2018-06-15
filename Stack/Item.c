#include "Item.h"
#include <stdio.h>

int eq_item(item a,item b)
{
    return a==b;
}
void input_item(item* i)
{
    scanf(" %c",i);
}
void output_item(item i)
{
    printf("%c",i);
}

void finput_item(FILE* input,item* i)
{
    *i=fgetc(input);
}

void foutput_item(FILE* output,item i)
{
    fprintf(output,"%c ",i);
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
    while((temp=fgetc(file))!=EOF)
    {
        cnt++;
    }
    rewind(file);
    fclose(file);
    return cnt;
}