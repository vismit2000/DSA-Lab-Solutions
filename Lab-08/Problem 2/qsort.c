#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName)
{
	FILE *fp = fopen(fileName, "r");
	
	if(fp == NULL)
	{
		printf("\nError opening file\n");
		exit(1);
	}
	
	char buf[100], str[20];
	char c1, c2;
	
	size = fgetc(fp) - '0';
	c1 = fgetc(fp);
	
	int i = 0;
	
	int *marks = (int *)malloc(size * sizeof(int));
	
	while(fgets(buf, 100, fp) != NULL)
	{
		sscanf(buf, "%[^\t]%c%d%c", str, &c1, &marks[i], &c2);
		i++;
	}
	return marks;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	KeyStruct ks = (KeyStruct)malloc(sizeof(struct keyStruct));
	int count = 0, j = 0;
	int temp[lsSize];
	for(int i = 0; i < lsSize; i++)
	{
		if(Ls[i] >= loKey && Ls[i] <= hiKey && notInArray(Ls[i], temp, count))
		{
			temp[j++] = Ls[i];
			count++;
		}
	}
	
	ks->Keys = (int *)malloc(count * sizeof(int));
	
	for(int i = 0; i < count; i++)
	{
		(ks->Keys)[i] = temp[i];
	}
	
	sort(ks->Keys, count);
	
	ks->keysSize = count;
	
	return ks;
}

void sort(int *arr, int n)
{
	int i, key, j;
	for(int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int notInArray(int x, int *arr, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == x)
			return 0;
	}
	return 1;
}

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int pivot = Ls[piv];
	swap(&Ls[piv], &Ls[hi]);
	int i = lo-1;
	int j = lo;
	for(; j < hi; j++)
	{
		if(Ls[j] <= pivot)
		{
			i++;
			swap(&Ls[i], &Ls[j]);
		}
	}
	swap(&Ls[i+1], &Ls[hi]);
	return (i+1);
}

void swap(int *a, int *b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct ks = extractKeys(Ls, size, loKey, hiKey);
	int k = ks->keysSize;
	
	for(int i = 0; i < k; i++)
	{
		while(loKey < hiKey)
		{
			int p = part2Loc(Ls, loKey, hiKey, i);
			printf("%d\n", p);
			quickSortKnownKeyRange(Ls, p-loKey, loKey, p-1);
			loKey = p+1;
		}
	}
}