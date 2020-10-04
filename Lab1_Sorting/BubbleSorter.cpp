//
// Created by Bori on 10/4/2020.
//

#include "BubbleSorter.h"

void BubbleSorter::sort(int *v, int no_elements) {
    bool exchangeMade = true;
    for (int i = no_elements - 1; i >= 0 && exchangeMade; i--) {
        exchangeMade = false;
        for (int j = 0; j < i; j++) {
            if (v[i] > v[i+1]) {
                int helper = v[i];
                v[i] = v[i+1];
                v[i+1] = helper;
                exchangeMade = true;
            }
        }
    }
}
