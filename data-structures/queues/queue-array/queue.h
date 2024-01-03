#ifndef APACHA_QUEUE
#define APACHA_QUEUE

/*
 https://github.com/jwasham/coding-interview-university#arrays
	Implement using a fixed-sized array:
		enqueue(value) - adds item at end of available storage
		dequeue() - returns value and removes least recently added element
		empty()
		full()
*/

#define QUEUE_SIZE 10

typedef struct Apacha_Queue {
	int data[QUEUE_SIZE + 1];
	int read;
	int write;
} Apueue;

// Return a new queue
Apueue *apueue_new();

// Free all memory
void apueue_destroy(Apueue *qp);

//  adds item at end of available storage
void apueue_enqueue(Apueue *qp, int value);

//  returns value and removes least recently added element
int apueue_dequeue(Apueue *qp);

// true if queue is empty, false otherwise
bool apueue_empty(Apueue *qp);

// true if queue is full, false otherwise
bool apueue_full(Apueue *qp);

#endif	// APACHA_QUEUE