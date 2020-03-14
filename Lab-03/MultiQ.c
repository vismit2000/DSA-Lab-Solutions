#include<stdlib.h>
#include "MultiQ.h"

// creates a list of num Queues, each of which is empty
MultiQ* createMQ(int num)
{
	MultiQ* mq = (MultiQ *) malloc(sizeof(MultiQ));
	mq->q = (Queue **) malloc(num * sizeof(Queue));
	mq->size = num;
	
	for(int i = 0; i < num; i++)
	{
		(mq->q)[i] = newQ();
	}
	
	return mq;
}

// adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p
MultiQ* addMQ(MultiQ *mq, Task *t)
{
	node *link = (node *) malloc(sizeof(node));
	link->element = t;
	link->next = NULL;
	
	int pri = t->p;
	(mq->q)[pri] = addQ( (mq->q)[pri], link);
	
	return mq;
}

// returns the front of the non-empty Queue in mq with the highest priority
Task* nextMQ(MultiQ *mq)
{
	int num = mq->size;
	while(num--)
	{
		if(!isEmptyQ( (mq->q)[num] ))	
			return (Task *)((front( (mq->q)[num] ))->element);
	}
	return NULL;
}

// deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
MultiQ* delNextMQ(MultiQ *mq)
{
	int num = mq->size;
	
	while(num--)
	{
		if(!isEmptyQ( (mq->q)[num] ))
		{	
			(mq->q)[num] = delQ( (mq->q)[num] );
			break;
		}
	}
	return mq;
}

// tests whether all the Queues in mq are empty
bool isEmptyMQ(MultiQ *mq)
{
	int num = mq->size;
	
	while(num--)
	{
		if(!isEmptyQ( (mq->q)[num] ))
		{	
			return false;
		}
	}
	return true;
}

// returns the total number of items in the MultiQ
int sizeMQ(MultiQ *mq)
{
	int ans = 0;
	
	int num = mq->size;
	
	while(num--)
	{
		ans += ( (mq->q)[num] )->count;
	}
	return ans;
}

// returns the number of items in mq with the priority p
int sizeMQbyPriority(MultiQ *mq, Priority p)
{
	return ( (mq->q)[p] )->count;
}

// returns the Queue with priority p
Queue* getQueueFromMQ(MultiQ *mq, Priority p)
{
	return ( (mq->q)[p] );
}