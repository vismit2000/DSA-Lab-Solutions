#include <stdio.h>

struct node
{
    int element;
    struct node * next;
};

struct linkedList
{
    int count;
    struct node * first;
};

void insertFirst(struct linkedList * head, int ele);
struct node * deleteFirst(struct linkedList * head);
void printList (struct linkedList * head);
int search (struct linkedList * head, int ele);
struct node * delete (struct linkedList * head, int ele);