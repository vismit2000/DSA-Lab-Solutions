#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>   // for gettimeofday()
#include "MultiQ.h"

#define n 100

MultiQ* loadData(FILE *fileptr)
{
	int i = 0;
	int a, b;
	char c;

	MultiQ *mq = createMQ(11);

	Task *task[n];
	
	for(int i = 0; i < n; i++)
	{
		task[i] = (Task *) malloc(sizeof(Task));
	}

	while(fscanf(fileptr, "%d %c %d", &a, &c, &b) != EOF)
	{
		task[i]->tid = a;
		task[i]->p = b;
		mq = addMQ(mq, task[i]);
		i++;
	}
	return mq;
}

MultiQ *testDel(MultiQ *mq, int num)
{
	for(int i = 0; i < num; i++)
	{
		printf("%d , %d\n", nextMQ(mq)->tid, nextMQ(mq)->p);
		mq = delNextMQ(mq);
	}
	return mq;
}

int main(int argc, char *argv[])
{
	FILE * fileptr = fopen(argv[1], "r");
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	
	MultiQ *mq = loadData(fileptr);
	
	gettimeofday(&end, NULL);

	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	printf("Time elpased in loadData is %ld seconds and %ld micros\n", seconds, micros);
	
	fclose(fileptr);

	//printf("%d\n", sizeMQ(mq));
	
	gettimeofday(&start, NULL);
	
	mq = testDel(mq, 100);
	
	gettimeofday(&end, NULL);

	seconds = (end.tv_sec - start.tv_sec);
	micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	printf("Time elpased in testDel is %ld seconds and %ld micros\n", seconds, micros);
	
	//printf("%d\n", sizeMQ(mq));
	
	return 0;	
}