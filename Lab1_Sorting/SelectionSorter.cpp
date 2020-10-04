//
// Created by Bori on 10/4/2020.
//

#include "SelectionSorter.h"

void SelectionSorter::sort(int *v, int no_elements) {
    for (int i = 0; i < no_elements; i++){
        int minIndex = i;
        for (int j = i + 1; j < no_elements; j++) {
            if (v[minIndex] > v[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            const int helper = v[i];
            v[i] = v[minIndex];
            v[minIndex] = helper;
        }
    }

}
