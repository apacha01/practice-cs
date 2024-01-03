#ifndef APACHA_QUEUE
#define APACHA_QUEUE

/*
	https://github.com/jwasham/coding-interview-university#queue
	Implement using linked-list, with tail pointer:
		enqueue(value) - adds value at a position at the tail
		dequeue() - returns value and removes least recently added element (front)
		empty()
*/

typedef struct Apacha_Queue_Node {
	struct Apacha_Queue_Node *next;
	int data;
} ApueueNode;

typedef struct Apacha_Queue {
	ApueueNode *head;
	ApueueNode *tail;
} Apueue;

// Return a new queue
Apueue *apueue_new();

// Free all memory
void apueue_destroy(Apueue *qp);

// adds value at a position at the tail
void apueue_enqueue(Apueue *qp, int value);

// returns value and removes least recently added element (front)
int apueue_dequeue(Apueue *qp);

// true if queue is empty, false otherwise
bool apueue_empty(Apueue *qp);

#endif	// APACHA_QUEUE