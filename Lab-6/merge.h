#include<stdio.h>

typedef struct Record Record;

struct Record
{
	char name[20];
	float cgpa;
};

extern void merge(Record *Ls1, int sz1, Record *Ls2, int sz2, Record *Ls);
extern void mergesort(Record *arr, int s, int e);