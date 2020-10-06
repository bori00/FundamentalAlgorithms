//
// Created by Bori on 10/4/2020.
//

#include "InsertionSorter.h"
#include "Profiler.h"
#include "SorterEvaluator.h"

const char* InsertionSorter::ASSIGN_OP_NAME = "InsertionSort-Assign";
const char* InsertionSorter::COMP_OP_NAME = "InsertionSort-Comp";

void InsertionSorter::sort(int *v, int no_elements, Profiler& p) {
    Operation opComp = p.createOperation(COMP_OP_NAME, no_elements);
    Operation opAssign = p.createOperation(ASSIGN_OP_NAME, no_elements);
    for (int i = 1; i < no_elements; i++) {
        int insertionIndex = i;
        int toInsertValue = v[i];
        opAssign.count();
        while (insertionIndex >= 1 && toInsertValue < v[insertionIndex - 1]) {
            opComp.count();
            v[insertionIndex] = v[insertionIndex - 1];
            opAssign.count();
            insertionIndex--;
        }
        if (insertionIndex >= 1) {
            opComp.count();
        }
        v[insertionIndex] = toInsertValue;
        opAssign.count();
    }
}

const char *InsertionSorter::getCompOpName() {
    return COMP_OP_NAME;
}

const char *InsertionSorter::getAssignOpName() {
    return ASSIGN_OP_NAME;
}

