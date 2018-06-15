typedef char item;
typedef struct __sFILE FILE;

#define NULLITEM '\0';

int eq_item(item a,item b);
void input_item(item* i);
void output_item(item i);
void finput_item(FILE* input,item* i);
void foutput_item(FILE* output,item i);
int fcountItem(const char* file_name);