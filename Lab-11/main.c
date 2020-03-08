#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "trie.h"

int main(int argc, char *argv[])
{
	FILE * fp = fopen(argv[1], "r");
	
	if(fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	
	int choice, n;
	char search[100];
	
	Trie *trie = (Trie *) malloc(sizeof(Trie));
	trie->root = (Node *) malloc(sizeof(Node));
	strcpy(trie->root->data, "");
	trie->root->isTerminal = false;
	trie->root->count = 0;
	while(1)
	{
		fscanf(fp, "%d", &choice);
		if(choice == 1)
		{
			fscanf(fp, " %d\n", &n);
			trie = readData(fp, trie, n);	
		}
		else if(choice == 2)
		{
			fscanf(fp," %[^\n]\n", search);
			printf("%s\n", lookup(trie, search));
		}
		else if(choice == -1)
			break;
	}
	fclose(fp);
	return 0;			
}