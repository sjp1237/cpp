#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SeqlistType;

typedef struct Seqlist
{
	 SeqlistType* data;
	 int sz;
	 int capacity;
}Seqlist;

 //初始化数据
void SeqlistInit(Seqlist* pc);
//打印数据
void SeqlistPrint(Seqlist* pc);
//尾插
void SeqlistPushBack(Seqlist* pc, SeqlistType x); 
//头插
void SeqlistPushFront(Seqlist* pc, SeqlistType x);
//尾删
void SeqlistPopBack(Seqlist* pc);
//头删
void SeqlistPopFront(Seqlist* pc);

void SeqlistInster(Seqlist* pc, int pos, SeqlistType x);

void SeqlistErase(Seqlist* pc, int pos);



