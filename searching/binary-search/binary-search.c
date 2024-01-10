#include "binary-search.h"

#include <stdio.h>

int apinary_search(int arr[], int len, int target) {
	int l = 0;
	int h = len - 1;

	while (l <= h) {
		int mid = l + ((h - l) / 2);

		if (arr[mid] > target)
			h = mid - 1;
		else if (arr[mid] < target)
			l = mid + 1;
		else
			return mid;
	}

	return -1;
}