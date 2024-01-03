// Includes
#include "hash-table.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Functions Implementation
ApashTable *apash_new(int capacity) {
	if (capacity < 1) capacity = DEFAULT_TABLE_SIZE;

	ApashTable *hp = malloc(sizeof(ApashTable));
	hp->data = malloc(sizeof(ApashTableItem) * capacity);
	hp->__capacity = capacity;

	return hp;
}

void apash_destroy(ApashTable *hp) {
	// https://stackoverflow.com/questions/10063222/freeing-strings-in-c
	// if key gets allocated memory and used strncpy to save it use free,
	// otherwise there's no need
	free(hp->data);
	free(hp);
}

unsigned int apash_hash(char *key, int capacity) {
	unsigned int hash = 0;

	for (int i = 0; i < strlen(key); i++) {
		hash += *(key + i);
		hash *= 10000000000037;
	}

	return hash % capacity;
}