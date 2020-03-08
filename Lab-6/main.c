#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include "merge.h"
//size stores the current size of array, count stores the number of elements inserted
int count, size;

int main(int argc, char *argv[])
{
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
	//int n = atoi(argv[1]);
	
	char str[10];
	sscanf(argv[1], "%[^.]", str);
	int n = atoi(str);
	int i = 0;
	
	struct timeval start, end;
	gettimeofday(&start, NULL);

	while(fgets(buf, 100, fp) != NULL)
	{
		if(count == size)
		{
			arr = (Record *)realloc(arr, 2*size*sizeof(Record));
			size *= 2;
		}
		count++;
		sscanf(buf, "%[^,] %c %f %c", (arr[i].name), &c1, &(arr[i].cgpa), &c2);
		i++;
	}

	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	fprintf(fout, "Time elpased in reading from file is %ld seconds and %ld micros\n", seconds, micros);
	for(int i = 0; i < n; i++)
	{
		printf("%20s %10f\n", (arr[i].name), (arr[i].cgpa));
	}
	printf("\nSorted order according to cgpa : \n\n");

	gettimeofday(&start, NULL);

	mergesort(arr, 0, n-1);

	for(int i = 0; i < n; i++)
	{
		printf("%20s %10f\n", (arr[i].name), (arr[i].cgpa));
	}

	gettimeofday(&end, NULL);
	seconds = (end.tv_sec - start.tv_sec);
	micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	fprintf(fout, "\nTime elpased in merge sort is %ld seconds and %ld micros\n", seconds, micros);

	fclose(fp);
	fclose(fout);

	return 0;
}