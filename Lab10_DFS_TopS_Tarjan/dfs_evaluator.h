//
// Created by Bori on 12/21/2020.
//

#ifndef LAB10_DFS_TOPS_TARJAN__DFS_EVALUATOR_H_
#define LAB10_DFS_TOPS_TARJAN__DFS_EVALUATOR_H_

#include "Profiler.h"
#include "graph.h"

class DFSEvaluator {
 public:
  void Evaluate();

 private:
  void EvaluateConstantNodesVaryingEdges();
  void EvaluateConstantEdgesVaryingNodes();

  static Graph GenerateRandomGraph(int no_nodes, int no_edges);

  // for evaluating constant nr. nodes, varying nr. edges case
  static const int kNoNodes = 100;
  static const int kMinEdges = 1000;
  static const int kMaxEdges = 5000;
  static const int kVarEdgesIncrement = 100;

  // for evaluating constant nr. edges, varying nr. nodes case
  static const int kNoEdges = 9000;
  static const int kMinNodes = 100;
  static const int kMaxNodes = 200;
  static const int kVarNodesIncrement = 10;

  Profiler p;
};

#endif //LAB10_DFS_TOPS_TARJAN__DFS_EVALUATOR_H_
