//
// Created by Bori on 10/6/2020.
//

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cassert>
#include "sorter_evaluator.h"
#include "sorter_test.h"

using namespace std;

#define MAX_SERIES_NAME_LENGTH 50

SorterEvaluator::SorterEvaluator() : p_("sorting") {
  no_sorters_ = 0;
}

void SorterEvaluator::Evaluate() {
  EvaluateAverageCase();
  EvaluateBestCase();
  EvaluateWorstCase();
}

void SorterEvaluator::AddSorter(Sorter *sorter) {
  if (no_sorters_ == kMaxNoSorters) {
    cerr << "Max number of sorters_ exceeded";
    exit(1);
  }
  sorters_[no_sorters_] = sorter;
  no_sorters_++;
}

void SorterEvaluator::EvaluateWorstCase() {
  EvaluateCase(1, DESCENDING, "WorstCase");
}

void SorterEvaluator::EvaluateBestCase() {
  EvaluateCase(1, ASCENDING, "BestCase");
}

void SorterEvaluator::EvaluateAverageCase() {
  EvaluateCase(kAverageCaseNoTests, UNSORTED, "AverageCase");
}

void SorterEvaluator::EvaluateCase(int no_tests, int order, const char *title) {
  p_.reset(title);
  int v[kMaxArraySize];
  int u[kMaxArraySize];
  for (int size = kMinArraySize; size <= kMaxArraySize; size += kStepSize) {
    for (int test = 0; test < no_tests; test++) {
      FillRandomArray(v, size, INT_MIN / 2, INT_MAX / 2, false, order);
      for (int i = 0; i < no_sorters_; i++) {
        memcpy(&u, &v, size * sizeof(v[0]));
        cout << "evauluate case " << order << " size " << size << ", test nr. " << test << " sorter nr. " << i << endl;
        sorters_[i]->Sort(u, size, p_);
        assert(SorterTest::ArrayIsSorted(u, size));
      }
    }
  }
  for (int i = 0; i < no_sorters_; i++) {
    p_.divideValues(sorters_[i]->GetCompOpName(), no_tests);
    p_.divideValues(sorters_[i]->GetAssignOpName(), no_tests);
    p_.addSeries(sorters_[i]->GetSorterName(), sorters_[i]->GetCompOpName(), sorters_[i]->GetAssignOpName());
  }
  //CreateProfilerGroups();
  p_.showReport();
}

void SorterEvaluator::CreateProfilerGroups() {
  CreateProfilerAssignGroup();
  CreateProfilerCompGroup();
  CreateProfilerTotalGroup();
}

void SorterEvaluator::CreateProfilerTotalGroup() {
  char **members = (char **) malloc(sizeof(char *) * kMaxNoSorters);
  for (int i = 0; i < kMaxNoSorters; i++) {
    if (i < no_sorters_) {
      members[i] = (char *) malloc(sizeof(char) * MAX_SERIES_NAME_LENGTH);
      strcpy(members[i], sorters_[i]->GetSorterName());
    } else {
      members[i] = 0;
    }
  }
  p_.createGroup("Total", members[0], members[1], members[2], members[3], members[4], members[5],
                 members[6], members[7], members[8], members[9]);
}

void SorterEvaluator::CreateProfilerCompGroup() {
  char **members = (char **) malloc(sizeof(char *) * kMaxNoSorters);
  for (int i = 0; i < kMaxNoSorters; i++) {
    if (i < no_sorters_) {
      members[i] = (char *) malloc(sizeof(char) * MAX_SERIES_NAME_LENGTH);
      strcpy(members[i], sorters_[i]->GetCompOpName());
    } else {
      members[i] = 0;
    }
  }
  p_.createGroup("Comparsions", members[0], members[1], members[2], members[3], members[4], members[5],
                 members[6], members[7], members[8], members[9]);
}

void SorterEvaluator::CreateProfilerAssignGroup() {

  char **members = (char **) malloc(sizeof(char *) * kMaxNoSorters);
  for (int i = 0; i < kMaxNoSorters; i++) {
    if (i < no_sorters_) {
      members[i] = (char *) malloc(sizeof(char) * MAX_SERIES_NAME_LENGTH);
      strcpy(members[i], sorters_[i]->GetAssignOpName());
    } else {
      members[i] = 0;
    }
  }
  p_.createGroup("Assignments", members[0], members[1], members[2], members[3], members[4], members[5],
                 members[6], members[7], members[8], members[9]);
}
