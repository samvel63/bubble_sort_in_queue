#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

#define SWAP(A, B) { Queue t = A; A = B; B = t; }

void queue_bubble_sort(Queue q_bas, int n)
{
    Queue q = queue_create(n);
    Queue q_sub = queue_create(n);
    while (!queue_is_empty(q_bas)) {
        Item tmp = queue_get(q_bas);
        bool is_inserted = false;
        while (!queue_is_empty(q)) {
            if (tmp < queue_first(q) && !is_inserted) {
                is_inserted = true;
                queue_put(q_sub, tmp);
            } else {
                queue_put(q_sub, queue_get(q));
            }
        }
        if (!is_inserted)
            queue_put(q_sub, tmp);
        SWAP(q, q_sub);
    }

    while (!queue_is_empty(q))
        queue_put(q_bas, queue_get(q));

    queue_destroy(&q_sub);
    queue_destroy(&q);
}

int main(void)
{
	Queue q;
    int val = 0, cap = 0, err = 0;
    char s[7];

    printf("\nНаберите команду `help`, чтобы узнать команды, используемые в программе\n\n");
    while (1) {
    	scanf("%6s", s);
    	if (!strcmp(s, "create") || !strcmp(s, "c")) {
    		scanf("%d", &cap);
    		q = queue_create(cap);
    	} else if (!strcmp(s, "put") || !strcmp(s, "p")) {
    		while(scanf("%d", &val))
    			if(queue_put(q, val))
                    fprintf(stderr, "\nНевозможно добавить цифру %d в очередь, т.к. она переполнена.\n\n", val);
    	} else if (!strcmp(s, "get") || !strcmp(s, "g")) {
    		queue_get(q);
    	} else if (!strcmp(s, "print") || !strcmp(s, "pr")) {
    		if(queue_print(q))
                fprintf(stderr, "\nОчередь пуста.\n\n");
    	} else if (!strcmp(s, "new")) {
    		queue_destroy(&q);
    		scanf("%d", &cap);
    		q = queue_create(cap);
    	} else if (!strcmp(s, "sort") || !strcmp(s, "s")) {
    		queue_bubble_sort(q, cap);
    	} else if (!strcmp(s, "help")) {
            printf("\n`сreate numb` и `c numb` === создает очередь размером numb.\n");
            printf("`put n1 n2 ...` и `p n1 n2 ...` === добавляет в очередь элементы n1, n2 ...\n");
            printf("`get` и `g` === выводит первый элемент из очереди.\n");
            printf("`print` и `pr` === печатает очередь.\n");
            printf("`new numb` === создает новую очередь размером numb.\n");
            printf("`sort` === сортирует очередь методом пузырька.\n");
            printf("`quit` и `q` === заканчивает работу программы.\n\n");
    	} else if (!strcmp(s, "quit") || !strcmp(s, "q")) {
    		queue_destroy(&q);
    		break;
    	} else {
            printf("\n\nВведены некорректные данные. Воспользуйтесь командой `help`, чтобы подробнее узнать команды.\n\n");
        }
    }

    return 0;
}