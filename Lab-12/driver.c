#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"
#include "extras.h"

int main(int argc, char *argv[])
{
    Graph g;
    int i, N, E;
    unsigned int u, v;
    int w;
    int seed, count;
    scanf("%d %d", &seed, &N);
    srand(seed);

    E = 2 * N;

    //part a
    g = initGraph(N);

    bool *matrix = (bool*) malloc(sizeof(bool) * N * N);
    assert(matrix != NULL);
    int j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            matrix[i * N + j] = false;

    while(E--)
    {
        u = rand()%N;
        v = rand()%N;
        i = 10;
        while(i-- && (u == v || matrix[u * N + v] == true))
                v = rand() % N;
        matrix[u * N +v] = true;

        //part b
        insertEdge(g, u, v);
        printf("%u %u\n", u, v);
    }
    printf("\nWeights: ");
    for(i=0; i < N; i++)
    {
        w = (rand() % N) * 10;
        g->wt[i] = w;
        printf("%d\t", w);
    }

    //part c
    printf("\nAdjacency List: \n");
    printAdjacencyList(g);

    //part d
    printf("\nBest First Traversal: \n");
    bestFirstTraverse(g);
    return 0;
}