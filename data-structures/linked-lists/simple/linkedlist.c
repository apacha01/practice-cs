// Includes
#include "linkedlist.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void isIndexValid(Aplist *lp, int index);
void isHeadNull(Aplist *lp, char *operation);

// Functions
void isIndexValid(Aplist *lp, int index) {
	if (0 > index || index >= lp->__size) {
		printf("\n\n\nIndex '%d' out of bounds for list of size '%d'", index, lp->__size);
		exit(1);
	}
}

void isHeadNull(Aplist *lp, char *operation) {
	if (lp->head == NULL) {
		printf("\n\n\nCan not %s from an emtpy list.", operation);
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
	isHeadNull(lp, "pop");

	AplistNode *tmp = lp->head;
	int res = lp->head->data;
	lp->head = lp->head->next;
	free(tmp);
	lp->__size -= 1;

	return res;
}

void aplist_push_back(Aplist *lp, int value) {
	AplistNode *new_node = malloc(sizeof(AplistNode));
	new_node->data = value;
	new_node->next = NULL;

	if (!lp->head) {
		lp->head = new_node;
	}

	AplistNode *current = lp->head;

	while (current->next) {
		current = current->next;
	}

	current->next = new_node;
	lp->__size += 1;
}

int aplist_pop_back(Aplist *lp) {
	isHeadNull(lp, "pop");

	AplistNode *current = lp->head;
	AplistNode *aux;

	while (current->next->next) {
		current = current->next;
	}

	int res = current->next->data;
	aux = current->next;
	current->next = NULL;
	free(aux);

	lp->__size -= 1;

	return res;
}

int aplist_front(Aplist *lp) {
	isHeadNull(lp, "read");
	return lp->head->data;
}

int aplist_back(Aplist *lp) {
	isHeadNull(lp, "read");

	AplistNode *current = lp->head;
	while (current->next) {
		current = current->next;
	}

	return current->data;
}

void aplist_insert(Aplist *lp, int index, int value) {
	isIndexValid(lp, index);

	if (lp->__size == 0 || index == 0) {
		aplist_push_front(lp, value);
	} else {
		AplistNode *current = lp->head;
		AplistNode *new_node = malloc(sizeof(AplistNode));

		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		new_node->data = value;
		new_node->next = current->next;
		current->next = new_node;
		lp->__size += 1;
	}
}

void aplist_erase(Aplist *lp, int index) {
	isHeadNull(lp, "erase");
	isIndexValid(lp, index);

	if (index == 0) {
		aplist_pop_front(lp);
	} else {
		AplistNode *current = lp->head;
		AplistNode *tmp;

		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		tmp = current->next;
		current->next = current->next->next;
		free(tmp);

		lp->__size -= 1;
	}
}

int aplist_value_n_from_end(Aplist *lp, int n) {
	isHeadNull(lp, "read");
	isIndexValid(lp, n);

	AplistNode *current = lp->head;
	for (int i = 0; i < lp->__size - n - 1; i++) {
		current = current->next;
	}

	return current->data;
}

void aplist_reverse(Aplist *lp) {
	for (int i = 0; i < lp->__size - 1; i++) {
		aplist_push_front(lp, aplist_value_at(lp, i + 1));
		aplist_erase(lp, i + 2);
	}
}