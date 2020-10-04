//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_INSERTIONSORTER_H
#define LAB1_SORTING_CLION_INSERTIONSORTER_H


#include "Sorter.h"

class InsertionSorter : public Sorter{
public:
    void sort(int* v, int no_elements) override;
};


#endif //LAB1_SORTING_CLION_INSERTIONSORTER_H
