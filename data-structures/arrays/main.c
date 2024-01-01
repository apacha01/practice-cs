#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array.c"
#include "array.h"

// Auxiliary Print
void apector_print(Apector *vector) {
	printf("\n******************************\n");
	printf("Size: %d\n", vector->__size);
	printf("Capacity: %d\n", vector->__capacity);

	printf("Items: [");
	for (int i = 0; i < vector->__size; ++i) {
		printf("%d", *(vector->data + i));
		if (!(i == vector->__size - 1))
			printf(",");
	}

	printf("]");
	printf("\n******************************\n");
}

// Main
int main() {
	Apector *aptr = apector_new(17);
	Apector *aptr1 = apector_new(16);
	Apector *aptr2 = apector_new(15);

	// apector_new test
	apector_print(aptr);
	apector_print(aptr1);
	apector_print(aptr2);

	// apector_size test
	printf("\nSize: %d. Expected 0.", apector_size(aptr));

	// apector_capacity test
	printf("\naptr Capacity: %d. Expected 32.", apector_capacity(aptr));
	printf("\naptr1 Capacity: %d. Expected 16.", apector_capacity(aptr1));
	printf("\naptr2 Capacity: %d. Expected 16.", apector_capacity(aptr2));

	// apector_is_empty test
	printf("\naptr Is Empty: %d. Expected 1 (true).", apector_is_empty(aptr));

	// apector_push test
	printf("\n\nPushing 1 into aptr...");
	apector_push(aptr, 1);
	printf("\nPushing 17 into aptr...");
	apector_push(aptr, 17);
	printf("\nPushing 890 into aptr...");
	apector_push(aptr, 890);
	printf("\nPushing -1 into aptr...");
	apector_push(aptr, -1);
	apector_print(aptr);

	printf("aptr Size: %d. Expected 4.", apector_size(aptr));
	printf("\naptr Capacity: %d. Expected 32.", apector_capacity(aptr));
	printf("\naptr Is Empty: %d. Expected 0 (false).", apector_is_empty(aptr));

	// apector_at test
	printf("\n\naptr[%d]: %d. Expected 1.", 0, apector_at(aptr, 0));
	printf("\naptr[%d]: %d. Expected 17.", 1, apector_at(aptr, 1));
	printf("\naptr[%d]: %d. Expected 890.", 2, apector_at(aptr, 2));
	printf("\naptr[%d]: %d. Expected -1.", 3, apector_at(aptr, 3));

	// apector_insert test
	printf("\n\nInserting 10 into aptr[0]...");
	apector_insert(aptr, 0, 10);
	printf("\nInserting 20 into aptr[4]...");
	apector_insert(aptr, 4, 20);
	printf("\nInserting 30 into aptr[2]...");
	apector_insert(aptr, 2, 30);
	printf("\nInserting 40 into aptr[5]...");
	apector_insert(aptr, 5, 40);
	apector_print(aptr);

	// apector_prepend test
	printf("\n\nPrepending 10 into aptr...");
	apector_prepend(aptr, 10);
	printf("\nPrepending 20 into aptr...");
	apector_prepend(aptr, 20);
	printf("\nPrepending 30 into aptr...");
	apector_prepend(aptr, 30);
	apector_print(aptr);

	// apector_pop test
	printf("\n\nPopping value from aptr: %d", apector_pop(aptr));
	printf("\nPopping value from aptr: %d", apector_pop(aptr));
	printf("\nPopping value from aptr: %d", apector_pop(aptr));
	apector_print(aptr);

	// apector_delete test
	printf("\n\nDeleting value in aptr[%d]: %d", 1, apector_at(aptr, 1));
	apector_delete(aptr, 1);
	printf("\nDeleting value in aptr[%d]: %d", 5, apector_at(aptr, 5));
	apector_delete(aptr, 5);
	printf("\nDeleting value in aptr[%d]: %d", 2, apector_at(aptr, 2));
	apector_delete(aptr, 2);
	apector_print(aptr);

	// apector_remove test
	printf("\n\nRemoving value %d from aptr.", 30);
	apector_remove(aptr, 30);
	apector_print(aptr);

	// apector_find test
	printf("\n\nFind index of value 30 in aptr: %d.", apector_find(aptr, 30));
	printf("\nFind index of value 10 in aptr: %d.", apector_find(aptr, 10));
	printf("\nFind index of value 890 in aptr: %d.", apector_find(aptr, 890));
	apector_print(aptr);

	// free memory
	printf("\n\n\nDestroying all vectors...");
	apector_destroy(aptr);
	apector_destroy(aptr1);
	apector_destroy(aptr2);
}