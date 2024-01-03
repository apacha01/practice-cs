#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash-table.c"
#include "hash-table.h"

// Auxiliary Print
void apash_print(ApashTable *hp) {
	printf("\n****************************************\n");
	printf("Capacity: %d", hp->__capacity);
	printf("\n[");
	for (int i = 0; i < hp->__capacity; i++) {
		printf("%d", (hp->data + i)->value);
		if (i != hp->__capacity - 1) {
			printf(",");
		}
	}
	printf("]");
	printf("\n****************************************\n");
}

// Main
int main() {
	ApashTable *aptr = apash_new(10);
	ApashTable *aptr1 = apash_new(1);
	ApashTable *aptr2 = apash_new(0);

	apash_print(aptr);
	apash_print(aptr1);
	apash_print(aptr2);

	return 0;
}