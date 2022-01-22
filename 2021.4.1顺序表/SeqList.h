#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>	



typedef int SeqDatasize;//方便以后类型的变换
typedef struct SeqList
{
	SeqDatasize* a;//数组的指针
	int size;//有效数据的个数
	int capcity;//当前的最大容量
}SeqList;

//内存中管理数据结构增删查改接口
void SeqListPushBack(SeqList* pc, SeqDatasize x);
void SeqListPushFront(SeqList* pc, SeqDatasize x);
void SeqListPopBack(SeqList* pc);
void SeqListPopFront(SeqList* pc);
void SeqListInit(SeqList* pc);
void SeqListDestory(SeqList* pc);
void SeqListPrint(SeqList* pc);
void SeqListInsert(SeqList* pc, int pos, SeqDatasize x);
void SeqListErase(SeqList* pc, int pos);


