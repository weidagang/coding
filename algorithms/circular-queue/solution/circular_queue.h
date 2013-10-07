#ifndef __CIRCULAR_QUEUE__
#define __CIRCULAR_QUEUE__

struct _Queue;
typedef struct _Queue Queue;

Queue* initialize(unsigned int capacity);
int destroy(Queue* queue);
int enqueue(Queue* queue, int element);
int dequeue(Queue* queue, int *out_element);
int size(Queue* queue);

#endif
