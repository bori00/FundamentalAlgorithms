//
// Created by Bori on 12/5/2020.
//

#include "kruskal_evaluator.h"
#include "graph.h"

const char* KruskalEvaluator::sort_op_name = "sorting";
const char* KruskalEvaluator::make_set_op_name = "make set";
const char* KruskalEvaluator::find_set_op_name = "find set";
const char* KruskalEvaluator::union_op_name = "union";
const char* KruskalEvaluator::other_op_name = "other operations";

void KruskalEvaluator::Evaluate() {
  Profiler p("Kruskal Evaluation");
  for (int size = kMinGraphSize; size <= kMaxGraphSize; size+=kStepSize) {
    Operation op_sort = p.createOperation(sort_op_name, size);
    Operation op_make_set = p.createOperation(make_set_op_name, size);
    Operation op_find_set = p.createOperation(find_set_op_name, size);
    Operation op_union = p.createOperation(union_op_name, size);
    Operation op_other = p.createOperation(other_op_name, size);
    for (int test = 0; test < kNoRepetitions; test++) {
      Graph g = Graph::GenerateRandomGraph(size);
      g.Kruskal(&op_sort, &op_make_set, &op_find_set, &op_union, &op_other);
    }
    cout << "Evaluated size " << size << endl;
  }
  p.divideValues(sort_op_name, kNoRepetitions);
  p.divideValues(make_set_op_name, kNoRepetitions);
  p.divideValues(find_set_op_name, kNoRepetitions);
  p.divideValues(union_op_name, kNoRepetitions);
  p.divideValues(other_op_name, kNoRepetitions);
  p.addSeries("total_op1", sort_op_name, union_op_name);
  p.addSeries("total_op2", "total_op1", make_set_op_name);
  p.addSeries("total_op3", "total_op2", find_set_op_name);
  p.addSeries("total_op", "total_op3", other_op_name);
  p.createGroup("All Operations", sort_op_name, make_set_op_name, find_set_op_name,
      union_op_name, other_op_name);
  p.showReport();
}
