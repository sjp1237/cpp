#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

bool QueueEmpty(Queue* pq)
{
	return pq->head == NULL;
}

void QueuqInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueNodePush(Queue* pq, int x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->a = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
void QueueNodePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(&pq));
	if (pq->head->next == NULL)	
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* ret = pq->head->next;
		free(pq->head);
		pq->head = ret;
	}
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
QueueDataSize QueueFront(Queue* pq)
{
	assert(pq);
	return pq->head->a;
}
QueueDataSize QueueBack(Queue* pq)
{
	assert(pq);
	return pq->tail->a;
}