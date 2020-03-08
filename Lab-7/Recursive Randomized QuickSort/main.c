#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include "quick.h"

//size stores the current size of array, count stores the number of elements inserted
int count, size;

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
	
	for(int i = 0; i < n; i++)
	{
		printf("%20s %10d\n", (arr[i].name), (arr[i].empID));
	}
	printf("\nSorted order according to empID : \n\n");
	
	shuffle(arr, 0, n-1);
	quickSort(arr, 0, n-1);

	for(int i = 0; i < n; i++)
	{
		printf("%20s %10d\n", (arr[i].name), (arr[i].empID));
	}
	
	fclose(fp);
	fclose(fout);
	return 0;
}