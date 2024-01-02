// Includes
#include "linkedlist.h"

#include <stdbool.h>
#include <stdio.h>

// Function Prototypes
void isIndexValid(Aplist *lp, int index);

// Functions
void isIndexValid(Aplist *lp, int index) {
	if (0 > index || index >= lp->__size) {
		printf("\n\n\nIndex '%d' out of bounds for list of size '%d'", index, lp->__size);
		exit(1);
	}
}

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

int aplist_value_at(Aplist *lp, int index) {
	isIndexValid(lp, index);

	AplistNode *current = lp->head;
	for (int i = 0; i < index && current; i++) {
		current = current->next;
	}

	return current->data;
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

int aplist_pop_front(Aplist *lp) {
	if (!lp->head) {
		printf("\n\n\nCan not pop from empty list.");
		exit(1);
	}

	AplistNode *tmp = lp->head;
	int res = lp->head->data;
	lp->head = lp->head->next;
	free(tmp);
	lp->__size -= 1;

	return res;
}