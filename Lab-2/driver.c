#include <stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
int main(int argc, char *argv[])
{
    FILE * fileptr = fopen(argv[1], "r");
    struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
    int temp;
    while ((fscanf(fileptr, "%d", &temp)) != EOF)
    {
        insertFirst(head,temp);
    }
    fclose(fileptr);

    printList(head);
    deleteFirst(head);
    printList(head);
    
    int srch;
    printf("\nEnter element to be searched for in the list : ");
    scanf("%d", &srch);
    if(search(head, srch) == 1)
    	    printf("\nElement found");
    else
    	    printf("\nSorry, Element could not be found");    
    
    printf("\nEnter element to be deleted from the list : ");
    scanf("%d", &srch);
    struct node *check = delete(head, srch);
    if(check->element != -1)
    {
    	    printf("\nDeletion successful");
    	    printList(head);
    }
    else
    {
    	    printf("\nSorry, the element to be deleted doesn't exist.");
    	    printList(head);
    }
    
    // print the linked list to a new file.
   
    FILE *fptr = fopen("output.txt", "w");
    
    struct node *ptr = head->first;
    fprintf(fptr, "%s", "\n[ ");
    while(ptr != NULL)
    {       
        fprintf(fptr, "%d,", ptr->element);
        ptr = ptr->next;
    }
    fprintf(fptr, "%s", " ]");

    fclose(fptr);
    
    printf("%c",'\n');
}