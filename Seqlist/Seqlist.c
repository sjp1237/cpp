#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"
void SeqlistInit(Seqlist* pc)
{
	pc->data = NULL;
	pc->capacity = 0;	
	pc->sz = 0;
}

void SeqlistPrint(Seqlist* pc)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%d ", pc->data[i]);
	}
	printf("\n");
}



void SealistRealloc(Seqlist* pc)
{
	if (pc->capacity == pc->sz)
	{
		pc->capacity = pc->capacity == 0 ? 4 : pc->capacity * 2;
		pc->data = realloc(pc->data, pc->capacity * sizeof(SeqlistType));
	}
	if (pc->data==NULL)
	{
		exit(1);
	}

}



void SeqlistPushBack(Seqlist* pc, SeqlistType x)
{
	SealistRealloc(pc);

	pc->data[pc->sz] = x;
	pc->sz++;
}

void SeqlistPushFront(Seqlist* pc, SeqlistType x)
{
	SealistRealloc(pc);
	int cur = pc->sz;
	while (cur >= 0)
	{
		pc->data[cur + 1] = pc->data[cur];
		cur--;
	}
	pc->data[0] = x;
	pc->sz++;
}

void SeqlistPopBack(Seqlist* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		return;
	}
	pc->sz--;
}

void SeqlistPopFront(Seqlist* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		return;
	}
	int cur = pc->sz;
	for (int i = 0; i < cur-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
}

void SeqlistInster(Seqlist* pc, int pos, SeqlistType x)
{
	assert(pc);
	assert(pos >= 0 && pos <= pc->sz);
	SealistRealloc(pc);
	int cur = pos;
	while (cur <= pc->sz)
	{
		pc->data[cur + 1] = pc->data[cur];
		cur++;
	}
	pc->data[pos] = x;
	pc->sz++;

}

void SeqlistErase(Seqlist* pc, int pos)
{
	assert(pc);
	int cur = pos;
	if (pc->sz == 0)
	{
		return;
	}
	for (int i = cur; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;

}




