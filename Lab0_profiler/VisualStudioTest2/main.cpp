#include <climits>
#include <cstdlib>
#include <cstdio>
#include "Profiler.h"

#define MAX_SIZE 10000
#define STEP_SIZE 100
#define NO_TESTS 50

Profiler p("secondMin");


void secondMinV1(int* v, int n, int* min1, int* min2)
{
	Operation opComp = p.createOperation("v1-comp", n);
	Operation opAssign = p.createOperation("v1-assign", n);
	if (n < 2)
	{
		fprintf(stderr, "The array has an invalid length\n");
	}
	*min1 = v[0];
	opAssign.count();
	*min2 = INT_MAX;
	opAssign.count();
	for (int i = 0; i < n; i++)
	{
		opComp.count();
		if (v[i] < *min1)
		{
			*min2 = *min1;
			opAssign.count();
			*min1 = v[i];
			opAssign.count();
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

void perf()
{
	int v[MAX_SIZE];
	;
	int n;
	for (n = STEP_SIZE; n <= MAX_SIZE; n += STEP_SIZE)
	{
		for (int test = 0; test < NO_TESTS; test++)
		{
			FillRandomArray(v, n);
			secondMinV1(v, n, (int*)malloc(sizeof(int)), (int*)malloc(sizeof(int)));
		}
	}
	p.divideValues("v1-comp", NO_TESTS);
	p.divideValues("v1-assign", NO_TESTS);
	p.addSeries("v1", "v1-assign", "v1-comp");
	p.showReport();
}

void demo()
{
	int v[] = { 2, 5, 0, 1, 7, 3, 10, 6, 3 };
	int n = sizeof(v) / sizeof(v[0]);
	int min1 = 0;
	int min2 = 0;
	secondMinV1(v, n, &min1, &min2);
	printf("The min = %d and min2 = %d\n", min1, min2);
	
}

int main()
{
	// demo();
	perf();
	return 0;
}