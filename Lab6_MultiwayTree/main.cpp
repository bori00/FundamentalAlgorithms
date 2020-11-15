#include <iostream>
#include "parent_array_multiway_tree.h"
#include "multiway_tree.h"
#include "binary_rep_multiway_tree.h"

using namespace std;

void demo(int parents[], int no_nodes);

/**
 * @author Borbala Fazakas
 * @Group 30422
 *
 * Task: implement linear time transformations between several representation of a multi-way tree
 * T1: Transformation from parent array representation to multi-way tree representation
 * T2: Transformation from multiway tree representation to binary tree representation
 *
 * ----- Solutions:
 *
 * Representations:
 * Multi-way tree representation is based on nodes with a data field and a variable number of
 * pointers to children nodes. The tree objects consists of a pointer to the root.
 * Binary-tree representation is based on nodes with a data field and two pointers: one to the
 * first-child and one to the first-sibling. The tree objects consists of a pointer to the root.
 *
 * Remark:
 * "On the surface", the nodes are indexed from 1, and a missing parent (for the root) is marked
 * as -1. However, in the background, nodes are indexes from 0, in order to avoid unnecessary
 * memory.
 *
 * T1
 * -- Algorithm
 * In order to transform a parent-array into a traditional multi-way tree representation, I
 * applied the following algorithm:
 * - in the first iteration, n nodes are instantiated, and pointers to them are stored in an
 * array such that the pointer to the node with data i is at index i. The number of children is
 * set to 0 for each node. --> O(n)
 * - in the second iteration on the parent array, I counted how many children each node has and
 * identified the index. If parent of node i is p[i], then the number of children of p[i] is
 * increased by 1, for all i between 0 and n-1 --> O(n)
 * - in the third iteration, space for the pointer to the children of each node is allocated,
 * based on the previously counted number of children for each node. --> O(n)
 * - in the fourth iteration, for each child-parent relationship(i - p[i]) represented by the
 * parent array, I added to node at index p[i] a new child pointer to node at index i. In the
 * meantime I kept track of how many children of node p[i] were already added, so that I knew
 * immediately on which index a child needs to be inserted. --> O(n).
 * --Analysis
 * As shown in the above description, the algorithm consists of four iterations over the n
 * nodes, one after the other, so the algorithm is linear. However, we should remark that some
 * additional memory was used in order to achieve this complexity:
 * - one array of pointer to the nodes. This array is the key of making the algorithm linear: due
 * to this array, a parent-child relationship can be immediately processed, vecause we can access
 * and update the node p[i] and i in constant time based on their index in the array. Thus, no
 * searching is required.
 * - one array of integers counting the children which were already added to a particular node.
 * This was required for the ste when we needed to insert a new child, because we had to know
 * which is the next empty slot where the pointer to it can be saved.
 *
 * T2
 * -- Algorithm
 * In order to convert a tree in multy-way format to binary format, I used a postorder traversal
 * of the nodes:
 * - for each multi-way node I in the tree, I assumed its right sibling J is already
 * converted to a binary-format, and thus a pointer to it is provided
 * - before converting itself, I first converted all subtrees rooted at its children, from the
 * right to left to binary format (The right to left order is important, because this way I
 * could indeed guarantee that when a subtree rooted at node i is converted, its right sibling j
 * is already converted.).
 * - after having all of its children converted, I simply memorised the pointer to its left-most
 * child as its first-child, and together with the already provided first-sibling pointer I
 * instantiated a binary node for the original multi-way one.
 * Thus, by doing this procedure for the root actually the whole tree is converted in a postorder
 * way. Remark that for nodes with no right-sibling I stored nullptr in the corresponding field.
 * -- Analysis
 * As mentioned before, this approach is very similar to a simple post-order traversal, which is
 * well-known a linear algorithm. Indeed, if we analyse this convertion, we can remark that each
 * node is processed exactly once (despite of the several returns to the function call in which
 * it was the root of the subtree), after all of its children were processed, and the processing
 * consists of a simple instantiation of a binary node. Thus, the algorithm is linear.
 * Regarding space, this approach doesn't require any explicitly instantiated memory, but some
 * additional memory is used for the stack due to the recursive calls: at each point if node N is
 * currently processed, then the data of the nodes along the path from the root to N is on the
 * stack. For a tree of length h, the maximum size of the stack is h * size of data for
 * processing one node. This extra memory was necessary to store the parent-child relationships.
 */

int main() {
  int parents_1[9] = {2, 7, 5, 2, 7, 7, -1, 5, 2};
  cout << "--------------Tree 1--------------" << endl;
  demo(parents_1, 9);

  int parents_2[10] = {9, -1, 7, 2, 2, 7, 2, 2, 3, 2};
  cout << "--------------Tree 2--------------" << endl;
  demo(parents_2, 10);

  int parents_3[6] = {-1, 1, 2, 3, 4, 5};
  cout << "--------------Tree 3--------------" << endl;
  demo(parents_3, 6);

  int parents_4[5] = {3, 3, -1, 3, 3};
  cout << "--------------Tree 4--------------" << endl;
  demo(parents_4, 5);

  int parents_5[8] = {2, 3, 8, 5, 6, 8, 8, -1};
  cout << "--------------Tree 5--------------" << endl;
  demo(parents_5, 8);
  return 0;
}

void demo(int parents[], int no_nodes) {
  ParentArrayMultiwayTree p_tree(parents, no_nodes);
  cout << "---Parent array representation:" << endl;
  p_tree.Print();
  MultiwayTree m_tree(p_tree);
  cout << "---Multiway tree representation:" << endl;
  m_tree.PrettyPrint();
  BinaryRepMultiwayTree b_tree(m_tree);
  cout << "---Binary tree representation:" << endl;
  b_tree.PrettyPrint();
}