#include "gtest/gtest.h"
#include "list_merger_evaluator.h"

using namespace std;

int main(int argc, char *argv[]) {
  ListMergerEvaluator list_merger_evaluator;
  list_merger_evaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
 * Task:
 * implement an algorithm to merge k sorted lists with a total of n elements into one single sorted
 * list. The algorithm's complexity must be O(nlogk).
 *
 * Solution:
 * The solution is similar to the one used for merging two arrays.
 * Let's assume we have the smallest i elements of the lists sorted already and places in the
 * final list in the correct order. Then, we store in a minheap the smallest remaining element of
 * each list. So the next element that needs to be inserted in the final list is the smallest
 * element of the heap. After inserting this one, to find the next one we may need to consider
 * the element following after this one in its original array.
 * Algorithm:
 * 1. build a minheap with the (current) smallest elements of each array. Instead of just the
 * data, store pointers to nodes in the heap, each node containing the actual data and a pointer to
 * the element following this one in its original list.  This results in a heap of k elements, so the
 * build heap procedure is O(k) (we apply the bottom-up approach), and each operation(insert, pop)
 * is O(logk).
 * 2. As long as the heap is not empty:
 *    2.a. Remove the smallest element from the heap (O(log k))
 *    2.b. Insert in the heap the element following after this one in the original array (O(logk))
 *    2.c. Insert the element at the end of the final list ((O(1))
 * 3. The final list is returned (O(1))
 *
 * Remark that for each element only one Node object is created, and then only the poiunters are
 * modified. So, at the end, the original lists are destroyed, but memory usage is kept at minimum.
 * As a consequence, the number of assignments is always equal to n, the number of elements, but
 * the number os pointer assignments is quite large. In a general case, pointer assignments are
 * not such a heavy operation as copying an object, so I counted these separately. However, in
 * this case they contribute significantly to the total running time, so in one of the charts
 * they are counted in too.
 *
 * As we can see, the build heap procedure's complexity is O(log k) and then n-k pieces of
 * insertions and pops are needed, each of complexity O(logk), so this sums up to O(nlogk)
 *
 * Interpretation of charts
 * I evaluated the performance of the algorithm in two cases:
 * 1. N is varying bwteen 100 and 10000, with an increement of 100, k is 5, 10 and then 1000
 * Given that the complexity of the algorithm is linear n terms of N, the functions drawn are all
 * linear.
 * 2. K is varying bwteen 10 and 500 with an increment of 10, and n is set to 10000
 * The complexity is logarithmic in terms of k, so the curves drawn show an logarithmic function.
 * These observations correspond to our computations that the total complexity is O(nlogk).
 * However, we should remark that the hidden multiplicative constants are quite large.
 */