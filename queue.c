#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

typedef struct _queue {
    int head;
    int last;
    int size;
    Item *data;
};

Queue queue_create(int queue_size)
{
    Queue q = (Queue) malloc(sizeof(*q));

    q->size = queue_size + 1;
    q->data = (Item *) malloc(sizeof(Item) * q->size);

    q->head = q->size;
    q->last = 0;

    return q;
}

int queue_put(Queue q, Item value)
{
    if ((q->last + 1) % q->size == q->head)
        return QUEUE_ERROR;

    q->data[q->last++] = value;
    q->last %= q->size;

    return QUEUE_SUCCESS;
}

Item queue_get(Queue q)
{
    if (q->head % q->size == q->last) {
        fprintf(stderr, "Очередь пуста.\n\n");
        return QUEUE_ERROR;
    }

    q->head %= q->size;
    return q->data[q->head++];
}

bool queue_is_empty(Queue q)
{
    return (q->head % q->size) == q->last;
}

void queue_destroy(Queue *q)
{
    free((*q)->data);
    free(*q);
}

Item queue_first(Queue q)
{
    return q->data[q->head % q->size];
}

int queue_size(Queue q)
{
    return q->size;
}

void queue_print(Queue q)
{
    printf("\n");
	if (q->head % q->size < q->last) {
		for (int i = q->head % q->size; i < q->last; ++i)
			printf("%d ", q->data[i]);			
		printf("\n\n");
	} else {
		for (int i = q->head; i < q->size; ++i)
			printf("%d ", q->data[i]);
		for (int i = 0; i < q->last; ++i)
			printf("%d ", q->data[i]);
		printf("\n\n");
	}
}