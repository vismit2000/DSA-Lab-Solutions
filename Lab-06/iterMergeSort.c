#include<stdio.h>
#include<stdlib.h>
#include "merge.h"

void mergesort(Record *arr, int s, int e)
{
	int curr_size;  // For current size of subarrays to be merged 
                   	// curr_size varies from 1 to n/2 
   	int left_start; // For picking starting index of left subarray 
                   	// to be merged

	for(curr_size = 1; curr_size <= e; curr_size *= 2)
	{
		for(left_start = 0; left_start <= e; left_start += (2*curr_size))
		{
			int mid = left_start + curr_size - 1;
			int right_end;
			
			if((left_start + 2*curr_size - 1) <= e)
				right_end = left_start + 2*curr_size - 1;
			else
				right_end = e;
				
			Record *temp = (Record *)malloc((e+1)*sizeof(Record));
			
			merge(arr+left_start, curr_size, arr+mid+1, right_end-mid, temp);
			
			for(int i = left_start; i <= right_end; i++)
			{
				arr[i] = temp[i-left_start];
				//printf("%s %f\n", arr[i].name, arr[i].cgpa);
			}
			free(temp);
		}
	}
}