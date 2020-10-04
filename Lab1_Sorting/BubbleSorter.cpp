//
// Created by Bori on 10/4/2020.
//

#include "BubbleSorter.h"

void BubbleSorter::sort(int *v, int no_elements) {
    bool exchangeMade = true;
    for (int i = no_elements - 1; i >= 1 && exchangeMade; i--) {
        exchangeMade = false;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j+1]) {
                int helper = v[j];
                v[j] = v[j+1];
                v[j+1] = helper;
                exchangeMade = true;
            }
        }
    }
}
