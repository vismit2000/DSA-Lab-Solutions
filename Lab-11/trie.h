#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Trie Trie;
typedef struct Node Node;

struct Trie
{
	Node *root;
};

struct Node
{
	char data[100];
	bool isTerminal;
	int count;			//No. of children
	Node **child;
};

extern Trie *readData(FILE *fptr, Trie *trie, int n);
extern char **parseString(char *string);
extern void addWord(Trie *trie, char **arr, char *ip, int size);
extern char *lookup(Trie *trie, char *search);