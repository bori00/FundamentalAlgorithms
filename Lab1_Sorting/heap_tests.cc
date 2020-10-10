//
// Created by Bori on 10/10/2020.
//

#include <iostream>
#include "gtest/gtest.h"
#include "heap_test.h"
#include "Profiler.h"

using namespace std;

static Profiler ignorePHeap("ignore");
static Operation op_comp = ignorePHeap.createOperation("op_comp", 0);
static Operation op_assign = ignorePHeap.createOperation("op_assign", 0);

TEST_F(HeapTest, MaxHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, MaxHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, MaxHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, MinHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, MinHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, MinHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}
