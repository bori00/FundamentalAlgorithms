//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_SORTERTEST_H
#define LAB1_SORTING_SORTERTEST_H

#include "gtest/gtest.h"

class SorterTest : public ::testing::Test {
protected:
    static bool ArrayIsSorted(int *v, int no_elements);

    static int *GetRandomArray() {
        return GetArrayWIthContent(random_array);
    }

    static int *GetSortedArray() {
        return GetArrayWIthContent(sorted_array);
    }

    static int *GetInverselySortedArray() {
        return GetArrayWIthContent(inv_sorted_array);
    }

    static const int ARRAY_LENGTH = 10;

private:
    static int random_array[ARRAY_LENGTH];
    static int sorted_array[ARRAY_LENGTH];
    static int inv_sorted_array[ARRAY_LENGTH];

    static int *GetArrayWIthContent(const int content[ARRAY_LENGTH]);
};

#endif //LAB1_SORTING_SORTERTEST_H
