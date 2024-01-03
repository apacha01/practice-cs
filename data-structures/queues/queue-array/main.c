#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.c"
#include "queue.h"

// Auxiliary Print
void apueue_print(Apueue *qp) {
	printf("\n****************************************\n");
	printf("Empty: %d\t-\tFull: %d", qp->read == qp->write, qp->read - 1 == qp->write);
	printf("\nRead Index: %d\t-\tWrite Index: %d", qp->read, qp->write);
	printf("\n[");
	for (int i = qp->read; i != qp->write; i = (i + 1) % QUEUE_SIZE) {
		printf("%d", *(qp->data + i));
		if (i != qp->write - 1) {
			printf(", ");
		}
	}
	printf("]");
	printf("\n****************************************\n");
}

// Main
int main() {
	Apueue *qptr = apueue_new();
	apueue_print(qptr);

	printf("\n\nEnqueuing 1 into qptr...");
	apueue_enqueue(qptr, 1);
	printf("\nEnqueuing 3 into qptr...");
	apueue_enqueue(qptr, 3);
	printf("\nEnqueuing 456 into qptr...");
	apueue_enqueue(qptr, 456);
	apueue_print(qptr);

	printf("\n\nDequeueing from qptr: %d", apueue_dequeue(qptr));
	printf("\nDequeueing from qptr: %d", apueue_dequeue(qptr));
	apueue_print(qptr);
	printf("Dequeueing from qptr: %d", apueue_dequeue(qptr));
	apueue_print(qptr);

	apueue_destroy(qptr);
	return 0;
}