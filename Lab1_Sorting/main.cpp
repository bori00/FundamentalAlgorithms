#include <iostream>
#include "SelectionSorter.h"

int main(int argc, char* argv[]) {
    SelectionSorter selectionSorter;
    int* v = (int*) malloc(sizeof(int)*10);
    selectionSorter.sort(v, sizeof(v) / sizeof(v[0]));
    return 0;
}