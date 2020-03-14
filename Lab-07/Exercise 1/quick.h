#include<stdio.h>

typedef struct Record Record;

struct Record
{
	char name[15];
	int empID;
};

extern void swap(Record *r1, Record *r2);
extern void shuffle(Record *arr, int s, int e);
extern int partition(Record *arr, int s, int e);
extern void quickSort(Record *arr, int s, int e, int Size);
extern void insertionSort(Record *arr, int n);