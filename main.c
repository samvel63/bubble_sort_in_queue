#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

int main(void)
{
    int val;
    Queue q = queue_create(100);

    while (scanf("%d", &val) == 1)
        queue_put(q, val);

    while (!queue_is_empty(q))
        printf("%d\n", queue_get(q));

    queue_destroy(&q);
    return 0;
}