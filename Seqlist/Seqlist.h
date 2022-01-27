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

 //��ʼ������
void SeqlistInit(Seqlist* pc);
//��ӡ����
void SeqlistPrint(Seqlist* pc);
//β��
void SeqlistPushBack(Seqlist* pc, SeqlistType x); 
//ͷ��
void SeqlistPushFront(Seqlist* pc, SeqlistType x);
//βɾ
void SeqlistPopBack(Seqlist* pc);
//ͷɾ
void SeqlistPopFront(Seqlist* pc);

void SeqlistInster(Seqlist* pc, int pos, SeqlistType x);

void SeqlistErase(Seqlist* pc, int pos);



