#include "List.h"

List createList(Student studArray, int arraySize)
{
	List ll = (List)myalloc(sizeof(struct list));
	
	ll->count = arraySize;
	
	Node temp = NULL;
	
	for(int i = arraySize-1; i >= 0; i--)
	{
		Node link = (Node)myalloc(sizeof(struct node));
		link->record = &studArray[i];	
		link->next = temp;
		
		if(i == arraySize-1)
			ll->last = link;
		
		temp = link;	
	}
	
	ll->first = temp;
	
	return ll;
}

void insertInOrder(List list, Node newNode)
{
	Node temp = list->first;
	
	if(temp == NULL)
	{
		list->first = newNode;
		list->last = newNode;
		list->last->next = NULL;
		return;
	}
	
	if(temp->record->marks > newNode->record->marks)
	{
		newNode->next = temp;
		list->first = newNode;
		return;
	}
	
	while(temp->next)
	{
		if(temp->next->record->marks > newNode->record->marks)
			break;
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	if(newNode->next == NULL)
		list->last = newNode;
}

List insertionSort(List list)
{
	List ll = (List)myalloc(sizeof(struct list));
	ll->count = list->count;
	ll->first = NULL;
	ll->last = NULL;
	
	Node nxt;
	Node temp = list->first;
	while(temp!=NULL)
	{
		nxt = temp->next;
		insertInOrder(ll, temp);
		temp=nxt;
	}
	return ll;
}

double measureSortingTime(List list)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	list = insertionSort(list);
	gettimeofday(&end, NULL);
	
	double seconds = (end.tv_sec - start.tv_sec);
	double micros = seconds *1000000 + end.tv_usec - start.tv_usec;
	return micros/1000;
}

void * myalloc(int size)
{
	void *a  = malloc(sizeof(int) + size);
	globalCounter += size;
	*(int *)a = size;
	return (a + sizeof(int));
}

void myfree(void* ptr)
{
	globalCounter -= *(int *)(ptr- sizeof(int));
	free(ptr-sizeof(int));
}