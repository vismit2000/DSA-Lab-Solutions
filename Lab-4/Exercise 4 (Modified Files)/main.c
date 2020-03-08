#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "cycle.h"

int main()
{
	srand(time(NULL));
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	int n = 1000000;
	linkedList *ll = createList(n);
	ll = createCycle(ll);
	FILE *fileptr = fopen("output.txt", "w");
	fprintf(fileptr, "%d\n", totalspacealloc);
	fclose(fileptr);
	bool isCyclic = testCyclic(ll);
	if(isCyclic == true)
		printf("\nLinked list is cyclic\n");
	else
		printf("\nLinked list is not cyclic\n");
	
	gettimeofday(&end, NULL);

	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("\nTotal amount of heap space used : %d\n", totalspacealloc);
	printf("Time elpased in loadData is %ld seconds and %ld micros\n\n", seconds, micros);
}