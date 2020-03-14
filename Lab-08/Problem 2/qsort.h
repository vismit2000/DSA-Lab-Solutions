#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

typedef struct keyStruct * KeyStruct;
struct keyStruct
{
	int* Keys;
	int keysSize;
};

// Don't change signature or return type for any of the functions.

void printArray(int* studArray, int arrSize);

int* readData(char * fileName);

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey);

int part2Loc(int* Ls, int lo, int hi, int piv);

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey);

void sort(int *arr, int n);
int notInArray(int x, int *arr, int size);
void swap(int *a, int *b);