#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void test1()
{
	Queue pq;
	QueuqInit(&pq);
	QueueNodePush(&pq, 1);
	QueueNodePush(&pq, 2);
	QueueNodePush(&pq, 3);
	QueueNodePush(&pq, 4);
	QueueNodePush(&pq, 5);
	QueueNodePush(&pq, 6);
	while (!(QueueEmpty(&pq)))
	{
		printf("%d ", QueueFront(&pq));
		QueueNodePop(&pq);


	}

}

int main()
{
	test1();
	return 0;
}