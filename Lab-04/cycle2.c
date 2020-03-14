#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "cycle.h"

bool testCyclic(linkedList *ll)
{
	if(ll->count == 0)
		return false;

	node *startNode = ll->head;
	node *prevNode = NULL;
	node *currNode = startNode;
	node *nextNode;

	if(currNode->next == NULL)
		return false;
	
	while(currNode)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}

	return (prevNode == startNode);
}