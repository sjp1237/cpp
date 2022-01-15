#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
typedef int QueueDataSize;

typedef struct QueueNode
{
	struct QueueNode* next;
	QueueDataSize a;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueuqInit(Queue* pq);
void QueueNodePush(Queue* pq, int x);
void QueueDestory(Queue* pq);
void QueueNodePop(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
QueueDataSize QueueFront(Queue* pq);
QueueDataSize QueueBack(Queue* pq);




