#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "linkedList.h"

int totalspacealloc = 0;

void* myalloc(int n)
{
	void *a = malloc(n + sizeof(int));
	totalspacealloc += n;
	*(int*) a = n;
	return (a + sizeof(int));
}

void myfree(void *ptr)
{
	totalspacealloc -= *(int*)(ptr-sizeof(int));
	free(ptr-sizeof(int));
}

void insertFirst(linkedList* ll, void *ele)
{
	if(ll->count == 0)
		ll->head = NULL;
	node *link = (node*) myalloc(sizeof(struct node));
	link->data = ele;
	link->next = ll->head;
	ll->head = link;
	ll->count++;
}

linkedList *createList(int N)
{
	int *ele = (int*)myalloc(N*sizeof(int));
	linkedList *ll = (linkedList *)myalloc(N*sizeof(linkedList));
	for(int i = 0; i < N; i++)
	{
		ele[i] = rand() % 1000;
		insertFirst(ll, &ele[i]);
	}
	return ll;
}

linkedList *createCycle(linkedList *ll)
{
	int r, flag = 0;
	int n = rand()%2;
	if(n == 0)
	{
		printf("\nLinked list is not cyclic ---------------------------------------\n");
		return ll;
	}
	else
	{
		//Find last element of linked list
		node *tail;
		node *temp = ll->head;
		
		while(temp != NULL)
		{
			if(temp->next == NULL)
			{
				tail = temp;
			}
			temp = temp->next;
		}
		
		while(flag == 0)
		{
			r = rand()%1000;
			node *ptr = ll->head;
			while(ptr != NULL)
			{
				if(*(int *)(ptr->data) == r)
				{
					tail->next = ptr;
					flag = 1;
					break;
				}
				ptr = ptr->next;
			}
		}
	}
	printf("\nLinked list is CYCLIC---------------------------------------------------\n");
	return ll;
}