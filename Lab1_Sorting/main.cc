#include <iostream>
#include "selection_sorter.h"
#include "sorter_evaluator.h"
#include "gtest/gtest.h"
#include "bubble_sorter.h"
#include "insertion_sorter.h"

/**
 * Task: implement 3 direct sorting methods:
 * 1. Bubble Sort
 * 2. Insertion Sort
 * 3. Selection Sort
 * and then evaluate and compare their performance.
 */

int main(int argc, char *argv[]) {
  SorterEvaluator sorterEvaluator;
  SelectionSorter selectionSorter;
  sorterEvaluator.AddSorter(&selectionSorter);
  BubbleSorter bubbleSorter;
  sorterEvaluator.AddSorter(&bubbleSorter);
  InsertionSorter insertionSorter;
  sorterEvaluator.AddSorter(&insertionSorter);
  sorterEvaluator.Evaluate();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/**
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