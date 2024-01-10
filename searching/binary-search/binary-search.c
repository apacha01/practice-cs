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

int apinary_search_recursive(int arr[], int l, int h, int target) {
	int mid = l + ((h - l) / 2);
	if (l > h)
		return -1;
	else if (arr[mid] > target)
		return apinary_search_recursive(arr, l, mid - 1, target);
	else if (arr[mid] < target)
		return apinary_search_recursive(arr, mid + 1, h, target);
	else
		return mid;
}