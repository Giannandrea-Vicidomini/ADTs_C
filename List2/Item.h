typedef int item; 

#define NULLITEM 0;

int comp_item(item a,item b);
void input_item(item* i);
void output_item(item i);
void finput_item(FILE* input,item* i);
void foutput_item(FILE* output,item i);
int fcountItem(const char* file_name);
item cloneItem(item i);
void destroyItem(item* i);