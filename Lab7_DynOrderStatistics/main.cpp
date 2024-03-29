#include <iostream>
#include "os_tree.h"
#include "gtest/gtest.h"
#include "os_tree_evaluator.h"

using namespace std;

void demo11();

/**
 * @author Borbála Fazakas
 * @group 30422
 *
 * Task:
 * You are required to implement correctly and efficiently the management operations of an order
 * statistics tree: build tree, select and delete.
 *
 * Solution:
 * -- Build Tree
 * The constructor of the tree takes as an argument a number n, and build a perfectly balanced
 * tree containing n nodes with keys 1..n in a preorder way:
 * - for each subtree containing nodes l..r, the middle element m of the [l..r] interval is taken
 * as root, so the size difference between the remaining left interval [l..m-1] and right
 * interval [m+1..r] is
 *   --> 1, if the length of interval [l..r] is even
 *   --> 0, if the length of the interval [l..r] is dd
 * - the left subtree is constructed containing the nodes with keys in [l..m-1]
 * - the right subtree is constructed cntaining the nodes with keys in [m+1..r]
 * Similarly to the preorder traversal, because the extra computations take constant time per
 * node, this build tree operation is O(n).
 *
 * -- Select
 * Given that the OSTree is an augmented BST, in order to find the ith smallest element in the
 * tree we can rely on the following observation: all the elements of the left subtree of a node
 * are smaller than the data of the node, whch is in turn smaller than the data of all nodes in
 * the right subtree. Thus:
 * - if i is smaller than or equal to the size of the left subtree, then the ith smallest element
 * should be in the left subtree
 * - if i is equal to the size of the left subtree + 1, then the ith smallest element is held by
 * the root
 * - if i is larger than the size of the left subtree + 1, then the ith smallest element is in
 * the right subtree, and there it is the element with index i-size(left subtree)-1
 * Based on these rules, the selecion path can't be longer than the longest path from the root to
 * a leaf, which is the height of the tree. Given that originally we build a PBT with height lgn,
 * and deletion doesn't increase the height, the complexity of this operation o o(lgn).
 *
 * -- Delete
 * The delete operation in an OS Tree works similarly to the delete in BST, with one extra
 * instruction per node: for each node along the path of deletion, the size of the subtree rooted
 * at that node has to be decreased by 1. This is important to guarantee that the size fields
 * remaing consistent after deletion.
 * Given that deletion in a BST is O(h), and here we originally build a PBT with h=lgn, and the
 * height can never be increased through deletion and selection, the complexity of this operation
 * is O(lgn).
 *
 * -- Chart interpretations
 * To evaluate these operations in real life, trees of different n sizes between 100 and 10000 were
 * built, and on each of them n selections and deletions were performed.
 * - Build Tree
 * The charts show clearly, than building a tree takes linear time (in my implementation, 2
 * comparisons on data, 2 data assignments per node were performed).
 * - Deletion
 * Evaluating this chart is a little more complex, because a significant part of the operations
 * are in fact performed on pointers (counted seperately and siplayed on separate charts).
 * -> data assignments are performed on the deleted node, only if it has 2 children
 * -> pointer assignments are performed on the actually deleted node only
 * so these to operations are O(1) per deletion, so O(n) for n deletions.
 * -> pointer comparisons are performed on the node to delete and on the path from it to its
 * successor if it has children. So, this is in worst case O(lgn) per deletion, meaning O(nlgn)
 * per n deletions, but in practice it is much smaller, since in most cases the successor is not
 * needed or it is close to the node to delete
 * -> data comparisons are performed once per node along the path from the root to the node to
 * delete. This is worst case O(lgn), but the node to delete is a leaf only in ~half of the
 * cases, so in practice the average complexity is a little better. For n deletions, this results
 * in O(nlogn).
 * All in all, we can see that data comparisons determine the overall complexity of a deletion,
 * and what we can see on the chart corresponds to the expected O(nlogn) complexity (the charts
 * shows in fact ~2nlogn operations for n deletions).
 * - Selection
 * The selection is an interesting case for evaluation, because it doesn't require any data
 * assignments of comparisons: only sizes need to be computed(assigned) and compared. At each
 * node along the search path at most 2 comparisons take place and 1 computation, resulting in
 * ~2lgn operations, which corresponds to what we can see on the chart.
 */

int main(int argc, char *argv[]) {
  demo11();
  ::testing::InitGoogleTest(&argc, argv);
  OSTreeEvaluator::Evaluate();
  return RUN_ALL_TESTS();
}

void demo11() {
  Profiler p("ignore");
  Operation op_comp_select = p.createOperation("ignorecomp", 0);
  Operation op_assign_select = p.createOperation("ignoreassign", 0);
  Operation op_comp_delete = p.createOperation("ignorecompdelete", 0);
  Operation op_assign_delete = p.createOperation("ignoreassigndelete", 0);
  Operation op_pointer_comp_delete = p.createOperation("ignorecompdeletepointer", 0);
  Operation op_pointer_assign_delete = p.createOperation("ignoreassigndeletepointer", 0);
  Operation op_comp_build = p.createOperation("Build Comparisons", 0);
  Operation op_assign_build = p.createOperation("Build Assignments", 0);
  OSTree os_tree(11, &op_comp_build, &op_assign_build);
  cout << "------Original Tree" << endl;
  os_tree.PrettyPrint();
  cout << "------ Selected the 2nd element: " << os_tree.Select(2, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 2 (leaf)" << endl;
  os_tree.Delete(2, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
      &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 1st element: " << os_tree.Select(1, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 1 (one single child)" << endl;
  os_tree.Delete(1, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 7th element: " << os_tree.Select(7, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 9 (two children)" << endl;
  os_tree.Delete(9, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
  cout << "------ Selected the 4th element: " << os_tree.Select(4, &op_comp_select, &op_assign_select) << endl;
  cout << "------Delete 6 (root)" << endl;
  os_tree.Delete(6, &op_comp_delete, &op_assign_delete, &op_pointer_comp_delete,
                 &op_pointer_assign_delete);
  os_tree.PrettyPrint();
}