//
// Created by Bori on 12/21/2020.
//

#include "dfs_evaluator.h"

void DFSEvaluator::Evaluate() {
  p.reset("DFS");
  EvaluateConstantNodesVaryingEdges();
  EvaluateConstantEdgesVaryingNodes();
  p.showReport();
}

void DFSEvaluator::EvaluateConstantNodesVaryingEdges() {
  for (int no_edges = kMinEdges; no_edges <= kMaxEdges; no_edges += kVarEdgesIncrement) {
    Operation op_var_edges = p.createOperation("DFS-varying edges", no_edges);
    Graph g = GenerateRandomGraph(kNoNodes, no_edges);
    g.Dfs(&op_var_edges);
  }
}

void DFSEvaluator::EvaluateConstantEdgesVaryingNodes() {
  for (int no_nodes = kMinNodes; no_nodes <= kMaxNodes; no_nodes += kVarNodesIncrement) {
    Operation op_var_nodes = p.createOperation("DFS-varying nodes", no_nodes);
    Graph g = GenerateRandomGraph(no_nodes, kNoEdges);
    g.Dfs(&op_var_nodes);
  }
}

Graph DFSEvaluator::GenerateRandomGraph(int no_nodes, int no_edges) {
  srand (time(NULL));
  Graph g(no_nodes);
  int no_inserted_edges = 0;
  while (no_inserted_edges < no_edges) {
    int n1 = rand() % no_nodes;
    int n2 = rand() % no_nodes;
    if (!g.HasEdge(n1, n2)) {
      g.AddEdge(n1, n2);
      no_inserted_edges++;
    }
  }
  return g;
}
