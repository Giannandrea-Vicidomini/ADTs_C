typedef int item; 

#define NULLITEM 0;

int comp_item(item a,item b);
void input_item(item* i);
void output_item(item i);
item cloneItem(item i);
void destroyItem(item* i);