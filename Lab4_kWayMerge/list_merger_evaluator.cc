//
// Created by Bori on 11/1/2020.
//

#include "list_merger_evaluator.h"
#include "list_merger.h"
#include "list_merger_test.h"

ListMergerEvaluator::ListMergerEvaluator() : p_("ListMerger") {}

void ListMergerEvaluator::Evaluate() {
  p_.reset("Constant N, Varying K");
  EvaluateConstantN();
  p_.reset("Constant K, Varying N");
  EvaluateConstantK(k1);
  EvaluateConstantK(k2);
  EvaluateConstantK(k3);
  p_.createGroup("assign", GetOpName((char*) "assign_k=", k1), GetOpName((char*) "assign_k=", k2),
      GetOpName(
          (char*) "assign_k=",k3));
  p_.createGroup("comp", GetOpName((char*) "comp_k=", k1), GetOpName((char*) "comp_k=", k2), GetOpName((char*) "comp_k=",
                                                                                   k3));
  p_.createGroup((char*) "pointer_assign", GetOpName((char*) "pointer_assign_k=", k1), GetOpName
      ((char*) "pointer_assign_k=",k2), GetOpName((char*) "pointer_assign_k=",k3));
  p_.createGroup("total (not including pointer_assign)", GetOpName((char*) "total (not including pointer_assign) k=", k1), GetOpName((char*) "total (not including pointer_assign) k=", k2), GetOpName
  ((char*) "total (not including pointer_assign) k=",k3));
  p_.createGroup("total (including pointer_assign)", GetOpName((char*) "total (including pointer_assign) k=", k1), GetOpName((char*) "total (including pointer_assign) k=", k2), GetOpName
      ((char*) "total (including pointer_assign) k=",k3));
  p_.showReport();
}

void ListMergerEvaluator::EvaluateConstantN() {
  for (int k = kMinK; k <= kMaxK; k += kIncrementK) {
    for (int test = 0; test < kNoMeasurements; test++) {
      Operation op_comp = p_.createOperation("comp", k);
      Operation op_assign = p_.createOperation("assign", k);
      Operation op_pointer_assign = p_.createOperation("pointer_assign", k);
      List<int> **lists = GenerateLists(kConstN, k, &op_assign, &op_pointer_assign);
      ListMerger<int> listMerger;
      for (int i = 0; i < k; i++) {
        listMerger.AddList(lists[i]);
      }
      List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
      assert(ListMergerTest::IsSorted(*result));
      cout << "Evaluated n = " << kConstN << " const, k = " << k << " test = " << test << endl;
      delete result;
    }
  }
  p_.divideValues("comp", kNoMeasurements);
  p_.divideValues("assign", kNoMeasurements);
  p_.divideValues("pointer_assign", kNoMeasurements);
  p_.addSeries("total (not including pointer assign)", "comp", "assign");
  p_.addSeries("total (including pointer assign)", "total (not including pointer assign)",
      "pointer_assign");
  p_.showReport();
}

void ListMergerEvaluator::EvaluateConstantK(int k) {
  for (int n = kMinN; n <= kMaxN; n += kIncrementN) {
    for (int test = 0; test < kNoMeasurements; test++) {
      Operation op_comp = p_.createOperation(GetOpName((char*) "comp_k=", k), n);
      Operation op_assign = p_.createOperation(GetOpName((char*) "assign_k=", k), n);
      Operation op_pointer_assign = p_.createOperation(GetOpName((char*) "pointer_assign_k=", k),
          n);
      List<int> **lists = GenerateLists(n, k, &op_assign, &op_pointer_assign);
      ListMerger<int> listMerger;
      for (int i = 0; i < k; i++) {
        listMerger.AddList(lists[i]);
      }
      List<int>* result = listMerger.merge(&op_comp, &op_assign, &op_pointer_assign);
      assert(ListMergerTest::IsSorted(*result));
      delete result;
      cout << "Evaluated n = " << n << ", k = " << k << " const,  test = " << test << endl;
    }
  }
  p_.divideValues(GetOpName((char*) "comp_k=", k), kNoMeasurements);
  p_.divideValues(GetOpName((char*) "assign_k=", k), kNoMeasurements);
  p_.divideValues(GetOpName((char*) "pointer_assign_k=", k), kNoMeasurements);
  p_.addSeries(GetOpName((char*) "total (not including pointer_assign) k=", k),
               GetOpName((char*) "comp_k=", k),
               GetOpName((char*) "assign_k=", k));
  p_.addSeries(GetOpName((char*) "total (including pointer_assign) k=", k),
               GetOpName((char*) "total (not including pointer_assign) k=", k),
               GetOpName((char*) "pointer_assign_k=", k));
}

List<int> **ListMergerEvaluator::GenerateLists(int n, int k, Operation* op_assign, Operation*
op_pointer_assign) {
  auto** lists = (List<int>**) malloc(sizeof(List<int>*)*k);
  int size;
  for (int i = 0; i < k; i++) {
    if (n == k - i) {
      size = 1;
    } else {
      if (i < k - 1) {
        size = rand() % (n - k + i) + 1;
      } else {
        size = n;
      }
    }
    assert(size > 0);
    n -= size;
    int v[size];
    FillRandomArray(v, size, -10000, 10000, false, ASCENDING);
    lists[i] = new List<int>(v, size, op_assign, op_pointer_assign);
  }
  assert (n == 0);
  return lists;
}

char *ListMergerEvaluator::GetOpName(char *op_name, int k) {
  stringstream str;
  str << op_name << k;
  string result = str.str();
  char* result_char = (char*) malloc(sizeof(char) * (result.size() + 1));
  for (int i = 0; i < result.size(); i++) {
    result_char[i] = result[i];
  }
  result_char[result.size()] = '\0';
  return result_char;
}


