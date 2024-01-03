// Includes
#include "queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Functions Implementation
Apueue *apueue_new() {
	Apueue *q = malloc(sizeof(Apueue));

	q->head = NULL;
	q->tail = NULL;

	return q;
}

void apueue_destroy(Apueue *qp) {
	ApueueNode *current = qp->head;
	ApueueNode *next;

	while (current) {
		next = current->next;
		free(current);
		current = next;
	}

	free(qp);
}
