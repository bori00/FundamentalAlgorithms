#include "SelectionSorter.h"

void SelectionSorter::sort(int* a, int no_elements) {
	for (int i = 0; i < no_elements; i++) {
		int minIndex = i;
		for (int j = i + 1; j < no_elements; j++) {
			if (a[minIndex] > a[j]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			const int helper = a[i]; 
			a[i] = a[minIndex];
			a[minIndex] = helper;
		}
	}
}
