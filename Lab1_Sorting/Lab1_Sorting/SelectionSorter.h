#pragma once
#include "Sorter.h"

class SelectionSorter: public Sorter
{
public:
	void sort(int* a, int no_elements) override;
};
