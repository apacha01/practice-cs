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

	printf("\n\nPopping from lptr's back: %d", aplist_pop_back(lptr));
	printf("\nPopping from lptr's back: %d", aplist_pop_back(lptr));
	printf("\nPopping from lptr's back: %d", aplist_pop_back(lptr));
	aplist_print(lptr);

	printf("\n\nReading from lptr's front: %d", aplist_front(lptr));
	printf("\n\nReading from lptr's back: %d", aplist_back(lptr));

	printf("\n\nInserting into lptr[%d]: %d", 0, 100);
	aplist_insert(lptr, 0, 100);
	printf("\nInserting into lptr[%d]: %d", 1, 200);
	aplist_insert(lptr, 1, 200);
	printf("\nInserting into lptr[%d]: %d", aplist_size(lptr) - 1, 300);
	aplist_insert(lptr, aplist_size(lptr) - 1, 300);
	printf("\nInserting into lptr[%d]: %d", 3, 400);
	aplist_insert(lptr, 3, 400);
	aplist_print(lptr);

	printf("\n\nErasing node at lptr[%d]...", 0);
	aplist_erase(lptr, 0);
	printf("\nErasing node at lptr[%d]...", 2);
	aplist_erase(lptr, 2);
	printf("\nErasing node at lptr[%d]...", aplist_size(lptr) - 1);
	aplist_erase(lptr, aplist_size(lptr) - 1);
	printf("\nErasing node at lptr[%d]...", 3);
	aplist_erase(lptr, 3);
	aplist_print(lptr);

	printf("\n\nValue at %d from end: %d", 0, aplist_value_n_from_end(lptr, 0));
	printf("\nValue at %d from end: %d", 1, aplist_value_n_from_end(lptr, 1));
	printf("\nValue at %d from end: %d\n", 2, aplist_value_n_from_end(lptr, 2));

	aplist_print(lptr);
	printf("Reversing list...");
	aplist_reverse(lptr);
	aplist_print(lptr);

	printf("\n\nRemoving value %d from lptr...", 10);
	aplist_remove_value(lptr, 10);
	printf("\nRemoving value %d from lptr...", 1);
	aplist_remove_value(lptr, 1);
	printf("\nRemoving value %d from lptr...", 55);
	aplist_remove_value(lptr, 55);
	aplist_print(lptr);

	aplist_destroy(lptr);
	return 0;
}