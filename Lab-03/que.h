#include<stdio.h>
#include<stdbool.h>

typedef struct node node;
typedef struct Queue Queue;

struct node
{
	void* element;
	node *next;
};

struct Queue 
{
	int count;
	node *head;
	node *tail;
};

extern Queue* newQ();                       // returns an empty Queue
extern bool isEmptyQ(Queue* q);             // tests whether q is empty
extern Queue* delQ(Queue* q);               // deletes the element from the front of the Queue; returns 						the modified Queue
extern node* front(Queue* q);               // returns the element from the front of the Queue;
extern Queue* addQ(Queue* q , node* e);     // adds e to the rear of the Queue; returns the modified 							Queue
extern int lengthQ(Queue* q);               // returns the length of the Queue