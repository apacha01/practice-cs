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

void apueue_enqueue(Apueue *qp, int value) {
	ApueueNode *new_node = malloc(sizeof(ApueueNode));
	new_node->data = value;
	new_node->next = NULL;

	if (!qp->head) {
		qp->head = new_node;
		qp->tail = new_node;
	} else {
		qp->tail->next = new_node;
		qp->tail = new_node;
	}
}

int apueue_dequeue(Apueue *qp) {
	if (!qp->head) {
		printf("\n\n\nCan not dequeue from empty list");
		exit(1);
	}

	ApueueNode *tmp = qp->head;
	int res = qp->head->data;
	qp->head = qp->head->next;

	if (qp->tail == tmp)
		qp->tail = qp->head;

	free(tmp);

	return res;
}

bool apueue_empty(Apueue *qp) {
	return qp->head == NULL;
}