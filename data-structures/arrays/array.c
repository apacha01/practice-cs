// Includes
#include "array.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Constants
#define growthRate 2
#define reductionRate 4
#define minCapacity 16

// Functions Prototypes
int getCloserPowerOf2(int n);
void checkIndexValidity(Apector *vp, int index);

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

void checkIndexValidity(Apector *vp, int index) {
	if (0 > index || index >= vp->__size) {
		printf("\n\n\nIndex %d out of bounds for array of size %d.", index, vp->__size);
		exit(1);
	}
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

void apector_destroy(Apector *vp) {
	free(vp->data);
	free(vp);
}

int apector_size(Apector *vp) {
	return vp->__size;
}

int apector_capacity(Apector *vp) {
	return vp->__capacity;
}

bool apector_is_empty(Apector *vp) {
	return vp->__size == 0;
}

int apector_at(Apector *vp, int index) {
	checkIndexValidity(vp, index);
	return *(vp->data + index);
}

void apector_push(Apector *vp, int item) {
	const int new_size = vp->__size + 1;
	// if (new_size == capacity) resize(vp, capacity * growthFactor)

	*(vp->data + vp->__size) = item;
	vp->__size = new_size;
}

void apector_insert(Apector *vp, int item, int index) {
	checkIndexValidity(vp, index);
	const int new_size = vp->__size + 1;
	// if (new_size == capacity) resize(vp, capacity * growthFactor)

	// shift 'index' value and trailing elements to the right
	// https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm
	// dest, src, size
	// [..., index, ..., n] -> dest: index + 1, src: index and trailing elements, size: from index to size (size - index)
	memmove(vp->data + index + 1, vp->data + index, (vp->__size - index) * sizeof(int));

	// insert item
	*(vp->data + index) = item;
	vp->__size = new_size;
}