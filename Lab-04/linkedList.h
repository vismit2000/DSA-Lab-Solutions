typedef struct linkedList linkedList;
typedef struct node node;

struct node
{
	void *data;
	node *next;
};

struct linkedList
{
	int count;
	node *head;
};

extern int totalspacealloc;

extern void* myalloc(int n);
extern void myfree(void *ptr);
extern void insertFirst(linkedList* ll, void *ele);
extern linkedList *createList(int N);
extern linkedList *createCycle(linkedList *ll);