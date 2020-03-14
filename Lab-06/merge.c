#include<stdio.h>
#include "merge.h"
void merge(Record *Ls1, int sz1, Record *Ls2, int sz2, Record *Ls)
{
	int i = 0, j = 0, k = 0;
	while(i < sz1 && j < sz2)
	{
		if(Ls1[i].cgpa < Ls2[j].cgpa)
			Ls[k++] = Ls1[i++];
		else
			Ls[k++] = Ls2[j++];
	}
	while(i < sz1)
		Ls[k++] = Ls1[i++];
	while(j < sz2)
		Ls[k++] = Ls2[j++];
}