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
		if (!curr->next->next) {
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

	apueue_destroy(qptr);
	return 0;
}