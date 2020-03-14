#include<stdlib.h>
#include "que.h"

// returns an empty Queue
Queue* newQ()
{
	Queue *new = (Queue*) malloc(sizeof(Queue)); 
	new->count = 0;
	new->head = NULL;
	new->tail = NULL;
	return new;
}                      

// tests whether q is empty
bool isEmptyQ(Queue* q)             
{
	if(q->count == 0)
		return true;
	return false;
}

// deletes the element from the front of the Queue; returns the modified Queue
Queue* delQ(Queue* q)               
{
	if(isEmptyQ(q))
		return q;
	if(q->count == 1)
	{
		q->count = 0;
		node *temp = q->head;
		q->head = NULL;
		q->tail = NULL;
		free(temp);
		return q;
	}	
	node *ptr = q->head;
	q->head = ptr->next;
	free(ptr);
	q->count--;
	return q;
}

// returns the element from the front of the Queue;
node* front(Queue* q)                
{
	if(isEmptyQ(q))
		return NULL;
	return q->head;
}

// adds e to the rear of the Queue; returns the modified Queue
Queue* addQ(Queue* q , node* e)      
{	

	if(isEmptyQ(q))
	{
		q->count++;
		q->head = e;
		q->tail = e;
		return q;
	}
	q->tail->next = e;
	q->tail = e;
	q->count++;
	return q;
}

// returns the length of the Queue
int lengthQ(Queue* q)
{
	return q->count;
}                