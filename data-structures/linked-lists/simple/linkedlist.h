#ifndef APACHA_LINKED_LIST
#define APACHA_LINKED_LIST

/*
	https://github.com/jwasham/coding-interview-university#linked-lists
	Implement (I did with tail pointer & without):
		size() - returns the number of data elements in the list
		empty() - bool returns true if empty
		value_at(index) - returns the value of the nth item (starting at 0 for first)
		push_front(value) - adds an item to the front of the list
		pop_front() - remove the front item and return its value
		push_back(value) - adds an item at the end
		pop_back() - removes end item and returns its value
		front() - get the value of the front item
		back() - get the value of the end item
		insert(index, value) - insert value at index, so the current item at that index is pointed to by the new item at the index
		erase(index) - removes node at given index
		value_n_from_end(n) - returns the value of the node at the nth position from the end of the list
		reverse() - reverses the list
		remove_value(value) - removes the first item in the list with this value
*/

typedef struct Apacha_linked_list_node {
	int data;
	struct AplistNode *next;
} AplistNode;

typedef struct Apacha_linked_list {
	int __size;
	AplistNode *head;
} Aplist;

// return a pointer to a new linked list
Aplist *aplist_new();

// free all memory used
void aplist_destroy(Aplist *lp);

// returns the number of data elements in the list
int aplist_size(Aplist *lp);

// bool returns true if empty
bool aplist_empty(Aplist *lp);

// returns the value of the nth item (starting at 0 for first)
int aplist_value_at(Aplist *lp, int index);

// adds an item to the front of the list
void aplist_push_front(Aplist *lp, int value);

// remove the front item and return its value
int aplist_pop_front(Aplist *lp);

// adds an item at the end
void aplist_push_back(Aplist *lp, int value);

// removes end item and returns its value
int aplist_pop_back(Aplist *lp);

// get the value of the front item
int aplist_front(Aplist *lp);

// get the value of the end item
int aplist_back(Aplist *lp);

// insert value at index, so the current item at that index is pointed to by the new item at the index
void aplist_insert(Aplist *lp, int index, int value);

// removes node at given index
void aplist_erase(Aplist *lp, int index);

// returns the value of the node at the nth position from the end of the list
int aplist_value_n_from_end(Aplist *lp, int n);

// reverses the list
void aplist_reverse(Aplist *lp);

// removes the first item in the list with this value
void aplist_remove_value(Aplist *lp, int value);

// Auxiliary
void aplist_print(Aplist *lp);

#endif	// APACHA_LINKED_LIST