#include <iostream>
#include "selection_sorter.h"
#include "sorter_evaluator.h"
#include "gtest/gtest.h"
#include "bubble_sorter.h"
#include "insertion_sorter.h"
#include "heap_evaluator.h"


int main(int argc, char *argv[]) {
  HeapEvaluator heap_evaluator;
  heap_evaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
 * Task lab 2:
 * Implement build-heap with top-down and bottom-up method
 * and then evaluate and compare their performance.
 * Implement and exemplify heapsort.
 *
 * ----------------------------
 * Explanations and Conclusions about heap building
 * General heap building considerations
 * - for building a heap, I used an array, indexed from 0.
 * - the array is interpreted as a binary tree:
 * --> the left child of node at index i is the node at index 2 * i + 1
 * --> the right child of node at index i is the node at index 2 * i + 2
 * I implemented 2 different heap types based on their partial order relations:
 * --> MinHeap: the value of a node is smaller than those of its children
 * --> MaxHeap; the value of a node is larger than those of its children
 * Remark that the partial order relation is imposed by the IsCorrectRelation function
 * only, so new heaptypes can be easily added.
 *
 *
 * 1. Bottom-up approach
 * ----Short description----
 * This approach builds a heap from an array in the following way:
 * - first, the content of the array is copied into the heap's internal array
 * - for every node other than the leaves, in a bottom-up order, heapify() is called.
 * Heapify() ensures that the subtree of the heap rooted at the current node is a proper tree.
 * For this, it assumes that the left and the right subtrees are already proper trees. It ensures
 * the heap property for the entire subtree by sinking the root down as long as any of its
 * children is larger than it. For a heap of size k, heapify() takes at most log (k) comparisons,
 * because after each comparison the node goes down one level, and the height of the tree is log
 * (k).
 * The bottom-up order is important to make sure that when heapify() is called for node i, than
 * its  left and right subtrees, rooted at 2*i+1 and 2*i=2 are already heapified.
 * After the root being heapified, the heap building is finished.
 *
 * ----Complexity Analysis----
 * Thus, all in all we need to call heapify
 * n/2^2 times for the parents of the leaves, in trees of height 1
 * n/2^3 times for the "gradparents" of the leaves, for trees of height 2
 * n/2^4 times for trees of height 3
 * ...
 * once for a tree of length log(n)(which is the entire tree)
 * This sums up to 2n swaps(sinking steps) in worst case(worst case appears if tree root of any
 * subtree must be sunk down to the bottom).
 * At each swap 3 assignments are performed. At each possible sinking step 2 comaprisons are
 * performed.
 * Al in all, the heap building takes linear time with a > 1 multiplicative constant.
 *
 * ----Evaluate the charts in averag case----
 * What we can see on the chart corresponds to what we cave deduced based on computations:
 * - the total number of operations is ~6n
 * - the number of comparisons is ~2n
 * - the number of assignments is ~4n
 * So each of the metrics is growing linearly, as expected.
 *
 *
 * 2. Top-down approach
 * This approach os different in that it does not build the heap from a previously specified
 * array, but it is dynamical: elements can be inserted and removed from it anytime, and the heap
 * property is always ensured.
 * The two main operations are pop() and push().
 * At pop(), the top element(the max o min for maxheap and minheap) are removed from the heap.
 * The last element is placed on the top instead, and the size is decremented. Then, we apply
 * heapify() from the root to ensure the element placed at the root is at the correct position
 * and the heap property is still valid. Based on the previous analysis of heapify, this takes at
 * most log(n) swaps.
 * At push(), the size is incremented and the new array is inserted at the end. Then, because
 * this new element may violate the heap property, it must be bubbled up as long as the heap
 * relation does not hold for it and its parent. Similarly to heapify(), this takes <= log n swaps.
 * To build a heap with this interface we must apply push() for all elements.
 *
 * ----Complexity Analysis----
 * For the 1st element, log 1 = 0 swaps are needed at most
 * For the next 2 at most 1 swap
 * For the next 4 at most 2 swaps
 * ...
 * For the last n/2 at most log n swaps
 * This sums up to an O(n*logn) complexity.
 *
 * ----Evaluate the charts in average case----
 * Based on the average case chart we can only notice that the number of operations doesn't  grow
 * linearly, but the difference from a linear growth can be almost ignored: at small input sizes,
 * the number of operations is ~6n, and at larger input sizes its ~7n.
 *
 * ----------------------------------------------
 * Worst case analysis
 * For testing how the build-heap methods for max-heaps work in worst case, I generated ascending
 * arrays. Thus, for the bottom-up approach, each element is smaller than all of its children, so
 * it must be sunk to the bottom, and for the top-down approach each newly inserted element is
 * larger than all of its parents, so it must be bubbled up to the top. Thus, the maximum number
 * of operations is achieved.
 * (Remark that this is not the only worst case for build-heap method, but probably the only one
 * that can be easily generated, and which ensures that the worst-case scenario can be properly
 * analysed.)
 * Looking at the charts for te worst case, the difference between the linear bottom-up and the
 * nlogn top-down approach becomes much clearar than in the average case:
 * whereas for n=10000 the bottom-up approach takes ~60000 operations, the top-down one takes
 * 450000.
 *
  * -------------------------------------
 *
 * COMPARISON AND CONCLUSIONS
 *
 * All in all, in complexity mathematically we can express a significant difference, but the
 * actual difference in the running time of the top-down and bottom-up approach is almost
 * insignificant. The bottom-up approach is slightly faster, but in most cases the difference may
 * not matter.
 * On the other hand, the top-down approach has a major advantage: it's dynamic, we don't need to
 * know the size of the heap in advance. It can be seen as a data structure which supports
 * extracting the min/max in constant time and inserting a new element in logn time, which can be
 * exploited in amazingly in several applications, in particular, for optimisation problems(heaps
 * are a frequently used element of greedy solutions, for example).
 * However, the bottom-up approach is certainly the best option to choose if we want to use it
 * for sorting: in this case, the array is anyway fixed, dynamical insertion is an unnecessary
 * feature.
 *
 * To understand why the top-down approach is slower despite the very similar technique, we
 * should remark that when we bubble elements up, the majority of the elements is far away from
 * the "target"(=root). Half of the elements are leaves, and for each of them we need logn time,
 * then n/2 elements are parents of the leaves for which we need log(n/2) time, etc. On the other
 * hand, for the bottom-up approach all these "highly populated" levels are really close to the
 * target, which is the lowest level. Thus, for most of the elements heapify will be quick, it
 * will tak emore time only for the elements close to the root.
 */


/**
 *  Task: implement 3 direct sorting methods:
 * 1. Bubble Sort
 * 2. Insertion Sort
 * 3. Selection Sort
 * and then evaluate and compare their performance.
 *
 * ----------------------------
 * Explanations and Conclusions
 *
 * ALGORITHM ANALYSIS
 * 1. Bubble Sort
 * ----Short Description----
 * This sorting methods iterates at most n-1 times through the array
 * and it guarantees that after the i-th iteration on the rightmost i
 * places we'll have the i largest elements of the array in ascending order.
 * To achieve this, in each iteration the first n-i-1 elements of the array
 * are scanned and adjacent elements which are in the wrong order are swapped.
 * To optimise the algorithm, I exploited the fact that if at iteration i
 * no exchange was made, than the first n-i elements of the array are sorted too
 * meaning that the array is fully sorted, so the algorithm can stop.
 *
 * ----Complexity Analysis----
 * a) Average Case
 * --Comparisons--
 * In average case, when the algorithm does not stop after an iteration
 * without an exchange, bubble sort requires n*(n-1)/2 comparisons:
 * --> n-1 + n-2 + n-3 + ... + 1
 * In reality, we can expect the algorithm to stop a few iterations before the n-1th one.
 * --Assignments--
 * The number of assignments = 3 * number of swaps, where the number of swaps is
 * equal to the number of inversions in the array, which is ~ n*(n-1)/4 (= half
 * of the number o pairs) in average case, so the number of assignments is
 * ~ (3/4)*n*(n-1).
 * --Evaluate charts--
 * These computations correspond to the charts:
 * - for size = 100,
 * the algorithm required 4867 ~ 4950 comparisons and 6969 ~ 7425 assignments
 * - for size = 10000,
 * the algorithm required 49,985,238 ~ 49,995,000 comparisons
 * and 74,959,339 ~ 74,992,500 assignments
 *
 * b) Worst Case: inversely sorted input array
 * At the i-th iteration, the algorithm will "bubble" the i-th largest element
 * from the 0th index to the (n - i)th one, in (n-i) swaps.
 * In worst case, the number of comparisons will be the same as specified above.
 * The number of swaps will be the same as the number of comparisons, since the
 * i-th largest element will need to be swapped with all elements that are smaller than it.
 * --> n*(n-1)/2 assignments and comparisons
 *
 * c) Best Case: sorted input array
 * It takes only one iteration(n-1 comparisons and 0 assignments) for the algorithm
 * to detect that the array is sorted, and then the algorithm will stop.
 *
 * ----Stability----
 * Bubble Sort is a stable algorithm, because the relative order of wo elements can
 * change only if they are swapped when they become adjacent, but the swaps are conditioned
 * by strong inequality, so the order of equal elements never changes.
 *
 * -------------------------------------
 *
 * 2. Insertion Sort
 * ----Short Description----
 * The algorithm requires n-1 iterations, and after the i-th one the
 * smallest i elements of the array will be on the leftmost i places,
 * sorted in the correct order.
 * To achieve this, at the i-th iteration:
 * - the position j at which the v[i] element should be inserted in the sorted array (so that the
 * array remains sorted after the insertion) is found using binary search, which takes 2* log i
 * comparisons
 * - the elements [j .. i-1] are shifted to the right, taking i-j assignments
 * - v[i] is placed at position j
 *
 * ----Complexity Analysis----
 * --Comparisons--
 * The binary search always requires up to 2*Summalogk =~ 2*n*logn comparisons.
 * Remark that another implementation of insertion sort would be to search for the
 * index where the value needs to be inserted linearly. With this approach, on average
 * the algorithm would need i/2, in worst case i and in best case 0 comparisons.
 * --Assignemnts--
 * The number of assignments(shifts) depends on the case.
 * a) Average Case
 * In a general case we expect the index where we want to insert to be half of i.
 * Thus, the number of shifts will be Summa i/2 = n*(n-1)/4. Additionally, if the
 * insertion_index is not the same as i, then 2 extra assignments are needed,
 * so all in all we need ~n*(n-1)/4+2n assignments
 * --> ~ 2*n*logn comparisons, n*(n-1)/4+2n assignments
 * --Evaluate charts--
 * These computations correspond to the charts:
 * - for size = 100, the algorithm required 998 ~ 1328 comparisons and 2514 ~ 2675 assignments
 * - for size = 10000, the algorithm required 229,465 ~ 265,754 comparisons
 * and 25,006,419 ~ 25,017,500 assignments
 *
 * b) Best case: sorted input array
 * Insertion_index is equal to i, so no assignments are required.
 *
 * c) Worst case: inversely sorted input array
 * The number of shifts goes up to n*(n-1)/2, because the element on index i will
 * always be inserted at index 0.
 *
 * ----Stability----
 * Insertion Sort is a stable algorithm, because the elements are inserted in the
 * sorted array from the left to the right, and whenever the value v needs to
 * be inserted in the sorted array, it is inserted after the rightmost value equal to v.
 * Remark that, to achieve this, a small modification in the binary search was needed.
 *
 * -------------------------------------
 *
 * 3. Selection Sort
 * ----Short Description----
* The algorithm requires n-1 iterations, and after the it-th one the
 * smallest i elements of the array will be on the leftmost i places,
 * sorted in the correct order.
 * To achieve this, at the i-th iteration:
 * - the smallest element in the array [i-1... n-1] is searched linearly, taking n-i+1 comparisons
 * - if the smallest element is not the i-th one, then it is swapped with the i-th one.
 *
 * ----Complexity Analysis----
 * --Comparisons--
 * For selection sort, the number of comparisons is the same independently from the
 * case: Summa n-i+1 = n*(n-1)/2 comparisons are needed.
 * --Assignments--
 * The number of assignments is ~3n-3(n swaps)(minus 3*the number of elements which were originally
 * on the correct position). Thus, in the best case, when the array is originally sorted,
 * the number of assignemnts is 0.
 * --> n*(n-2)/2 comparisons, 3n assignments in average case
 * --Evaluate Charts for Average Case--
 * - for size = 100, the algorithm required 4950 = 4950 comparisons and 286 ~ 300 assignments
 * - for size = 10000, the algorithm required 49,995,000 = 49,995,000 comparisons and
 * 29969 ~ 30000 assignments
 *
 *
 * ----Stability----
 * Selection Sort is not stable. Consider the following example:
 * v = [5(1) 5(2) 2]
 * After iteration 1: v = [2 5(2) 5(1)] --> 5(1) was swapped with the minimum value = 2
 * After iteration 2: v = [2 5(2) 5(1)] --> no further swaps are needed
 * --> The order of 5(1) and 5(2) was not preserved.
 * Remark that selection sort could be made stable if instead of swapping the minimum element
 * with the i-th one we would shift the elements [i min_index-1] to the right and then set the i-th
 * to the minimum one. This approach would not ruin the overall complexity of the algorithm,
 * but it would significantly increase the number of assignments.
 *
 * -------------------------------------
 *
 * COMPARISON AND CONCLUSIONS
 * All in all, despite each algorithm being )(n^2),
 * Insertion Sort seems to outperform the other algorithms in the average case.
 * This can be explained by the following remarks:
 * - it is not based on swaps(=3 assignments), but on shifts(=1 assignment)
 * - the number of comparisons is actually not quadratic, but ~n*logn
 *
 * In the worst case, Insertion Sort and Selection Sort perform equally well(or badly),
 * but Selection Sort takes more comparisons and Insertion Sort more assignments.
 *
 * However, with this implementation of insertion sort(with the binary search),
 * ~n*logn comparisons are needed even in the best case. Thus, in the best case
 * Bubble Sort, which takes n-1 comparisons and 0 assignments is clearly better.
 * Remark that insertion sort would perform equally well with the other
 * (previously described) implementation.
 *
 * Other considerations:
 * - if for the input type the comparison is heavier than the assignment, then I would
 * favor Insertion Sort(with n*logn comparisons instead of n^2).
 * - if assignments are more heavy, it may be worth to consider selection sort, despite
 * the bad results in the charts, because it requires only 3*n assignments, compared to
 * the quadratic quantities in the other algorithms
 */