#ifndef APACHA_BINARY_SEARCH
#define APACHA_BINARY_SEARCH

/*
	https://github.com/jwasham/coding-interview-university#binary-search
	Implement:
		binary search (on a sorted array of integers)
		binary search using recursion
*/

// Performs binary search on sorted input of integers, returns index or -1 if not found
int apinary_search(int arr[], int len, int target);

// Performs binary search using recursion on sorted input of integers, returns index or -1 if not found
int apinary_search_recursive(int arr[], int len, int target);

#endif	// APACHA_BINARY_SEARCH