// Includes
#include "queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Functions Prototypes
int increaseIndex(int index);

// Functions Implementation
int increaseIndex(int index) {
	return (index + 1) % (QUEUE_SIZE + 1);
}

Apueue *apueue_new() {
	Apueue *q = malloc(sizeof(Apueue));

	q->read = 0;
	q->write = 0;

	return q;
}

void apueue_destroy(Apueue *qp) {
	free(qp);
}

void apueue_enqueue(Apueue *qp, int value) {
	if (apueue_full(qp)) {
		printf("\n\n\nCan not enqueue in a full queue.");
		exit(1);
	}

	*(qp->data + qp->write) = value;
	qp->write = increaseIndex(qp->write);
}

int apueue_dequeue(Apueue *qp) {
	if (apueue_empty(qp)) {
		printf("\n\n\nCan not dequeue in an empty queue.");
		exit(1);
	}

	int res = *(qp->data + qp->read);
	qp->read = increaseIndex(qp->read);
	return res;
}

bool apueue_empty(Apueue *qp) {
	return qp->read == qp->write;
}

bool apueue_full(Apueue *qp) {
	return qp->read - 1 == qp->write;
}