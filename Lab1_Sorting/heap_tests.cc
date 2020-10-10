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

TEST_F(HeapTest, BuildHeap_BottomUp_MaxHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_BottomUp_MaxHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_BottomUp_MaxHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_BottomUp_MinHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_BottomUp_MinHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_BottomUp_MinHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(v, kArrayLength, Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MaxHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MaxHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MaxHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(Heap::HeapType::kMaxHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MinHeap_AverageArray) {
  int *v = GetAverageArray();
  Heap h(Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MinHeap_SortedArray) {
  int *v = GetSortedArray();
  Heap h(Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

TEST_F(HeapTest, BuildHeap_TopDown_MinHeap_InvSortedArray) {
  int *v = GetInverselySortedArray();
  Heap h(Heap::HeapType::kMinHeap, &op_comp, &op_assign);
  for (int i = 0; i < kArrayLength; i++) {
    h.push(v[i]);
  }
  EXPECT_TRUE(HeapTest::isHeap(h));
}

