#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "quick.h"
#include "stack.h"

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

void quickSort(Record *arr, int s, int e, int Size)
{
	//printf("\nquickSort Called");
	LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
	ll->count = 0;
	push(ll, s);
	push(ll, e);
	
	while(!isEmpty(ll))
	{
		int end = pop(ll);
		int start = pop(ll);
		
		int p = partition(arr, start, end);
		
		if(p-1 > start && (p-start) > Size)
		{
			push(ll, start);
			push(ll, p-1);
		}
		if(p+1 < end && (end-p) > Size)
		{
			push(ll, p+1);
			push(ll, end);
		}
	}
}

void insertionSort(Record *arr, int n)
{
	int i, j; 
	Record key;
	for (i = 1; i < n; i++) 
	{ 
	    	key = arr[i]; 
		j = i-1; 
	  
	        while (j >= 0 && (arr[j]).empID > key.empID) 
	        { 
		   arr[j+1] = arr[j]; 
		   j = j-1; 
	        } 
	        arr[j+1] = key; 
	} 
}