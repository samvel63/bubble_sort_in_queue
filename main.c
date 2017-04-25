#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"



int main(void)
{
	Queue q;
    int val;
    char s[7];

    printf("\n");
    while (1) {
    	scanf("%6s", s);
    	if (!strcmp(s, "create") || !strcmp(s, "cr")) {
    		int cap = 0;
    		scanf("%d", &cap);
    		q = queue_create(cap);
    	} else if (!strcmp(s, "put") || !strcmp(s, "p")) {
    		while(scanf("%d", &val))
    			queue_put(q, val);
    	} else if (!strcmp(s, "get") || !strcmp(s, "g")) {
    		printf("%d\n", queue_get(q));
    	} else if (!strcmp(s, "print") || !strcmp(s, "p")) {
    		queue_print(q);
    	} else if (!strcmp(s, "new")) {
    		queue_destroy(&q);
    		int cap = 0;
    		scanf("%d", &cap);
    		q = queue_create(cap);
    	} else if (!strcmp(s, "sort") || !strcmp(s, "s")) {
    		queue_bubble_sort(q);
    	} else if (!strcmp(s, "help")) {

    	} else if (!strcmp(s, "quit") || !strcmp(s, "q")) {
    		queue_destroy(&q);
    		break;
    	}
    }

    return 0;
}