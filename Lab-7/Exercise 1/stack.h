#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node
{
	int data;
	Node *next;
};

struct LinkedList
{
	int count;
	Node *head;
};

extern void push(LinkedList *ll, int data);
extern int pop(LinkedList *ll);
extern int isEmpty(LinkedList *ll);