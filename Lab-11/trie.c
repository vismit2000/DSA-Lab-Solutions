#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "trie.h"

int size;

char **parseString(char *string)
{
	int cnt = 0;
	for(int i = 0; string[i] != 0; i++)
	{
		if(string[i] == '.')
			cnt++;
	}
	
	char **ret = (char **)malloc((cnt+1) * sizeof(char *));
	for(int i = 0; i <= cnt; i++)
	{
		ret[i] = (char *)malloc(30 * sizeof(char));
	}
	
	int j = cnt;
	size = cnt+1;
	
	for(int i = 0; string[i] != 0; i++)
	{
		int k = 0;
		char temp[30] = "\0";
		while(string[i] != 0 && string[i] != '.')
		{
			temp[k++] = string[i++];
		}
		strcpy(ret[j],temp);
		j--;
		if(string[i] == 0)
			break;
	}
	return ret;
}

Trie *readData(FILE *fp, Trie *trie, int n)
{
	char ch;
	char string[100], ip[100];
	
	for(int i = 0; i < n; i++)
	{
		char **arr = (char **)malloc(20 * sizeof(char *));
		for(int i = 0; i < 20; i++)
		{
			arr[i] = (char *)malloc(30 * sizeof(char));
		}
	
	
		fscanf(fp, "%[^ ] %[^\n]\n", string, ip);
		arr = parseString(string);
		
		//for(int j = 0; j < size; j++)
		//    printf("%s ", arr[j]);
		//    		
		//printf("%s\n", ip);	
		
		addWord(trie, arr, ip, size);	
	}
	return trie;
}

void addWord(Trie *trie, char **arr, char *ip, int size)
{
	Node *temp = trie->root;
	for(int i = 0; i < size; i++)
	{
		char *word = arr[i];
		int flag = 0;
		
		if(temp->count == 0)
		{
			//allocate memory for children
			temp->child = (Node **)malloc(10 * sizeof(Node *));
			for(int j = 0; j < 10; j++)
			{
				(temp->child)[j] = (Node *)malloc(sizeof(Node));
				((temp->child)[j])->count = 0;
				((temp->child)[j])->isTerminal = false;
			}
		}	
		
		for(int j = 0; j < temp->count; j++)
		{
			if(strcmp(((temp->child)[j])->data, word) == 0)
			{
				temp = (temp->child)[j];
				//printf("%s\n", temp->data);
				flag = 1;
				break;
			} 
		}
		
		if(flag == 0)
		{
			strcpy(((temp->child)[temp->count])->data, word);
			temp->count++;
			temp = (temp->child)[temp->count - 1];
		}		
	}
	
	//Now, insert the IP
	
	if(temp->count == 0)
	{
		//allocate memory for children
		temp->child = (Node **)malloc(10 * sizeof(Node *));
		for(int j = 0; j < 10; j++)
		{
			(temp->child)[j] = (Node *)malloc(sizeof(Node));
			((temp->child)[j])->count = 0;
			((temp->child)[j])->isTerminal = false;
		}
	}	
	strcpy(((temp->child)[temp->count])->data, ip);
	temp->count++;
	temp->isTerminal = true;
}

char *lookup(Trie *trie, char *search)
{
	Node *temp = trie->root;
	
	char *ret = (char *) malloc(20 * sizeof(char));
	int k = 0;
	
	char **arr = (char **)malloc(20 * sizeof(char *));
	for(int i = 0; i < 20; i++)
	{
		arr[i] = (char *)malloc(30 * sizeof(char));
	}
	arr = parseString(search);
	
	for(int i = 0; i < size; i++)
	{
		char *word = arr[i];
		int flag = 0;
		
		for(int j = 0; j < temp->count; j++)
		{
			if(strcmp(((temp->child)[j])->data, word) == 0)
			{
				temp = (temp->child)[j];
				ret[k++] = j + '0';
				ret[k++] = ' ';
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			//return 0 2 5 as given in example
			return ret;
		}
	}
	return ((temp->child)[0])->data;
}