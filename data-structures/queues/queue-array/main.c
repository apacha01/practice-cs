#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.c"
#include "queue.h"

// Auxiliary Print
void apueue_print(Apueue *qp) {
	printf("\n****************************************\n");
	printf("Empty: %d\t-\tFull: %d", qp->read == qp->write, qp->read - 1 == qp->write);
	for (int i = qp->read; i != qp->write; i = (i + 1) % QUEUE_SIZE) {
		printf("%d", qp->data[i]);
		if (i != qp->write - 1) {
			printf(", ");
		}
	}
	printf("\n****************************************\n");
}

// Main
int main() {
	Apueue *qptr = apueue_new();
	apueue_print(qptr);

	apueue_destroy(qptr);
	return 0;
}