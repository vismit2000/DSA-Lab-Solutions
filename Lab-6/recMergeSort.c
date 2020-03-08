#include<stdio.h>
#include<stdlib.h>
#include "merge.h"

void mergesort(Record *arr, int s, int e)
{
	if(s >= e)
		return;
	int mid = s + (e-s)/2;
	
	mergesort(arr, s, mid);
	mergesort(arr, mid+1, e);
	
	Record *temp = (Record *)malloc((e+1)*sizeof(Record));
	
	merge(arr + s, mid-s+1, (arr + mid + 1), e-mid, temp);
	
	for(int i = s; i <= e; i++)
	{
		arr[i] = temp[i-s];
		//printf("%s %f\n", arr[i].name, arr[i].cgpa);
	}
	free(temp);
}