#include "demo_tarjan.h"
#include "demo_topological_sort.h"
#include "demo_dfs.h"
#include "dfs_evaluator.h"

using namespace std;

/**
 * @author Fazakas Borbala
 * @group 30422
 *
 * Task:
 * Implement depth first search, topological sort and Tarjan's algorithm for strongl
 * connected components.
 * Evaluate the performance of dfs.
 *
 * Solution:
 * -- DFS:
 * Depth first search builds a spanning forest of the original graph such that while discovering
 * edges it tries to "go as far as possible".
 * The algorithm sets the nodes d=discovery time and f=finishing time in the depth first search
 * procedure's order, and modifies their colors:
 * - WHITE = unvisited node
 * - GRAY - discovered node, whose children are not all finished yet
 * - BLACK - finished node. All of its children are finished alreday.
 * The visit of one node n looks as follows:
 * - it sets its color to gray, and the discovery time to the current time. It then increments
 * the  current time.
 * - for any neighbor c of n, not yet visited (meaning that there exists an edge n-->c, and the
 * color or c is white), dfs visits c.
 * - dfs finished the visit of n, sets its color to black, the finishing time to the current time
 * and then increments the current time.
 * Since there may be some nodes unreachable from the starting point of dfs, multiple restarts
 * may be needed, thus dfs results in a forest not a simple tree.
 * Since all edges are visited exactly once (set gray once, set black once), and all edges are
 * checked exactly once, dfs has a complexity O(V + E).
 *
 * -- Topological Sort
 * The idea behing the algorithm implemented for topological sort is that in dfs the visit of any
 * node is guaranteed to be finished before the visit of any of its ancestors. This means that,
 * if (u, v) is a tree edge or forward edge in dfs, f(u) > f(v)
 * On the other hand, if (u, v) is a cross edge, that obviously v has already been visited
 * (otherwise the edge would become a tree edge), so f(u) > f(v).
 * Remark that back edges are not allowed in graph for which the topological ordering is
 * required, because a cycle would mean "a has to be before b" and "b has to be before a", which
 * is a contradiction.
 * So, for any edge (u, v) in a graph whose nodes can be topologically sorted, we have f(v) < f(u).
 * Based on the above statements, we can use a simple dfs for topological sort and insert the
 * nodes in the topologically ordered array in reverse order of finishing time.
 * Similarly to dfs, this implementation of topological sort is O(E + V).
 *
 * -- Tarjan's algorithm for strongly connected components
 * The following description is not a proof, just the intuition behind it.
 * Tarjan's algorithm is based on the following remarks:
 * - in a SCC, between nodes a and b there must be directed path a-->b and b-->a, so there must
 * ba circle containing a and b.
 * - in a graph, only back-edges are closing circles
 * Thus, Tarjan's algorithm aims to detect back edges and thus the cycles. To do so, it uses a
 * simple dfs and it assigns to each node n two values:
 * - d = discovery time in dfs
 * - low = the lowest from the discovery times of any nodes reachable from n through n's dfs
 * subtree (On the path from n to that node all the nodes should be tree edges, except the last
 * one, which is a back edge. Thus, this implies the existence of a circle between n and the node
 * with the lowest discovery time reachable from n through is subtree).
 * Additionally, to know which nodes are on the path from the dfs-root to n or possible
 * successors of n which are in the same scc as n, the algorithm maintains a stack, and an
 * attribute of the nodes showing whether they are on the stack or not.
 * Using this stack, we can differentiate back-edges from cross-edges, required to compute the
 * low value of a node.
 * The root of a scc is considered to be the node first discovered by dfs.
 * We can remark that:
 * - if n.d > n.low, it means that there is a path from n to an ancestor of n in the dfs tree
 * through n's subtree. We know that there must be a path from the ancestor to n, so we have
 * detected a cycle containing that ancestor and n. These two nodes should be in the same scc, so
 * n is not the root of a scc.
 * - if n.d = n.low, then no ancestor is reachable from any of n's successors through its subtree
 * . This means, that this node is the root of a scc. This scc contains all successor of
 * n from which n is reachable. These nodes are in fact the ones still on the stack, and above n
 * (including n). When n is detected as a root a scc, all the nodes in the same scc should be
 * removed from the stack, and marked as belonging to one scc.
 * Similarly to dfs, Tarjan's algorithm also is O(V + E).
 *
 * Chart analysis:
 * I analyised the complexity of dfs using the profiler, and the resulting charts correspond to
 * the expectations: the number of operations performed for dfs is linear both in terms of nodes
 * and edges based on the chart, meaning that the algorithm's complexity is indeed O(E + V).
 */

int main() {
  Demo_Dfs1();
  Demo_Dfs2();
  Demo_Dfs3();
  Demo_TopSort1();
  Demo_TopSort2();
  Demo_TopSort3();
  Demo_Tarjan1();
  Demo_Tarjan2();
  Demo_Tarjan3();

  DFSEvaluator evaluator;
  evaluator.Evaluate();
  return 0;
}