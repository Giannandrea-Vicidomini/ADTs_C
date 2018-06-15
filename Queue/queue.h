typedef struct _queue* Queue;

Queue newQueue(void);
int enqueue(const Queue q,const item i);
item dequeue(const Queue q);
int emptyQueue(const Queue q);
int destroyQueue(Queue* const qptr);