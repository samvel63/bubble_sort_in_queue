#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

int main(void)
{
	Queue q;
    int val;

    char s[10];

    printf("\n\n");
    while (1) {
    	scanf("%s", s);
    	if (!strcmp(s, "create") || !strcmp(s, "cr")) {
    		int cap = 0;
    		scanf("%d", &cap);
    		q = queue_create(cap);
    	} else if (!strcmp(s, "put") || !strcmp(s, "p")) {
    		while(scanf("%d", &val))
    			queue_put(q, val);
    	} else if (!strcmp(s, "get") || !strcmp(s, "g")) {
    		int n = 0;
    		scanf("%d", &n);
    		for (int i = 0; i < n; ++i)
    			printf("%d\n", queue_get(q));
    		printf("\n\n");
    	} else if (!strcmp(s, "getall") || !strcmp(s, "ga")) {

    	} else if (!strcmp(s, "clear") || !strcmp(s, "cl")) {
    		while (!queue_is_empty(q))
    			queue_get(q);
    	} else if (!strcmp(s, "sort") || !strcmp(s, "s")) {
    		// Bubble Sort
    	} else if (!strcmp(s, "quit") || !strcmp(s, "q")) {
    		queue_destroy(&q);
    		break;
    	}
    }

    return 0;
}