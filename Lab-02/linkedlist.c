#include<stdlib.h>
#include "linkedlist.h"

void insertFirst(struct linkedList* head, int ele)
{
    struct node *link = (struct node*) malloc(sizeof(struct node));   
    link->element=ele;
    link->next = head->first;
    head -> first = link;
    head -> count++;
}

struct node* deleteFirst(struct linkedList * head)
{
    struct node *temp = head->first;
    head->first = temp->next;
    free(temp);
    head->count--;
    return head->first;
}

void printList(struct linkedList * head)
{
    struct node *ptr = head->first;
    printf("[ ");
    while(ptr != NULL)
    {       
        printf("%d,",ptr->element);
        ptr = ptr->next;
    }
    printf(" ]\n");
}

int search (struct linkedList * head, int ele)
{
	struct node *ptr = head->first;
	while(ptr != NULL)
	{
		if(ptr->element == ele)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

struct node * delete (struct linkedList * head, int ele)
{
	struct node *ptr = head->first;
	struct node *temp, *tmp;
	
	if(ptr->element == ele)
	{
		temp = ptr->next;
		head->first = temp;
		tmp = ptr;
		free(ptr);
		return tmp;
	}
	while(ptr->next)
	{
		if(ptr->next->element == ele)
		{
			temp = ptr->next;
			ptr->next = temp->next;
			tmp = temp;
			free(temp);
			return tmp;
		}
		ptr = ptr->next;
	}
	
	tmp = (struct node*) malloc(sizeof(struct node)); 
	tmp->element = -1;
	tmp->next = NULL;
	return tmp;
}