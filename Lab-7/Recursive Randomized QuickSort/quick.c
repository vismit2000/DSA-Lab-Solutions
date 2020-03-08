#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "quick.h"

void swap(Record *r1, Record *r2)
{
	//printf("\nswap Called");
	Record temp = *r1;
	*r1 = *r2;
	*r2 = temp;
}

void shuffle(Record *arr, int s, int e)
{
	int i, j;
	for(i = e; i > 0; i--)
	{
		j = rand()%(i+1);
		swap(&arr[i], &arr[j]);
	}
}

int partition(Record *arr, int s, int e)
{
	//printf("\nPartition Called");
	int i = s-1; 
	Record pivot = arr[e];
	
	for(int j = s; j < e; j++)
	{
		if((arr[j]).empID <= pivot.empID)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	//Bring the pivot element back to its sorted position
	swap(&arr[i+1], &arr[e]);
	return (i+1);
}

void quickSort(Record *arr, int s, int e)
{
	//printf("\nquickSort Called");
	if(s >= e)
		return;
	int p = partition(arr, s, e);
	quickSort(arr, s, p-1);
	quickSort(arr, p+1, e);
}