#include "circular_queue.h"
#include <malloc.h>

#define OK 0
#define ERROR -1

struct _Queue {
    int capacity;
    int head;
    int tail;
    int *buffer;
};

Queue* initialize(unsigned int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (NULL == queue) {
        return NULL;
    }

    queue->capacity = capacity;
    queue->head = 0;
    queue->tail = 0;
    queue->buffer = (int*)malloc(sizeof(int) * (1 + capacity));
    if (NULL == queue->buffer) {
        free(queue);
        return NULL;
    }

    return queue;
}

int destroy(Queue *queue) {
    free(queue->buffer);
    free(queue);
    return OK;
}

int enqueue(Queue *queue, int element) {
    if (size(queue) >= queue->capacity) {
        return ERROR;
    }
    
    queue->buffer[queue->tail] = element;
    queue->tail = (queue->tail + 1) % (queue->capacity + 1);

    return OK;
}

int dequeue(Queue *queue, int *out_element) {
    if (size(queue) <= 0) {
        return ERROR;
    }

    *out_element = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % (queue->capacity + 1);
    return OK;
}

int size(Queue *queue) {
    return (queue->tail - queue->head + (1 + queue->capacity)) % (1 + queue->capacity);
}

