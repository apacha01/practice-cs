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
		printf("%d,", *(vector->data + i));
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
	printf("\nCapacity: %d. Expected 32.", apector_capacity(aptr));
	printf("\nCapacity: %d. Expected 16.", apector_capacity(aptr1));
	printf("\nCapacity: %d. Expected 16.", apector_capacity(aptr2));
}