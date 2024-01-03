#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "queue.c"
#include "queue.h"

// Auxiliary Print
void apueue_print(Apueue *qp) {
	printf("\n****************************************\n");
	printf("Empty: %d", qp->head == NULL);
	printf("\n[");
	ApueueNode *curr = qp->head;
	while (curr) {
		printf("%d", curr->data);
		if (curr->next) {
			printf(" -> ");
		}
		curr = curr->next;
	}
	printf("]");
	printf("\n****************************************\n");
}

// Main
int main() {
	Apueue *qptr = apueue_new();
	apueue_print(qptr);

	printf("\nEnqueueing 1 into qptr...");
	apueue_enqueue(qptr, 1);
	printf("\nEnqueueing 745 into qptr...");
	apueue_enqueue(qptr, 745);
	printf("\nEnqueueing 98456 into qptr...");
	apueue_enqueue(qptr, 98456);
	apueue_print(qptr);

	apueue_destroy(qptr);
	return 0;
}