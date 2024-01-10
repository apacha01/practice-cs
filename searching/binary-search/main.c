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

	print_arr(arr1, sizeof(arr1) / sizeof(int));
	print_arr(arr2, sizeof(arr2) / sizeof(int));
	print_arr(arr3, sizeof(arr3) / sizeof(int));
	print_arr(arr4, sizeof(arr4) / sizeof(int));

	return 0;
}
