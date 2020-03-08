#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"

#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

typedef node element;

struct _qnode
{
    element data;
    int pr;
};

typedef struct _qnode* qnode;
struct _pq
{
    qnode q;
    int len;
};

typedef struct _pq* pq;

pq createPQ();
void swap(qnode a, qnode b);
void enqueue(pq *q, element data, int prior);
void printQ(pq q);
bool isEmpty(pq q);
void max_heapify(qnode q, int i, int len);
element dequeue(pq *q);

#endif