/***********file:   main.c *********/
#include <stdio.h>
#include "seqListOps.h"

int main(void)
{
 int i; int size;
 JobList list;
 size = initialize_elements (list);
 printf("The Jobs waiting on CPU are:\n");
 printJobList(list, size);
 sortJobList(list, size);
 printf("The Jobs after sorting are:\n");
 printJobList(list, size);
 return 0;
}
 
