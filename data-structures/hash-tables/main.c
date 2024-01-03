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

	printf("\n\nAdding {key: %s, value: %d} to hptr...", "123", 123);
	apash_add(hptr, "123", 123);
	printf("\nAdding {key: %s, value: %d} to hptr...", "456", 456);
	apash_add(hptr, "456", 456);
	printf("\nAdding {key: %s, value: %d} to hptr...", "789", 789);
	apash_add(hptr, "789", 789);
	apash_print(hptr);

	printf("\n\nAdding {key: %s, value: %d} to hptr...", "789", 987);
	apash_add(hptr, "789", 987);
	apash_print(hptr);

	// printf("\n\nAdding {key: %s, value: %d} to hptr...", NULL, 987);
	// apash_add(hptr, NULL, 987);	// THROWS ERROR: Key can not be NULL.
	//													key: (null)

	return 0;
}