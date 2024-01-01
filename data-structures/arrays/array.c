// Includes
#include "array.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Constants
#define resizeRate 2
#define shrinkFactor 4
#define minCapacity 16

// Functions Prototypes
int getClosestPowerOf2(int n);
void checkIndexValidity(int size, int index);

// Functions Implementation
int getClosestPowerOf2(int n) {
	if ((n & (n - 1)) == 0)
		// already a power of 2
		return n;

	int value = 1;

	while (value <= n) {
		value = value << 1;
	}

	return value;
}

void checkIndexValidity(int size, int index) {
	if (0 > index || index >= size) {
		printf("\n\n\nIndex %d out of bounds for array of size %d.", index, size);
		exit(1);
	}
}

Apector *apector_new(int capacity) {
	if (capacity <= minCapacity)
		capacity = minCapacity;
	else
		capacity = getClosestPowerOf2(capacity);

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
	checkIndexValidity(vp->__size, index);
	return *(vp->data + index);
}

void apector_push(Apector *vp, int item) {
	const int new_size = vp->__size + 1;
	if (new_size >= vp->__capacity)
		apector_resize(vp, vp->__capacity * resizeRate);

	*(vp->data + vp->__size) = item;
	vp->__size = new_size;
}

void apector_insert(Apector *vp, int index, int item) {
	checkIndexValidity(vp->__size, index);
	const int new_size = vp->__size + 1;
	if (new_size >= vp->__capacity)
		apector_resize(vp, vp->__capacity * resizeRate);

	// shift 'index' value and trailing elements to the right
	// https://www.tutorialspoint.com/c_standard_library/c_function_memmove.htm
	// dest, src, size
	// [..., index, ..., n] -> dest: index + 1, src: index and trailing elements, size: from index to size (size - index)
	memmove(vp->data + index + 1, vp->data + index, (vp->__size - index) * sizeof(int));

	// insert item
	*(vp->data + index) = item;
	vp->__size = new_size;
}

void apector_prepend(Apector *vp, int item) {
	// size check and resize happen on insert function
	apector_insert(vp, 0, item);
}

int apector_pop(Apector *vp) {
	const int new_size = vp->__size - 1;
	if (new_size <= (vp->__capacity / shrinkFactor))
		apector_resize(vp, vp->__capacity / resizeRate);

	int popped_value = *(vp->data + new_size);
	vp->__size = new_size;

	return popped_value;
}

void apector_delete(Apector *vp, int index) {
	checkIndexValidity(vp->__size, index);

	const int new_size = vp->__size - 1;
	if (new_size <= (vp->__capacity / shrinkFactor))
		apector_resize(vp, vp->__capacity / resizeRate);

	// delete item at index, shifting all trailing elements left (override the index)
	// [..., index, ..., n] -> dest: index, src: index + 1 and trailing elements, size: from index to size (size - index)
	memmove(vp->data + index, vp->data + index + 1, (vp->__size - index) * sizeof(int));

	vp->__size = new_size;
}

void apector_remove(Apector *vp, int item) {
	for (int i = 0; i < vp->__size; i++) {
		if (*(vp->data + i) == item) {
			// size check and resize happen on delete function
			apector_delete(vp, i);
			// in case there's 2 consecutive 'item'
			i--;
		}
	}
}

int apector_find(Apector *vp, int item) {
	int res = -1;

	for (int i = 0; i < vp->__size; i++) {
		if (*(vp->data + i) == item) {
			res = i;
			break;
		}
	}

	return res;
}

void apector_resize(Apector *vp, int new_capacity) {
	if (new_capacity < minCapacity)
		new_capacity = minCapacity;

	new_capacity = getClosestPowerOf2(new_capacity);
	vp->__capacity = new_capacity;

	int *new_data = (int *)realloc(vp->data, sizeof(int) * new_capacity);
	vp->data = new_data;
}