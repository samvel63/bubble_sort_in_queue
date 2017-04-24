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

void queue_put(Queue q, Item value)
{
    q->data[q->last++] = value;
    printf("%d == (%d %d)\n", value, q->last - 1, q->head);
    q->last %= q->size;
}

Item queue_get(Queue q)
{
    q->head %= q->size;
    printf("%d == (%d %d)\n", q->data[q->head], q->last, q->head);
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

void queue_print(Queue q)
{
	if (q->head % q->size < q->last) {
		for (int i = q->head % q->size; i < q->last; ++i) {
			//printf("[%d %d]\n", i, q->last);
			printf("%d ", q->data[i]);			
		}

		printf("\n\n");
	} else {
		for (int i = q->head; i < q->size; ++i)
			printf("%d ", q->data[i]);
		for (int i = 0; i < q->last; ++i)
			printf("%d ", q->data[i]);
		printf("\n\n");
	}
}