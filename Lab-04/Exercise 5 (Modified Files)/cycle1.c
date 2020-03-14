#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "cycle.h"

bool testCyclic(linkedList *ll)
{
	if(ll->count == 0)
		return false;
	
	node *hare = ll->head;
	node *tortoise = ll->head;

	while(1)
	{
		if(hare == NULL)
			return false;
		
		hare = hare->next;
		
		if(hare == NULL)
			return false;
		
		hare = hare->next;
		tortoise = tortoise->next;
		
		if(hare == tortoise)
			return true;		
	}	
}

linkedList *makeCircularList(linkedList *ll)
{
	if(!testCyclic(ll))
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
		tail->next = ll->head;
		return ll;
	}
	else
	{
		node *hare = ll->head;
		node *tortoise = ll->head;
		node *temp;
		while(1)
		{
			hare = hare->next;
			hare = hare->next;
			tortoise = tortoise->next;

			if(hare == tortoise)
				break;		
		}
		
		tortoise = ll->head;
		
		while(1)
		{
			if(tortoise == hare)
				return ll;
			hare = hare->next;
			temp = tortoise;
			tortoise = tortoise->next;
			ll->head = tortoise;
			myfree(temp);
		}
		return ll;
	}
}