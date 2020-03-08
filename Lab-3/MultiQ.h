#include "que.h"

typedef int TaskID;
typedef int Priority;

typedef struct MultiQ MultiQ;
typedef struct Task Task;

struct MultiQ
{
	Queue **q;
	int size;
};

struct Task
{
	TaskID tid;
	Priority p;
};	

extern MultiQ* createMQ(int num);
extern MultiQ* addMQ(MultiQ *mq, Task *t);
extern Task* nextMQ(MultiQ *mq);
extern MultiQ* delNextMQ(MultiQ *mq);
extern bool isEmptyMQ(MultiQ *mq);
extern int sizeMQ(MultiQ *mq);
extern int sizeMQbyPriority(MultiQ *mq, Priority p);
extern Queue* getQueueFromMQ(MultiQ *mq, Priority p);