//
// Created by Bori on 10/24/2020.
//

#include <stdlib.h>
#include <algorithm>
#include "randomized_quick_select_test.h"

using namespace std;

int RandomizedQuickSelectTest::average_array_[] = {3, -7, 2, 10, -5, 9, 4, 12, 10, 10};
int RandomizedQuickSelectTest::sorted_array_[] = {-10, 0, 3, 7, 10, 23, 101, 103, 1000, 1500};
intRandomizedQuickSelectTest::inv_sorted_array_[] =
    {1002, 987, 540, 10, -24, -105, -900, -901, -901, -1000};

int *RandomizedQuickSelectTest::GetArrayWithContent(const int content[]) {
  int *result = (int *) malloc(sizeof(int) * kArrayLength);
  for (int i = 0; i < kArrayLength; i++) {
    result[i] = content[i];
  }
  return result;
}

bool RandomizedQuickSelectTest::CorrectSelectedElement(int *v, int no_elements, int index, int
selected_value) {
  sort(v, v + no_elements);
  return v[index] == selected_value;
}
