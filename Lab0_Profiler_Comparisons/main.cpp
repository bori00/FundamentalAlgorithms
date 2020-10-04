#include <climits>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include "Profiler.h"

#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NO_TESTS 50

Profiler p("secondMin");

using namespace std;

/**
 * Task: find the two lowest values in an array of integers.
 * @param v - pointer to the array of integers
 * @param n - number of elements in the array
 * @param min1 - pointer to the lowest value(to be returned)
 * @param min2 - pointer to the second lowest value(to be returned)
 *
 * Solution:
 * I implemented 3 different algorithms:
 * Version 1: iterate though the elements once.
 * If the current value is smaller
 * then the current min1, let min2 take the value of min1 and update min1
 * with the current elemen's value.
 * If the current element's value is larger than or equal to min1, but smaller
 * than min2, update min2 only with the current value.
 *
 * Version 2: similar to version 1, but compares to min2 first,
 * based on the remark that (especially in a large array) most elements will
 * be larger than min2 anyway, and then the second comparison is not needed.
 *
 * Version 3: build a binary tree of comparisons to find min1: originally,
 * each element is a leaf. Nodes next to each other are compared and the
 * smallest one will be their parent. With this recursive approach,
 * the root element will be min1. For n leaves, n/2 leaf-comparisons and n/2
 * inner-comparisons are needed.
 * To find min2, use the remark that min2 must have been compared to min1
 * at some point. So check the values to which min1 was compared. There are log n
 * such nodes.
 *
 * Performance comparison:
 * based on the attached graphs, version 1 and 2 are similar in terms of asignments,
 * but version 2 performs much better at comparisons. On evaregae, version 1 has
 * 2n comparisons, and version 2 a little more than n.
 * Version 3 is definitely faster than the other 2, but the difference between
 * version 2 and 3 is in fact irrelevant, especially if we take into account the fact
 * that for version 3 we did no count the assignments performed on game entities.
 */

void secondMinV1(int* v, int n, int* min1, int* min2)
{
    Operation opComp = p.createOperation("v1-comp", n);
    Operation opAssign = p.createOperation("v1-assign", n);
    if (n < 2)
    {
        fprintf(stderr, "The array has an invalid length\n");
    }
    opComp.count();
    if (v[0] < v[1]) {
        opAssign.count(2);
        *min1 = v[0];
        *min2 = v[1];
    } else {
        opAssign.count(2);
        *min1 = v[1];
        *min2 = v[0];
    }
    for (int i = 2; i < n; i++)
    {
        opComp.count();
        if (v[i] < *min1)
        {
            *min2 = *min1;
            *min1 = v[i];
            opAssign.count(2);
        }
        else {
            opComp.count();
            if (v[i] < *min2)
            {
                *min2 = v[i];
                opAssign.count();
            }
        }
    }
}

void secondMinV2(int* v, int n, int* min1, int* min2)
{
    Operation opComp = p.createOperation("v2-comp", n);
    Operation opAssign = p.createOperation("v2-assign", n);
    if (n < 2)
    {
        fprintf(stderr, "The array has an invalid length\n");
    }
    if (v[0] < v[1]) {
        opAssign.count(2);
        *min1 = v[0];
        *min2 = v[1];
    } else {
        opAssign.count(2);
        *min1 = v[1];
        *min2 = v[0];
    }
    for (int i = 2; i < n; i++)
    {
        opComp.count();
        if (v[i] < *min2)
        {
            opComp.count();
            if (v[i] < *min1) {
                *min2 = *min1;
                opAssign.count();
                *min1 = v[i];
                opAssign.count();
            } else {
                *min2 = v[i];
                opAssign.count();
            }
        }
    }
}

typedef struct _Game {
    int outcome; // the index of the winner
    struct _Game *winner;
    struct _Game *loser;
} Game;

void secondMinV3(int* v, int n, int* min1, int* min2)
{
    Operation opComp = p.createOperation("v3-comp", n);
    Operation opAssign = p.createOperation("v3-assign", n);
    Game games[2*MAX_SIZE];
    int i, j;
    for (i = 0; i < n; i++) {
        games[i].outcome = i;
        games[i].winner = games[i].loser = NULL;
    }
    i = 0;
    j = n;
    while (j - i > 1) {
        opComp.count();
        if (v[games[i].outcome] < v[games[i+1].outcome]) {
            games[j].outcome = games[i].outcome;
            games[j].winner = &games[i];
            games[j].loser = &games[i+1];
        } else {
            games[j].outcome = games[i+1].outcome;
            games[j].winner = &games[i+1];
            games[j].loser = &games[i];
        }
        i+=2;
        j++;
    }
    *min1 = v[games[j-1].outcome];
    *min2 = v[games[j-1].loser->outcome];
    opAssign.count(2);
    Game* g = games[j-1].winner;
    while (g->loser != NULL) {
        opComp.count();
        if (v[g->loser->outcome] < *min2) {
            *min2 = v[g->loser->outcome];
            opAssign.count();
        }
        g = g->winner;
    }
}

void perf(int order)
{
    int v[MAX_SIZE];
    ;
    int n;
    for (n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
    {
        for (int test = 0; test < NO_TESTS; test++)
        {
            FillRandomArray(v, n, 10, 50000, false, order);
            secondMinV1(v, n, (int*)malloc(sizeof(int)), (int*)malloc(sizeof(int)));
            secondMinV2(v, n, (int*)malloc(sizeof(int)), (int*)malloc(sizeof(int)));
            secondMinV3(v, n, (int*)malloc(sizeof(int)), (int*)malloc(sizeof(int)));
        }
    }
    p.divideValues("v1-comp", NO_TESTS);
    p.divideValues("v1-assign", NO_TESTS);
    p.addSeries("v1", "v1-assign", "v1-comp");

    p.divideValues("v2-comp", NO_TESTS);
    p.divideValues("v2-assign", NO_TESTS);
    p.addSeries("v2", "v2-assign", "v2-comp");

    p.divideValues("v3-comp", NO_TESTS);
    p.divideValues("v3-assign", NO_TESTS);
    p.addSeries("v3", "v3-assign", "v3-comp");

    p.createGroup("assign", "v1-assign", "v2-assign", "v3-assign");
    p.createGroup("comp", "v1-comp", "v2-comp", "v3-comp");
    p.createGroup("total", "v1", "v2", "v3");
}

void perf_all() {
    p.reset("average");
    perf(UNSORTED);
    p.reset("best");
    perf(ASCENDING);
    p.reset("worst");
    perf(DESCENDING);
    p.showReport();
}

void secondMinV1_test() {
    int v[MAX_SIZE];
    int min1 = 0, min2 = 0;
    int n = 2 + (rand() % (MAX_SIZE - 2));
    FillRandomArray(v, n);
    secondMinV1(v, n, &min1, &min2);
    sort(v, v+n);
    assert(v[0] == min1);
    assert(v[1] == min2);
}

void secondMinV2_test() {
    int v[MAX_SIZE];
    int min1 = 0, min2 = 0;
    int n = 2 + (rand() % (MAX_SIZE - 2));
    FillRandomArray(v, n);
    secondMinV2(v, n, &min1, &min2);
    sort(v, v+n);
    assert(v[0] == min1);
    assert(v[1] == min2);
}

void secondMinV3_test() {
    int v[MAX_SIZE];
    int min1 = 0, min2 = 0;
    int n = 2 + (rand() % (MAX_SIZE - 2));
    FillRandomArray(v, n);
    secondMinV3(v, n, &min1, &min2);
    sort(v, v+n);
    assert(v[0] == min1);
    assert(v[1] == min2);
}

void test() {
    for (int test = 0; test < 1000; test++) {
        secondMinV1_test();
        secondMinV2_test();
        secondMinV3_test();
    }
}

void demo()
{
    int v[] = { 2, 5, 0, 1, -6,  7, 3, 10, -6, 3 };
    int n = sizeof(v) / sizeof(v[0]);
    int min1 = 0;
    int min2 = 0;
    secondMinV2(v, n, &min1, &min2);
    printf("The min = %d and min2 = %d\n", min1, min2);
}

int main()
{
    // demo();
    test();
    perf_all();
    return 0;
}