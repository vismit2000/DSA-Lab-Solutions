#include <stdio.h>
#include<stdlib.h>
#include "Stack.h"

int main(int argc, char *argv[])
{
	FILE * fileptr = fopen(argv[1], "r");
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	int temp;
	while ((fscanf(fileptr, "%d", &temp)) != EOF)
	{
		push(head,temp);
	}
	fclose(fileptr);
	printList(head);

	struct node * ptr = (struct node *) malloc (sizeof(struct node));
	while(head->count)
	{
		ptr = pop(head);
		printList(head);
	}
}