#ifndef _QUEUE_H
#define _QUEUE_H

typedef int Item;
typedef struct _queue *Queue;

Queue queue_create(int queue_size);
void queue_put(Queue q, Item value);
Item queue_get(Queue q);
bool queue_is_empty(Queue q);
void queue_destroy(Queue *q);
void queue_print(Queue q);

#endif