#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include "cycle.h"

int main()
{
	srand(time(NULL));
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
}