#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash-table.c"
#include "hash-table.h"

// Auxiliary Print
void apash_print(ApashTable *hp) {
	printf("\n****************************************\n");
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
	return 0;
}