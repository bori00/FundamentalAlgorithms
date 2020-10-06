//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_SELECTIONSORTER_H
#define LAB1_SORTING_CLION_SELECTIONSORTER_H

#include <string>
#include "Sorter.h"

using namespace std;

class SelectionSorter : public Sorter {
public:
    void sort(int* v, int no_elements) override;

    // todo: change to static const
    const static string ASSIGN_OP_NAME;
    const static string COMP_OP_NAME;
};


#endif //LAB1_SORTING_CLION_SELECTIONSORTER_H
