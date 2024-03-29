#include <stdbool.h>

#ifndef APACHA_HASH_TABLE
#define APACHA_HASH_TABLE

/*
	https://github.com/jwasham/coding-interview-university#hash-table
	Implement with array using linear probing
		hash(k, m) - m is the size of the hash table
		add(key, value) - if the key already exists, update value
		exists(key)
		get(key)
		remove(key)
*/

#define DEFAULT_TABLE_SIZE 16

typedef struct Apacha_Hash_Table_Item {
	char *key;
	int value;
	bool isFree;
} ApashTableItem;

typedef struct Apacha_Hash_Table {
	ApashTableItem *data;
	int __capacity;
} ApashTable;

// Return a new hash table
ApashTable *apash_new(int capacity);

// Free all memory
void apash_destroy(ApashTable *hp);

// hash given key, m is the size of the hash table
unsigned int apash_hash(char *k, int m);

// adds key/value pair, if the key already exists, update value
void apash_add(ApashTable *hp, char *key, int value);

// true if key exists, false otherwise
bool apash_exists(ApashTable *hp, char *key);

// return value of given key
int apash_get(ApashTable *hp, char *key);

// removes key/value pair from table
void apash_remove(ApashTable *hp, char *key);

#endif	// APACHA_HASH_TABLE