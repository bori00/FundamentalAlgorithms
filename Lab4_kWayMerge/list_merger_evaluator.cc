//
// Created by Bori on 11/1/2020.
//

#include "list_merger_evaluator.h"
#include "list_merger.h"
#include "list_merger_test.h"

void ListMergerEvaluator::EvaluateConstantN() {
  Profiler p("Constant N - Varying K");
  for (int k = kMinK; k <= kMaxK; k += kIncrementK) {
    for (int test = 0; test < kNoMeasurements; test++) {
      Operation op_comp = p.createOperation("comp", k);
      Operation op_assign = p.createOperation("assign", k);
      Operation op_pointer_assign = p.createOperation("pointer_assign", k);
      List<int> **lists = GenerateLists(kConstN, k, &op_assign, &op_pointer_assign);
      ListMerger<int> listMerger;
      for (int i = 0; i < k; i++) {
        listMerger.AddList(lists[i]);
      }
      List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
      assert(ListMergerTest::IsSorted(*result));
      cout << "Evaluated n = " << kConstN << " const, k = " << k << " test = " << test << endl;
      delete result;
    }
  }
  p.divideValues("comp", kNoMeasurements);
  p.divideValues("assign", kNoMeasurements);
  p.divideValues("pointer_assign", kNoMeasurements);
  p.showReport();
}

void ListMergerEvaluator::EvaluateConstantK(int k) {
  Profiler p("Constant K - Varying N");
  for (int n = kMinN; n <= kMaxN; n += kIncrementN) {
    for (int test = 0; test < kNoMeasurements; test++) {
      Operation op_comp = p.createOperation("comp", n);
      Operation op_assign = p.createOperation("assign", n);
      Operation op_pointer_assign = p.createOperation("pointer_assign", n);
      List<int> **lists = GenerateLists(n, k, &op_assign, &op_pointer_assign);
      ListMerger<int> listMerger;
      for (int i = 0; i < k; i++) {
        listMerger.AddList(lists[i]);
      }
      List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
      assert(ListMergerTest::IsSorted(*result));
      delete result;
      cout << "Evaluated n = " << n << ", k = " << k << " const,  test = " << test << endl;
    }
  }
  p.divideValues("comp", kNoMeasurements);
  p.divideValues("assign", kNoMeasurements);
  p.divideValues("pointer_assign", kNoMeasurements);
  p.showReport();
}

List<int> **ListMergerEvaluator::GenerateLists(int n, int k, Operation* op_assign, Operation*
op_pointer_assign) {
  auto** lists = (List<int>**) malloc(sizeof(List<int>*)*k);
  int size;
  for (int i = 0; i < k; i++) {
    if (i < k - 1) {
      size = rand() % (n - k + i) + 1;
    } else {
      size = n;
    }
    assert(size > 0);
    n -= size;
    int v[size];
    FillRandomArray(v, size, -10000, 10000, false, ASCENDING);
    lists[i] = new List<int>(v, size, op_assign, op_pointer_assign);
  }
  assert (n == 0);
  return lists;
}
