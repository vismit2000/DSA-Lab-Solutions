#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "extras.h"

pq createPQ()
{
    pq que = (pq) malloc(sizeof(struct _pq));
    assert(que != NULL);

    que->len = 0;
    que->q = NULL;
    return que;
}

void swap(qnode a, qnode b)
{
    struct _qnode temp;
    temp.data = a->data;
    temp.pr = a->pr;

    a->data = b->data;
    a->pr = b->pr;

    b->data = temp.data;
    b->pr = temp.pr;
}
void enqueue(pq *q, element data, int prior)
{
    if((*q)->len == 0)
    {
        (*q)->len = 1;
        (*q)->q = (qnode) malloc(sizeof(struct _qnode));
        assert((*q)->q != NULL);
        (*q)->q[0].data = data;
        (*q)->q[0].pr = prior;
    }
    else
    {
        (*q)->len++;
        int len = (*q)->len;
        //printf("%d ", len);
        (*q)->q = (qnode) realloc((*q)->q, sizeof(struct _qnode) * len);
        assert((*q)->q != NULL);
        (*q)->q[len-1].data = data;
        (*q)->q[len-1].pr = prior;

        int cur = len - 1;
        while(cur > 0 && (*q)->q[cur].pr > (*q)->q[(cur-1)/2].pr)
        {
            swap(&((*q)->q[cur]), &((*q)->q[(cur-1)/2]));
            cur = (cur-1)/2;
        }
    }
}
bool isEmpty(pq q)
{
    if(q->len == 0)
        return true;
    else
        return false;
}
void printQ(pq q)
{
    printf("Size of PQ: %d\n", q->len);
    if(q->len == 0)
        return;
    int i;
    for(i = 0; i< q->len; i++)
    {
        //printf("%d (%d)\t", q->q[i].data, q->q[i].pr);
        printf("%d\t", q->q[i].pr);
    }
    printf("\n");
}
void max_heapify(qnode q, int i, int len)
{
    int left  = 2*i+1;
    int right = 2*i+2;
    int largest;
    if(left < len && q[left].pr > q[ i ].pr )
         largest = left;
    else
        largest = i;
    if(right < len && q[right].pr > q[largest].pr )
        largest = right;
    if(largest != i)
    {
        swap (&q[ i ], &q[ largest]);
        max_heapify (q, largest, len);
    }
}

element dequeue(pq *q)
{
    element temp;
    assert(!isEmpty(*q));
    temp = (*q)->q[0].data;

    int last = (*q)->len - 1;
    (*q)->q[0].data = (*q)->q[last].data;
    (*q)->q[0].pr = (*q)->q[last].pr;
    (*q)->q = (qnode) realloc((*q)->q, sizeof(struct _qnode) * last);
    (*q)->len--;
    max_heapify((*q)->q, 0, (*q)->len);
    return temp;
}