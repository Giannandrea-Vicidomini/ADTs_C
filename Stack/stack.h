#include "Item.h"
typedef struct _stack* Stack;

Stack newStack(void);
int destroyStack(Stack* s);
int pop(const Stack s);
int push(const Stack s,const item i);
item top(const Stack s);
int emptyStack(const Stack s);