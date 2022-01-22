#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListInit(SeqList* pc)
{
	assert(pc);
	pc->a = NULL;
	pc->capcity = 0;
	pc->size = 0;
}

void SeqListDestory(SeqList* pc)
{
	
	free(pc->a);
	pc->a = NULL;
	pc->capcity = pc->size = 0;
}

void SeqListrealloc(SeqList* pc)
{
	assert(pc);
	if (pc->size == pc->capcity)
	{
		int newcapcity = pc->capcity == 0 ? 4 : pc->capcity * 2;
		int* newA = realloc(pc->a, newcapcity * sizeof(SeqDatasize));
		if (newA == NULL)
		{
			printf("增容失败\n");
			exit(1);
		}
		pc->capcity = newcapcity;
		pc->a = newA;
	}
}
void SeqListPushBack(SeqList* pc, SeqDatasize x)
{
	//assert(pc);
	SeqListrealloc(pc);
	pc->a[pc->size] = x;
	pc->size++;
	
}
void SeqListPushFront(SeqList* pc, SeqDatasize x)
{
	assert(pc);
	SeqListrealloc(pc);
	int i =pc-> size;
	while (i>=0)//a[0]应包含在内
	{
		pc->a[i + 1] = pc->a[i];
		i--;
	}
	pc->a[0] = x;
	pc->size++;
}

void SeqListPrint(SeqList* pc)
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->a[i]);
	}
	printf("\n");
}
void SeqListInsert(SeqList* pc, int pos, SeqDatasize x)
{
	assert(pc);
	assert(pos >= 0 && pos<= pc->size);
	SeqListrealloc(pc);
	int i = pc->size;
	while (i >= pos)
	{
		pc->a[i+1] = pc->a[i];
		--i;
	}
	pc->a[pos] = x;
	pc->size++;
}

void SeqListErase(SeqList* pc, int pos)
{
	assert(pc);
	while (pos < pc->size-1)
	{
		pc->a[pos] = pc->a[pos + 1];
		pos++;
	}
	pc->size--;
}



