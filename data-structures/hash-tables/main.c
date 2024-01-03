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
	ApashTable *hptr = apash_new(10);
	ApashTable *hptr1 = apash_new(1);
	ApashTable *hptr2 = apash_new(0);

	apash_print(hptr);
	apash_print(hptr1);
	apash_print(hptr2);

	printf("\nHashing key '%s' with capacity '%d': %d", "abc", hptr->__capacity, apash_hash("abc", hptr->__capacity));
	printf("\nHashing key '%s' with capacity '%d': %d", "def", hptr->__capacity, apash_hash("def", hptr->__capacity));
	printf("\nHashing key '%s' with capacity '%d': %d", "123", hptr->__capacity, apash_hash("123", hptr->__capacity));

	return 0;
}