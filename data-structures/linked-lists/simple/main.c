#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.c"
#include "linkedlist.h"

// Auxiliary Print Function
void aplist_print(Aplist *lp) {
	AplistNode *curr = lp->head;

	printf("\n****************************************\n");
	printf("Size: %d", lp->__size);
	printf("\n(");
	while (curr) {
		printf("%d", curr->data);
		if (!curr->next) {
			printf(" -> ");
		}
		curr = curr->next;
	}
	printf(")");
	printf("\n****************************************\n");
}

int main() {
	Aplist *lptr = aplist_new();
	aplist_print(lptr);

	aplist_destroy(lptr);
	return 0;
}