//
// Created by Bori on 10/4/2020.
//

#include "BubbleSorter.h"
#include "SorterEvaluator.h"

const char* BubbleSorter::ASSIGN_OP_NAME = "BubbleSort-Assign";
const char* BubbleSorter::COMP_OP_NAME = "BubbleSort-Comp";

void BubbleSorter::sort(int *v, int no_elements, Profiler& p) {
    Operation opComp = p.createOperation(COMP_OP_NAME, no_elements);
    Operation opAssign = p.createOperation(ASSIGN_OP_NAME, no_elements);
    bool exchangeMade = true;
    for (int i = no_elements - 1; i >= 1 && exchangeMade; i--) {
        exchangeMade = false;
        for (int j = 0; j < i; j++) {
            opComp.count();
            if (v[j] > v[j+1]) {
                int helper = v[j];
                v[j] = v[j+1];
                v[j+1] = helper;
                opAssign.count(3);
                exchangeMade = true;
            }
        }
    }
}

const char *BubbleSorter::getCompOpName() {
    return COMP_OP_NAME;
}

const char *BubbleSorter::getAssignOpName() {
    return ASSIGN_OP_NAME;
}

