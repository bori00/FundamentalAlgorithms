//
// Created by Bori on 10/4/2020.
//

#include "InsertionSorter.h"
#include "Profiler.h"

const string InsertionSorter::ASSIGN_OP_NAME = "InsertionSort-Assign";
const string InsertionSorter::COMP_OP_NAME = "InsertionSort-Comp";

void InsertionSorter::sort(int *v, int no_elements) {
    for (int i = 1; i < no_elements; i++) {
        int insertionIndex = i;
        int toInsertValue = v[i];
        while (insertionIndex >= 1 && toInsertValue < v[insertionIndex - 1]) {
            v[insertionIndex] = v[insertionIndex - 1];
            insertionIndex--;
        }
        v[insertionIndex] = toInsertValue;
    }
}
