#include <stdio.h>
#include <stdlib.h>

#include "binary-search.c"
#include "binary-search.h"

void print_arr(int arr[], int len);

void print_arr(int arr[], int len) {
	printf("\n****************************************\n");
	printf("[");
	for (int i = 0; i < len; i++) {
		printf("%d", arr[i]);
		if (i < len - 1) printf(",");
	}
	printf("]");
	printf("\n****************************************\n");
}

int main() {
	int arr1[1] = {1};
	int arr2[2] = {1, 2};
	int arr3[0] = {};
	int arr4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int sizeArr1 = sizeof(arr1) / sizeof(int);
	int sizeArr2 = sizeof(arr2) / sizeof(int);
	int sizeArr3 = sizeof(arr3) / sizeof(int);
	int sizeArr4 = sizeof(arr4) / sizeof(int);

	print_arr(arr1, sizeArr1);
	print_arr(arr2, sizeArr2);
	print_arr(arr3, sizeArr3);
	print_arr(arr4, sizeArr4);

	printf("\n\nSearching 1 in arr1: %d", apinary_search(arr1, sizeArr1, 1));
	printf("\nSearching 1 in arr2: %d", apinary_search(arr2, sizeArr2, 1));
	printf("\nSearching 1 in arr3: %d", apinary_search(arr3, sizeArr3, 1));
	printf("\nSearching 1 in arr4: %d", apinary_search(arr4, sizeArr4, 1));

	printf("\n\nSearching 2 in arr1: %d", apinary_search(arr1, sizeArr1, 2));
	printf("\nSearching 2 in arr2: %d", apinary_search(arr2, sizeArr2, 2));
	printf("\nSearching 2 in arr3: %d", apinary_search(arr3, sizeArr3, 2));
	printf("\nSearching 2 in arr4: %d", apinary_search(arr4, sizeArr4, 2));

	printf("\n\nSearching 9 in arr4: %d", apinary_search(arr4, sizeArr4, 9));
	printf("\nSearching 5 in arr4: %d", apinary_search(arr4, sizeArr4, 5));
	printf("\nSearching 6 in arr4: %d", apinary_search(arr4, sizeArr4, 6));
	printf("\nSearching 10 in arr4: %d", apinary_search(arr4, sizeArr4, 10));

	printf("\n\nSearching 0 in arr1: %d", apinary_search(arr1, sizeArr1, 0));
	printf("\nSearching 1 in arr1: %d", apinary_search(arr1, sizeArr1, 1));
	printf("\nSearching 2 in arr1: %d", apinary_search(arr1, sizeArr1, 2));

	printf("\n\nSearching 0 in arr2: %d", apinary_search(arr2, sizeArr2, 0));
	printf("\nSearching 1 in arr2: %d", apinary_search(arr2, sizeArr2, 1));
	printf("\nSearching 2 in arr2: %d", apinary_search(arr2, sizeArr2, 2));
	printf("\nSearching 3 in arr2: %d", apinary_search(arr2, sizeArr2, 3));

	return 0;
}
