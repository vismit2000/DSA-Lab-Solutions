#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//size stores the current size of array, count stores the number of elements inserted
int count, size;
int BASE, TSIZE;

typedef struct Record Record;

struct Record {
    int index;
    int count;
    Record *next;
};

typedef struct HashTable HashTable;

struct HashTable {
    Record **slot; 
    // Create a hash table with given number of slots; Each slot is a linked list of records
    int elementCount;
    int insertionCost;
    int queryingCost;
};

int hashFunc(char *string, int baseNumber, int tableSize)
{
	int ans = 0;
	for(int i = 0; string[i] != '\0'; i++)
		ans += string[i];

	return (ans % baseNumber) % tableSize;
}

int collisionCount(char **string, int baseNumber, int tableSize, int len)
{
	int *arr = (int*)malloc(len*sizeof(int));
	for(int i = 0; i < len; i++)
		arr[i] = 0;
	int cnt = 0;
	for(int i = 0; i < len; i++)
	{
		if(arr[hashFunc(string[i], baseNumber, tableSize)] != 0)
			cnt++;
		else
			arr[hashFunc(string[i], baseNumber, tableSize)] = 1;
	}
	return cnt;
}

char **parse(FILE *fp)
{
	char **book = (char **)malloc(500*sizeof(char*));
	for(int i = 0; i < 500; i++)
	{
		book[i] = (char *)malloc(100*sizeof(char));
	}
	size = 500;
	count = 0;
	int i = 0, k = 0;
	char c;
	
	while(fscanf(fp, "%c", &c) != EOF)
	{		
		if(count == size)
		{	
			book = (char **)realloc(book, 2*size*sizeof(char *));
			for(int i = size; i < 2*size; i++)
			{
				book[i] = (char *)malloc(100*sizeof(char));
			}
			size *= 2;
		}
		
		if( (c < 65) || (c > 90 && c < 97) || (c >122) )
			continue;
			
		char temp[100] = "\0";
		temp[i++] = c;
		
		while(fscanf(fp, "%c", &c) != EOF)
		{
			if( (c < 65) || (c > 90 && c < 97) || (c >122) )
			{
				count++;		
				strcpy(book[k++], temp);
				i = 0;
				break;	
			}
			temp[i++] = c;
		}		
	}
	return book;
}

void profiler(char** book)
{
    //book = parse("aliceinwonderland.txt");                          
    int cointisions[18] = {0};

    cointisions[0] = collisionCount(book,5003,5000,count);
    cointisions[1] = collisionCount(book,7577,5000,count);
    cointisions[2] = collisionCount(book,9967,5000,count);
    cointisions[3] = collisionCount(book,5000011,5000,count);
    cointisions[4] = collisionCount(book,6000011,5000,count);
    cointisions[5] = collisionCount(book,9000011,5000,count);

    cointisions[6] = collisionCount(book,50021,50000,count);
    cointisions[7] = collisionCount(book,75133,50000,count);
    cointisions[8] = collisionCount(book,99881,50000,count);
    cointisions[9] = collisionCount(book,50000017,50000,count);
    cointisions[10] = collisionCount(book,70000027,50000,count);
    cointisions[11] = collisionCount(book,90000049,50000,count);

    cointisions[12] = collisionCount(book,500009,500000,count);
    cointisions[13] = collisionCount(book,700001,500000,count);
    cointisions[14] = collisionCount(book,1000003,500000,count);
    cointisions[15] = collisionCount(book,500000003,500000,count);
    cointisions[16] = collisionCount(book,700000001,500000,count);
    cointisions[17] = collisionCount(book,900000011,500000,count);

    for(int i=0; i<18; i++){
        printf("%d\n", cointisions[i] );
    }

}

HashTable *createHashTable(int size) 
{
	HashTable *ht;
	ht = (HashTable *) malloc(sizeof(HashTable));
	ht->elementCount = 0;
	ht->insertionCost = 0;
	ht->queryingCost = 0;
	ht->slot = (Record **) malloc(sizeof(Record *)*size);
	for(int i = 0; i < size; i++)
		ht->slot[i] = NULL;
	return ht;
}

void insert(HashTable *ht, char **book, int j)
{
	int cost = 0;
	int index = hashFunc(book[j], BASE, TSIZE);
	
	if(ht->slot[index] == NULL)
	{	
		ht->slot[index] = (Record *) malloc(sizeof(Record));
		(ht->slot[index])->index = j;
		(ht->slot[index])->count = 1;
		(ht->slot[index])->next = NULL;
	}
	else
	{
		Record *temp = ht->slot[index];
		
		while((temp->next != NULL) && (strcmp(book[temp->index], book[j]) != 0))
		{
			cost++;
			temp = temp->next;
		}
		
		if(strcmp(book[temp->index], book[j]) == 0)
		{
			temp->count++;
		}
		else
		{
			temp->next = (Record *)malloc(sizeof(Record));
            		(temp->next)->index = j;
            		(temp->next)->count = 1;
            		(temp->next)->next = NULL;
		}
	}
	ht->insertionCost += cost;	
}

int insertAll(HashTable *ht, char **book)
{
	for(int i = 0; i < count; i++)
		insert(ht, book, i);
	return ht->insertionCost;		
}

Record *lookup(HashTable *ht, char *string, char **book)
{
	int index = hashFunc(string, BASE, TSIZE);
	int cost = 0;
	
	Record *temp = ht->slot[index];
	
	if(temp == NULL)
		return NULL;
	
	while((temp->next != NULL) && (strcmp(book[temp->index], string) != 0))
	{
		cost++;
		temp = temp->next;
	}
	
	ht->queryingCost += cost;
	
	if(strcmp(book[temp->index], string) == 0)
		return temp;
	return NULL;
}

int lookupAll(HashTable *ht, char **book, float m)
{
	int sz = (int) count*m;
	Record *temp;
	ht->queryingCost = 0;
	
	for(int i = 0; i < sz; i++)
		lookup(ht, book[i], book);
	
	return ht->queryingCost;
}

void printHashTable(HashTable *ht, char** book)
{
    for(int i = 0; i < TSIZE; i++)
    {
        if(ht->slot[i] != NULL)
        {
            Record *temp = ht->slot[i];
            while(temp != NULL)
            {
                printf("%s-> ", book[temp->index]);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

void delete(HashTable *ht, char** book, char* str)
{
    if(lookup(ht, str, book) == NULL) 
    	return;
    	
    int index = hashFunc(str, BASE, TSIZE);

    Record *temp = ht->slot[index];

    //if the element to be deleted is the first element of the list
    if(temp == NULL) 
    	return;
    else if(strcmp(book[temp->index], str) == 0)
    {
        ht->slot[index] = temp->next;
        return;
    }

    //if the element to be deleted is somewhere in the middle
    Record *pretemp = temp;
    temp = temp->next;

    while(temp->next != NULL && (strcmp(book[temp->index], str) != 0)) 
    {
        pretemp = pretemp->next;
        temp = temp->next;
    }

    if((strcmp(book[temp->index],str) == 0))   
    {
        pretemp->next = temp->next;
        free(temp);
    }
}

void cleanup(HashTable* ht, char** book)
{
    FILE* fptr = fopen("stopwords.txt", "r");
    if(fptr == NULL)
    {
		printf("Cannot Open File");
		exit(0);
    }

    while(!feof(fptr))
    {
        char word[100];
        fscanf(fptr,"%s\n", word);
        delete(ht, book, word);
    }
    fclose(fptr);
}


int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}
	
	char **book = parse(fp);
	
	//profiler(book);
	
	HashTable *ht = createHashTable(50000);
	
	BASE = 99881, TSIZE = 50000;
	
	printf("%d\n", insertAll(ht, book));
	printf("%d\n", lookupAll(ht, book, 0.05));
	printHashTable(ht, book);
	
	cleanup(ht, book);
	printHashTable(ht, book);	
	
	fclose(fp);
	return 0;
}