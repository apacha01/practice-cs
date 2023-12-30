#ifndef APACHA_VECTOR
#define APACHA_VECTOR

/*
 https://github.com/jwasham/coding-interview-university#arrays
 Implement a vector (mutable array with automatic resizing):
		Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
		New raw data array with allocated memory
				can allocate int array under the hood, just not use its features
				start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
		size() - number of items
		capacity() - number of items it can hold
		is_empty()
		at(index) - returns item at given index, blows up if index out of bounds
		push(item)
		insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
		prepend(item) - can use insert above at index 0
		pop() - remove from end, return value
		delete(index) - delete item at index, shifting all trailing elements left
		remove(item) - looks for value and removes index holding it (even if in multiple places)
		find(item) - looks for value and returns first index with that value, -1 if not found
		resize(new_capacity) // private function
				when you reach capacity, resize to double the size
				when popping an item, if size is 1/4 of capacity, resize to half
 Time
		O(1) to add/remove at end (amortized for allocations for more space), index, or update
		O(n) to insert/remove elsewhere
 Space
		contiguous in memory, so proximity helps performance
		space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
*/

typedef struct Apacha_Vector {
	int *data;
	int __size;
	int __capacity;
} Apector;

// Return a new vector with given capacity's closer power of 2
Apector *apector_new(int capacity);

// returns the number of elements in the vector
int apector_size(Apector *vp);

// return the actual number of elements it could hold
int apector_capacity(Apector *vp);

// true if vector is empty, else false
bool apector_is_empty(Apector *vp);

// return the item at given index
int apector_at(Apector *vp, int index);

// insets given item at the end of the vector
void apector_push(Apector *vp, int item);

// inserts given item at given index, shifts that index's value and trailing elements to the right
void apector_insert(Apector *vp, int index, int item);

// inserts given item at the beginning of the vector
void apector_prepend(Apector *vp, int item);

// removes and returns the last item of the vector
int apector_pop(Apector *vp);

// deletes the item at given index, shifting trailing elements to the left.
void apector_delete(Apector *vp, int index);

// deletes the given item of the vector, even if in multiple places
void apector_remove(Apector *vp, int item);

// return the index of given item, -1 if not found
int apector_find(Apector *vp, int item);

// private function, resizes the vector according to the new_capacity
void apector_resize(Apector *vp, int new_capacity);

// Auxiliary
void apector_print(Apector *vector);

#endif	// APACHA_VECTOR