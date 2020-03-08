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