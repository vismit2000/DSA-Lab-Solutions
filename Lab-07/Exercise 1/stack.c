#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void push(LinkedList *ll, int data)
{
	if(ll->count == 0)
		ll->head = NULL;
	Node *link = (Node *)malloc(sizeof(Node));
	link->data = data;
	link->next = ll->head;
	ll->head = link;
	ll->count++;
}

int pop(LinkedList *ll)
{
	Node *temp = ll->head;
	int ret = temp->data;
	ll->head = temp->next;
	free(temp);
	ll->count--;
	return ret;
}

int isEmpty(LinkedList *ll)
{
	if(ll->count == 0)
		return 1;
	else
		return 0;
}