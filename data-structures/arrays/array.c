// Includes
#include "array.h"

// Constants
#define growthRate 2
#define reductionRate 4
#define minCapacity 16

// Functions Prototypes
int getCloserPowerOf2(int n);

// Functions Implementation
int getCloserPowerOf2(int n) {
	if ((n & (n - 1)) == 0)
		// already a power of 2
		return n;

	int value = 1;

	while (value <= n) {
		value = value << 1;
	}

	return value;
}

Apector *apector_new(int capacity) {
	if (capacity <= minCapacity)
		capacity = minCapacity;
	else
		capacity = getCloserPowerOf2(capacity);

	Apector *v = malloc(sizeof(Apector));

	v->data = malloc(sizeof(int) * capacity);
	v->__capacity = capacity;
	v->__size = 0;
}