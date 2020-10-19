//
// Created by Bori on 10/13/2020.
//

#include <iostream>
#include <assert.h>
#include "heap_evaluator.h"
#include "heap.h"

const char *HeapEvaluator::kTopDownAssignmentName = "top-down-assignment";
const char *HeapEvaluator::kTopDownComparisonName = "top-down-comparison";
const char *HeapEvaluator::kBottomUpAssignmentName = "bottom-up-assignment";
const char *HeapEvaluator::kBottomUpComparisonName = "bottom-up-comparison";
const char *HeapEvaluator::kBottomUpOperationName = "bottom-up";
const char *HeapEvaluator::kTopDownOperationName = "top-down";

// These are not used for evaluation.
Profiler ignore_p("ignore");
Operation ignore_op_assign = ignore_p.createOperation("ignoreA", 1);
Operation ignore_op_comp = ignore_p.createOperation("ignoreC", 1);

HeapEvaluator::HeapEvaluator() : p_("heap-building") {}

void HeapEvaluator::Evaluate() {
  EvaluateAverageCase();
  EvaluateWorstCase();
}

void HeapEvaluator::EvaluateAverageCase() {
  EvaluateCase(kAverageCaseNoTests, UNSORTED, "AverageCase");
}

void HeapEvaluator::EvaluateWorstCase() {
  EvaluateCase(1, ASCENDING, "WorstCase");
}

void HeapEvaluator::EvaluateCase(int no_tests, int order, const char *title) {
  p_.reset(title);
  int v[kMaxArraySize];
  for (int size = kMinArraySize; size <= kMaxArraySize; size += kStepSize) {
    for (int test = 0; test < no_tests; test++) {
      FillRandomArray(v, size, 1, INT_MAX, false, order);
      cout << "evauluate case " << order << " size " << size << ", test nr. " << test << endl;
      EvaluateBottomUpHeapBuilding(v, size);
      EvaluateTopDownHeapBuilding(v, size);
    }
  }
  p_.divideValues(kBottomUpComparisonName, no_tests);
  p_.divideValues(kTopDownComparisonName, no_tests);
  p_.divideValues(kBottomUpAssignmentName, no_tests);
  p_.divideValues(kTopDownAssignmentName, no_tests);
  p_.createGroup("Assignments", kBottomUpAssignmentName, kTopDownAssignmentName);
  p_.createGroup("Comparisons", kBottomUpComparisonName, kTopDownComparisonName);
  p_.addSeries(kBottomUpOperationName, kBottomUpComparisonName, kBottomUpAssignmentName);
  p_.addSeries(kTopDownOperationName, kTopDownComparisonName, kTopDownAssignmentName);
  p_.createGroup("Total", kBottomUpOperationName, kTopDownOperationName);
  p_.showReport();
}

void HeapEvaluator::EvaluateBottomUpHeapBuilding(int *v, int size) {
  Operation op_assign = p_.createOperation(kBottomUpAssignmentName, size);
  Operation op_comp = p_.createOperation(kBottomUpComparisonName, size);
  Heap h(v, size, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
}

void HeapEvaluator::EvaluateTopDownHeapBuilding(int *v, int size) {
  Operation op_assign = p_.createOperation(kTopDownAssignmentName, size);
  Operation op_comp = p_.createOperation(kTopDownComparisonName, size);
  Heap h(Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  for (int i = 0; i < size; i++) {
    h.Push(v[i]);
  }
}