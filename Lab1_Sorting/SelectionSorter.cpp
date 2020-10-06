//
// Created by Bori on 10/4/2020.
//

#include "SelectionSorter.h"
#include "SorterEvaluator.h"

const char* SelectionSorter::ASSIGN_OP_NAME = "SelectionSort-Assign";
const char* SelectionSorter::COMP_OP_NAME = "SelectionSort-Comp";

void SelectionSorter::sort(int *v, int no_elements, Profiler& p) {
    Operation opComp = p.createOperation(COMP_OP_NAME, no_elements);
    Operation opAssign = p.createOperation(ASSIGN_OP_NAME, no_elements);
    for (int i = 0; i < no_elements; i++){
        int minIndex = i;
        for (int j = i + 1; j < no_elements; j++) {
            opComp.count();
            if (v[minIndex] > v[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            opAssign.count(3);
            const int helper = v[i];
            v[i] = v[minIndex];
            v[minIndex] = helper;
        }
    }
}

const char *SelectionSorter::getCompOpName() {
    return COMP_OP_NAME;
}

const char *SelectionSorter::getAssignOpName() {
    return ASSIGN_OP_NAME;
}
