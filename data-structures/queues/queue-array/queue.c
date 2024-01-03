// Includes
#include "queue.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Functions Prototypes
int increaseIndex(int index);

// Functions Implementation
int increaseIndex(int index) {
	return (index + 1) % QUEUE_SIZE;
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
	*(qp->data + qp->write) = value;
	qp->write = increaseIndex(qp->write);
}