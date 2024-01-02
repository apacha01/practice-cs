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
		if (curr->next) {
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

	printf("\nSize of lptr: %d. Expected 0.", aplist_size(lptr));
	printf("\nisEmpty lptr: %d. Expected 1 (true).", aplist_empty(lptr));

	printf("\n\nPushing %d to lptr's front...", 1);
	aplist_push_front(lptr, 1);
	printf("\nPushing %d to lptr's front...", 55);
	aplist_push_front(lptr, 55);
	printf("\nPushing %d to lptr's front...", 7);
	aplist_push_front(lptr, 7);
	printf("\nPushing %d to lptr's front...", 69);
	aplist_push_front(lptr, 69);
	aplist_print(lptr);

	printf("\nValue at lptr[%d]: %d", 0, aplist_value_at(lptr, 0));
	printf("\nValue at lptr[%d]: %d", 1, aplist_value_at(lptr, 1));
	printf("\nValue at lptr[%d]: %d", 2, aplist_value_at(lptr, 2));

	printf("\n\nPopping from lptr front: %d", aplist_pop_front(lptr));
	printf("\nPopping from lptr front: %d", aplist_pop_front(lptr));
	aplist_print(lptr);

	printf("\n\nPushing %d to lptr's back...", 10);
	aplist_push_back(lptr, 10);
	printf("\nPushing %d to lptr's back...", 20);
	aplist_push_back(lptr, 20);
	printf("\nPushing %d to lptr's back...", 19);
	aplist_push_back(lptr, 19);
	printf("\nPushing %d to lptr's back...", 984);
	aplist_push_back(lptr, 984);
	aplist_print(lptr);

	aplist_destroy(lptr);
	return 0;
}