#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include "quick.h"

//size stores the current size of array, count stores the number of elements inserted
int count, size;

int absolute(int a, int b)
{
	if(a >= b)
		return (a-b);
	else
		return (b-a);
}

typedef struct TT TT;

struct TT
{
	int IStime;
	int QStime;
};

TT testRun(Record *arr, int n)
{
	TT tt;
	
	Record *arr1 = (Record *)malloc(n*sizeof(Record));
	for(int i = 0; i < n; i++)
	{
		arr1[i] = arr[i];
	}
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	shuffle(arr1, 0, n-1);
	quickSort(arr1, 0, n-1, 0);
	
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("\n%d\n", micros);
	
	tt.QStime = micros;
	
	for(int i = 0; i < n; i++)
	{
		arr1[i] = arr[i];
	}
	
	gettimeofday(&start, NULL);
	
	insertionSort(arr1, n);
	
	gettimeofday(&end, NULL);
	seconds = (end.tv_sec - start.tv_sec);
	micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	printf("\n%d\n", micros);
	
	tt.IStime = micros;
	
	return tt;
}


int estimateCutoff(Record *arr, int min, int max)
{
	/*TT tt1 = testRun(arr, min);
	while(tt1.IStime > tt1.QStime)
	{
		min--;
		tt1 = testRun(arr, min);
	}
	
	TT tt2 = testRun(arr, max);
	while(tt1.IStime < tt1.QStime)
	{
		max++;
		tt2 = testRun(arr, max);
	}
	*/
	TT tt;
	int mid;
	while(1)
	{
		mid = (min+max)/2;
		tt = testRun(arr, mid);
		if(tt.IStime >= tt.QStime)
			max = mid-1;
		else
			min = mid+1;
		if(min >= max)
			break;
	}
	return min;
	
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	FILE *fp = fopen(argv[1], "r");
	FILE *fout = fopen("output.txt", "w");
	
	if(fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	
	Record *arr = (Record *)malloc(4*sizeof(Record));
	size = 4;
	count = 0;
	char buf[100];
	char c1, c2;
	
	int i = 0;
	
	while(fgets(buf, 100, fp) != NULL)
	{
		if(count == size)
		{
			arr = (Record *)realloc(arr, 2*size*sizeof(Record));
			size *= 2;
		}
		count++;
		sscanf(buf, "%[^ ]%c%d%c", arr[i].name, &c1, &(arr[i].empID), &c2);
		i++;
	}
	int n = count;
	
	int ans = estimateCutoff(arr, 5, 9999);
	
	printf("\nans = %d\n", ans);
	
	fclose(fp);
	fclose(fout);
	return 0;
}