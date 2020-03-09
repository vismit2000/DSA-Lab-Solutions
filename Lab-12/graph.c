#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"
#include "extras.h"

#define INF 0x3f3f3f3f

Graph initGraph(int N)
{
    int i;
    Graph g;
    g = (Graph) malloc(sizeof(struct _Graph));
    assert(g != NULL);

    g->list = (node) malloc(sizeof(struct _node) * N);
    assert(g->list != NULL);

    g->visited = (bool*) malloc(sizeof(bool) * N);
    assert(g->visited != NULL);

    g->wt = (int*) malloc(sizeof(int) * N);
    assert(g->wt != NULL);

    g->vcount = N;
    g->ecount = 0;

    for(i = 0; i < N; i++)
    {
        g->list[i].id = i;
        g->list[i].next = NULL;
        g->visited[i] = false;
        g->wt[i] = -1;
    }
    return g;
}
void printAdjacencyList(Graph g)
{
	for(int i = 0; i < g->vcount; i++)
	{
		node temp = &(g->list[i]);
		
		printf("%u\t(%d) ==> ", i, g->wt[i]);
		temp = temp->next;
		while(temp != NULL)
		{
			printf("%u\t", temp->id);
			temp = temp->next;
		}
		printf("\n");
	}
}

/*
void insertNeighbor(node u, int v)
{
    node vnode = (node) malloc(sizeof(struct _node));
    assert(vnode != NULL);
    vnode->id = v;
    vnode->next = u->next;
    u->next = vnode;
}*/
void insertEdge(Graph g, unsigned int u, unsigned int v)
{
    //insertNeighbor(&(g->list[u]), v);
    node t = &(g->list[u]);
    node vnode = (node) malloc(sizeof(struct _node));
    assert(vnode != NULL);
    vnode->id = v;
    vnode->next = t->next;
    t->next = vnode;
    g->ecount++;
}
void bestFirstTraverse(Graph g)
{
	int src = 0;
	int V = g->vcount;
	
	int *key = (int *)malloc(sizeof(int)*V);
	bool *included = (bool *)malloc(sizeof(bool)*V);
	
	for(int i = 0; i < V; i++)
	{
		key[i] = -INF;
		included[i] = false;
	}
	
	pq PQ = createPQ();
	
	element ele = (element) malloc(sizeof(struct _node));
        assert(ele != NULL);
        ele->id = src;
        ele->next = NULL;
	
	enqueue(&PQ, ele, 0);

	while(!isEmpty(PQ))
	{
		element tp = dequeue(&PQ);
		int u = tp->id;
		
		included[u] = true;
		
		printf("%d\t", u);
		
		node temp = &(g->list[u]);
		temp = temp->next;
		while(temp != NULL)
		{
			int v = temp->id;
			int weight = g->wt[v];
			
			if(included[v] == false && key[v] < weight)
			{
				key[v] = weight;
				enqueue(&PQ, temp, key[v]);
				//printf("%d %d\n", v, key[v]);
			}
			temp = temp->next;
		}
	}
	printf("\n");
}