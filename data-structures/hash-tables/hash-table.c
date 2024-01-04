// Includes
#include "hash-table.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Functions prototypes
void checkKey(char *key);

// Functions Implementation
void checkKey(char *key) {
	if (key) return;

	printf("\n\n\nKey can not be NULL.\n\tkey: %s", key);
	exit(1);
}

ApashTable *apash_new(int capacity) {
	if (capacity < 1) capacity = DEFAULT_TABLE_SIZE;

	ApashTable *hp = malloc(sizeof(ApashTable));
	hp->data = malloc(sizeof(ApashTableItem) * capacity);
	hp->__capacity = capacity;

	for (int i = 0; i < hp->__capacity; i++) {
		(hp->data + i)->isFree = true;
		(hp->data + i)->key = NULL;
		(hp->data + i)->value = 0;
	}

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
	checkKey(key);
	unsigned int hash = 0;

	for (int i = 0; i < strlen(key); i++) {
		hash += *(key + i);
		hash *= 10000000000037;
	}

	return hash % capacity;
}

void apash_add(ApashTable *hp, char *key, int value) {
	unsigned int hash = apash_hash(key, hp->__capacity);

	for (int i = 0; i < hp->__capacity; i++) {
		hash = (hash + i) % hp->__capacity;	 // add i to hash index in case space is taken and need the next one

		bool areKeysEqualLength = (hp->data + hash)->key ? strlen((hp->data + hash)->key) == strlen(key) : false;
		bool areKeysEqual = areKeysEqualLength ? strncmp((hp->data + hash)->key, key, strlen(key)) == 0 : false;

		// if free, create a new one
		if ((hp->data + hash)->isFree) {
			(hp->data + hash)->isFree = false;
			(hp->data + hash)->key = key;
			(hp->data + hash)->value = value;
			return;
		}
		// not free but keys match, replace value in existing key
		else if (!((hp->data + hash)->isFree) && areKeysEqual) {
			(hp->data + hash)->value = value;
			return;
		}
		// else not free and keys don't match, look for another place in table (i++)
	}

	printf("\n\n\nTable is full, can not add another item");
	exit(1);
}

bool apash_exists(ApashTable *hp, char *key) {
	checkKey(key);
	unsigned int hash = apash_hash(key, hp->__capacity);

	for (int i = 0; i < hp->__capacity; i++) {
		hash = (hash + i) % hp->__capacity;

		bool areKeysEqualLength = (hp->data + hash)->key ? strlen((hp->data + hash)->key) == strlen(key) : false;

		if (areKeysEqualLength && strncmp((hp->data + hash)->key, key, strlen(key)) == 0) return true;
	}

	return false;
}