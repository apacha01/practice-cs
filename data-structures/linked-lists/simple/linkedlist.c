// Includes
#include "linkedlist.h"

#include <stdbool.h>
#include <stdio.h>

// Functions
Aplist *aplist_new() {
	Aplist *lp = malloc(sizeof(Aplist));

	lp->__size = 0;
	lp->head = NULL;

	return lp;
}

void aplist_destroy(Aplist *lp) {
	AplistNode *current = lp->head;
	AplistNode *next;

	while (current) {
		next = current->next;
		free(current);
		current = next;
	}

	free(lp);
}

int aplist_size(Aplist *lp) {
	return lp->__size;
}

bool aplist_empty(Aplist *lp) {
	return lp->__size == 0;
}

void aplist_push_front(Aplist *lp, int value) {
	AplistNode *new_node = malloc(sizeof(AplistNode));

	new_node->data = value;

	if (lp->head) {
		new_node->next = lp->head;
	}

	lp->head = new_node;
	lp->__size += 1;
}