//
// Created by Bori on 10/4/2020.
//

#ifndef LAB1_SORTING_CLION_BUBBLESORTER_H
#define LAB1_SORTING_CLION_BUBBLESORTER_H

#include <string>
#include "Sorter.h"

using namespace std;

class BubbleSorter : public Sorter {
public:
    void sort(int*v, int no_elements) override;

    const static string ASSIGN_OP_NAME;
    const static string COMP_OP_NAME;
};


#endif //LAB1_SORTING_CLION_BUBBLESORTER_H
